/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 22:25:14 by jkimmina          #+#    #+#             */
/*   Updated: 2018/04/01 16:22:51 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_pow(int b, int e)
{
	int r;

	if (e == 0)
		return (1);
	r = b;
	while (--e)
		r *= b;
	return (r);
}