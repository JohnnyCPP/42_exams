/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:59:24 by jonnavar          #+#    #+#             */
/*   Updated: 2024/11/01 16:01:42 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	free()
#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*current;

	if (!begin_list || !*begin_list)
		return ;
	current = *begin_list;
	if (!cmp(current->data, data_ref))
	{
		*begin_list = current->next;
		free(current);
		ft_list_remove_if(begin_list, data_ref, cmp);
	}
	else
	{
		current = *begin_list;
		ft_list_remove_if(&current->next, data_ref, cmp);
	}
}
