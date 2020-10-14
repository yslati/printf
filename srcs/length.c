/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslati <yslati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 16:22:20 by yslati            #+#    #+#             */
/*   Updated: 2019/12/16 13:47:20 by yslati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int				len_str(t_var *var, char c)
{
	int n;

	var->len_str = 0;
	n = 0;
	if (c == 'p')
		n = ft_strlen((char *)var->p) + 2;
	else if (c == 'c' || c == '%')
		n = 1;
	else if (c == 's')
		n = ft_strlen(var->s);
	else if (c == 'x' || c == 'X')
		n = ft_strlen(var->x);
	return (n);
}

int				len_num(t_var *var)
{
	long long	d;
	long long	l;
	int			n;

	n = 0;
	l = var->d;
	var->negative = 0;
	if (l == 0)
		var->total++;
	if (l < 0)
	{
		l = -l;
		var->sp -= 1;
		var->negative = 1;
		var->total++;
	}
	d = l;
	while (d > 0)
	{
		d /= 10;
		n++;
	}
	var->d = l;
	return (n);
}

int				len_num_u(t_var *var)
{
	unsigned int		u;
	int					n;

	u = var->u;
	n = 0;
	if (var->u == 0)
		var->total++;
	if (u > 0)
	{
		while (u > 0)
		{
			u /= 10;
			n++;
		}
	}
	return (n);
}
