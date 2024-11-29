/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_list_remove_if.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:59:24 by jonnavar          #+#    #+#             */
/*   Updated: 2024/11/01 16:01:42 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	malloc(), free()
#include <stdlib.h>
//	printf()
#include <stdio.h>
//	NULL
#include <stddef.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

static	int	ft_is_equal_to(void *a, void *b)
{
	if (*((int *) a) == *((int *) b))
		return (0);
	return (1);
}

static	void	ft_print_list(t_list **begin_list)
{
	t_list	*head;

	head = *begin_list;
	while (head)
	{
		printf("%i ", *((int *) head->data));
		head = head->next;
	}
	printf("\n");
}

static	void	push_to_list(t_list **head, int number)
{
	t_list	*new_node;
	int		*new_number;

	new_node = (t_list *) malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_number = (int *) malloc(sizeof(int));
	*new_number = number;
	new_node->data = (void *) new_number;
	new_node->next = *head;
	*head = new_node;
}

static	t_list	*initialize_list(void)
{
	t_list	*head;
	int		*number;
	int		i;

	head = NULL;
	i = 10;
	while (i)
	{
		push_to_list(&head, i);
		i --;
	}
	return (head);
}

static	void	free_list(t_list **head)
{
	t_list	*current;
	t_list	*next;

	current = *head;
	while (current)
	{
		next = current->next;
		free(current->data);
		free(current);
		current = next;
	}
	*head = NULL;
}

/*
int	main(void)
{
	t_list	*head;
	int		target;

	head = initialize_list();
	target = 5;
	printf("Starting list: ");
	ft_print_list(&head);
	ft_list_remove_if(&head, (void *) &target, ft_is_equal_to);
	printf("Modified list: ");
	ft_print_list(&head);
	free_list(&head);
	return (0);
}
*/
