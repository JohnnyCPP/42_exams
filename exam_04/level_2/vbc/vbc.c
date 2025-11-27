#include "vbc.h"

/**
 * factor: the most basic building blocks
 *   - single numbers: [0-9]
 *   - parenthesized expressions
 *   - examples:
 *     - 5
 *     - (2+3)
 *     - ((1+2)*3)
 *
 * term: multiplication or division operations
 *   - built from factors: factor * factor * factor
 *   - examples:
 *     - 5
 *     - 5*3
 *     - (2+3)*4
 *
 * expression: addition or subtraction operations
 *   - built from terms: term + term + term
 *   - examples:
 *     - 5
 *     - 5+3
 *     - 2*3+4*5
 *       - <term> + <term> where each term has multiplication
 *
 * 
 * definition of the expression grammar
 *   - defined with BNF (Backus-Naur Form)
 *   - metasymbols:
 *     - "::=" means "is replaced by"
 *     - "|" means "OR" (optionality)
 *     - "*" means "zero or more repetitions"
 *     - "()" group things together
 *       - ( and ) are metasymbols to group symbols
 *       - '(' and ')' are terminal symbols
 *   - symbols:
 *     - a symbol between quotes is "terminal"
 *       - fixed, literal elements
 *     - a symbol between angle brackets is "non-terminal"
 *       - represents a variable that can be replaced
 *
 *   <expression>  ::= <term> ('+' <term>)*
 *   <term>        ::= <factor> ('*' <factor>)*
 *   <factor>      ::= <NUMBER> | '(' <expression> ')'
 *
 *
 *   the nesting order establishes precedence:
 *
 *     expression  (lowest precedence - addition)
 *         ↓
 *        term     (medium precedence - multiplication)
 *         ↓
 *       factor    (highest precedence - numbers/parentheses)
 *
 *   
 *   the factors happen "deeper" in the call stack, 
 *   so they get evaluated before terms, which are 
 *   evaluated before expressions
 */

/**
 * the names "expression", "term", and "factor" 
 * come from traditional mathematical terminology
 *
 * in algebra, these terms have specific meanings:
 *
 *   - "factor": something being multiplied
 *     - in "2*3" both numbers are factors
 *
 *   - "term": a part of a sum or difference
 *     - in "2+3" both numbers are terms
 *     - in "2+3*4" the terms are "2" and "3*4"
 *
 *   - "expression": any combination of terms and operations
 *     - "2+3" is an expression
 *     - "2*3+4" is an expression
 */

#define TRUE 1
#define FALSE 0

#define EXP_ARGS 2
#define RET_FAILURE 1
#define RET_SUCCESS 0

#define MSG_UNEXP_TOKEN "Unexpected token '%c'\n"
#define MSG_UNEXP_EOF "Unexpected end of input\n"

// forward declaration because of mutual recursion
static	int	vbc_parse_expr(t_parser *parser);

static	char	vbc_get_curr(t_parser *parser)
{
	char	current;

	current = parser->input[parser->pos];
	return (current);
}

static	void	vbc_advance(t_parser *parser)
{
	if (vbc_get_curr(parser) != '\0')
		parser->pos ++;
}

static	void	vbc_print_unexp(t_parser *parser, char c)
{
	if (c == '\0')
		printf(MSG_UNEXP_EOF);
	else
		printf(MSG_UNEXP_TOKEN, c);
	parser->error = TRUE;
}

static	int	vbc_parse_num(t_parser *parser)
{
	char	current;
	int		num;

	current = vbc_get_curr(parser);
	if (isdigit((int) current))
	{
		num = current - '0';
		vbc_advance(parser);
		return (num);
	}
	vbc_print_unexp(parser, current);
	return (0);
}

// <factor>      ::= <NUMBER> | '(' <expression> ')'
static	int	vbc_parse_fact(t_parser *parser)
{
	char	current;
	int		expression;

	if (parser->error)
		return (0);
	current = vbc_get_curr(parser);
	if (current == '(')
	{
		vbc_advance(parser);
		expression = vbc_parse_expr(parser);
		if (parser->error)
			return (0);
		current = vbc_get_curr(parser);
		if (current != ')')
		{
			vbc_print_unexp(parser, current);
			return (0);
		}
		vbc_advance(parser);
		return (expression);
	}
	else if (isdigit((int) current))
		return (vbc_parse_num(parser));
	vbc_print_unexp(parser, current);
	return (0);
}

// <term>        ::= <factor> ('*' <factor>)*
static	int	vbc_parse_term(t_parser *parser)
{
	char	current;
	int		factor;

	if (parser->error)
		return (0);
	factor = vbc_parse_fact(parser);
	current = vbc_get_curr(parser);
	while (!parser->error && current == '*')
	{
		vbc_advance(parser);
		factor *= vbc_parse_fact(parser);
		current = vbc_get_curr(parser);
	}
	return (factor);
}

// <expression>  ::= <term> ('+' <term>)*
static	int	vbc_parse_expr(t_parser *parser)
{
	char	current;
	int		term;

	if (parser->error)
		return (0);
	term = vbc_parse_term(parser);
	current = vbc_get_curr(parser);
	while (!parser->error && current == '+')
	{
		vbc_advance(parser);
		term += vbc_parse_term(parser);
		current = vbc_get_curr(parser);
	}
	return (term);
}

int	main(int argc, char **argv)
{
	t_parser	parser;
	int			result;

	if (argc != EXP_ARGS)
		return (RET_FAILURE);
	parser.input = argv[1];
	parser.pos = 0;
	parser.error = FALSE;
	result = vbc_parse_expr(&parser);
	if (!parser.error && vbc_get_curr(&parser) == '\0')
	{
		printf("%d\n", result);
		return (RET_SUCCESS);
	}
	else if (!parser.error)
		vbc_print_unexp(&parser, vbc_get_curr(&parser));
	return (RET_FAILURE);
}
