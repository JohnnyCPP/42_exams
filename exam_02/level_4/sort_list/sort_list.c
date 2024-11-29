/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:59:24 by jonnavar          #+#    #+#             */
/*   Updated: 2024/11/01 16:01:42 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	NULL
#include <stddef.h>
#include "sort_list.h"

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*start;
	int		aux;

	start = lst;
	while (lst != NULL && lst->next != NULL)
	{
		if (!cmp(lst->data, lst->next->data))
		{
			aux = lst->data;
			lst->data = lst->next->data;
			lst->next->data = aux;
			lst = start;
		}
		else
			lst = lst->next;
	}
	return (start);
}
