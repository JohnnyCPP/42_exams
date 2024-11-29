/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:59:24 by jonnavar          #+#    #+#             */
/*   Updated: 2024/11/01 16:01:42 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	int	ft_is_multiplier(unsigned int a, unsigned int b, unsigned int num)
{
	if (num % a == 0 && num % b == 0)
		return (1);
	return (0);
}

unsigned	int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	aux;

	if (!a || !b)
		return (0);
	if (a > b)
		aux = a;
	else
		aux = b;
	while (1)
	{
		if (ft_is_multiplier(a, b, aux))
			return (aux);
		aux ++;
	}
}
