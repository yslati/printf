/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslati <yslati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:55:18 by yslati            #+#    #+#             */
/*   Updated: 2019/11/05 14:41:39 by yslati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		checker(int r, int n)
{
	if (r > 0 && n < 0)
		return (0);
	if (r < 0 && n > 0)
		return (-1);
	return (r);
}

int				ft_atoi(const char *str)
{
	size_t		i;
	int			r;
	int			n;

	n = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
	|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		n = -1;
		i++;
	}
	r = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + str[i] - '0';
		i++;
	}
	r = r * n;
	return (checker(r, n));
}
