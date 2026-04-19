#include "bigint.hpp"

bigint::bigint() :	magnitude("0")
{}

bigint::~bigint()
{}

bigint::bigint(const bigint& that) :	magnitude(that.getMagnitude())
{}

bigint::bigint(const unsigned int n)
{
	std::stringstream	stream;

	stream << n;
	this->magnitude = stream.str();
}

bigint&	bigint::operator=(const bigint& that)
{
	if (this != &that)
		this->magnitude = that.getMagnitude();
	return (*this);
}

void	bigint::setMagnitude(const std::string& magnitude)
{
	this->magnitude = magnitude;
}

std::string	bigint::getMagnitude() const
{
	return (this->magnitude);
}

static size_t	max(const size_t a, const size_t b)
{
	if (a > b)
		return (a);
	return (b);
}

static	std::string	reverse(const std::string& original)
{
	std::string	reverse;
	char		current;
	size_t		i;

	i = original.length();
	while (i > 0)
	{
		current = original[i - 1];
		reverse.push_back(current);
		i --;
	}
	return (reverse);
}

static std::string	add(const std::string& left, const std::string& right)
{
	std::string	reverseLeft;
	std::string	reverseRight;
	size_t		maxLength;
	std::string	reverseResult;
	int			carry;
	size_t		i;
	int			leftDigit;
	int			rightDigit;
	int			addition;
	int			base;
	std::string	result;

	reverseLeft = reverse(left);
	reverseRight = reverse(right);
	maxLength = max(reverseLeft.length(), reverseRight.length());
	while (reverseLeft.length() < maxLength)
		reverseLeft.push_back('0');
	while (reverseRight.length() < maxLength)
		reverseRight.push_back('0');
	carry = 0;
	i = 0;
	base = 10;
	while (i < maxLength)
	{
		leftDigit = reverseLeft[i] - '0';
		rightDigit = reverseRight[i] - '0';
		addition = leftDigit + rightDigit + carry;
		reverseResult.push_back((addition % base) + '0');
		carry = addition / base;
		i ++;
	}
	if (carry > 0)
		reverseResult.push_back(carry + '0');
	result = reverse(reverseResult);
	i = 0;
	while (i + 1 < result.length() && result[i] == '0')
		i ++;
	return (result.substr(i));
}

bigint  bigint::operator+(const bigint& that) const
{
	std::string	magnitude;
	bigint		result;

	magnitude = add(this->getMagnitude(), that.getMagnitude());
	result.setMagnitude(magnitude);
	return (result);
}

bigint&	bigint::operator+=(const bigint& that)
{
	*this = *this + that;
	return (*this);
}

bigint&	bigint::operator++()
{
	*this += bigint(1);
	return (*this);
}

bigint	bigint::operator++(int)
{
	bigint	previous(*this);

	*this += bigint(1);
	return (previous);
}

bigint	bigint::operator<<(unsigned int n) const
{
	bigint	result(*this);

	if (n != 0 && this->magnitude != "0")
		result.magnitude.append(n, '0');
	return (result);
}

bigint	bigint::operator>>(unsigned int n) const
{
	bigint	result(*this);
	size_t	length;

	length = this->magnitude.length();
	if (n >= length)
		result.magnitude = "0";
	else if (n != 0)
		result.magnitude.erase(length - n, n);
	return (result);
}

bigint&	bigint::operator<<=(unsigned int n)
{
	*this = *this << n;
	return (*this);
}

bigint&	bigint::operator>>=(unsigned int n)
{
	*this = *this >> n;
	return (*this);
}

bigint	bigint::operator<<(const bigint& that) const
{
	std::stringstream	stream(that.getMagnitude());
	unsigned int		shift;

	stream >> shift;
	return (*this << shift);
}

bigint	bigint::operator>>(const bigint& that) const
{
	std::stringstream	stream(that.getMagnitude());
	unsigned int		shift;

	stream >> shift;
	return (*this >> shift);
}

bigint&	bigint::operator<<=(const bigint& that)
{
	*this = *this << that;
	return (*this);
}

bigint&	bigint::operator>>=(const bigint& that)
{
	*this = *this >> that;
	return (*this);
}

bool	bigint::operator==(const bigint& that) const
{
	return (this->magnitude == that.getMagnitude());
}

bool	bigint::operator!=(const bigint& that) const
{
	return (!(*this == that));
}

bool	bigint::operator<(const bigint& that) const
{
	const std::string&	left = this->magnitude;
	const std::string&	right = that.getMagnitude();

	if (left.length() != right.length())
		return (left.length() < right.length());
	return (left < right);
}

bool	bigint::operator>(const bigint& that) const
{
	return (!(*this < that) && *this != that);
}

bool	bigint::operator<=(const bigint& that) const
{
	return ((*this < that) || *this == that);
}

bool	bigint::operator>=(const bigint& that) const
{
	return ((*this > that) || *this == that);
}

std::ostream&	operator<<(std::ostream& out, const bigint& value)
{
	out << value.getMagnitude();
	return (out);
}
