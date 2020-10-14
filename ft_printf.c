/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslati <yslati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:16:34 by yslati            #+#    #+#             */
/*   Updated: 2019/12/14 18:58:23 by yslati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			all_zero(t_var *var)
{
	var->c = 0;
	var->s = NULL;
	var->p = NULL;
	var->d = 0;
	var->u = 0;
	var->x = NULL;
	var->sp = 0;
	var->zero = 0;
	var->point = 0;
	var->sp_position = 0;
	var->valid = 0;
	var->negative = 0;
	var->len_str = 0;
	var->i = 0;
}

void			check_get(const char *fmt, t_var *var)
{
	get_val(fmt, var);
	if (check_conv(fmt) == 1)
		var->len_str += len_str(var, *fmt);
	else if (check_conv(fmt) == 2)
		var->len_str += len_num(var);
	else if (check_conv(fmt) == 3)
		var->len_str += len_num_u(var);
	if (var->d == 0 && var->u == 0 && (check_conv(fmt) == 2 ||
	check_conv(fmt) == 3) && var->point != 1)
	{
		var->len_str = 1;
		var->total--;
	}
}

void			print_and_return(const char *fmt, t_var *var)
{
	print_before(fmt, var);
	print_conv(fmt, var);
	print_after(var);
	if (var->sp < 0 || (var->point == 0 && var->sp_position == 0))
		var->sp = 0;
	if (var->zero < 0)
		var->zero = 0;
	var->total += var->len_str + var->zero + var->sp;
}

char			*manager(const char *fmt, t_var *var)
{
	all_zero(var);
	if (check_conv(fmt))
	{
		check_get(fmt, var);
		print_before(fmt, var);
		print_conv(fmt, var);
		var->total += var->len_str;
	}
	else
	{
		while (!check_conv(fmt))
		{
			fmt = flags((char *)fmt, var);
			while (var->i > 0)
			{
				var->i /= 10;
				fmt++;
			}
			check_get(fmt, var);
			calc(fmt, var);
		}
		print_and_return(fmt, var);
	}
	return ((char *)fmt);
}

int				ft_printf(const char *fmt, ...)
{
	t_var		var;

	if (!fmt)
		return (0);
	var.total = 0;
	va_start(var.args, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			fmt = manager(fmt, &var);
		}
		else
		{
			ft_putchar(*fmt);
			var.total++;
		}
		fmt++;
	}
	return (var.total);
}
