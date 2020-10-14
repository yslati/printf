/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslati <yslati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 18:23:36 by yslati            #+#    #+#             */
/*   Updated: 2019/12/05 20:46:48 by yslati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void			get_val(const char *fmt, t_var *var)
{
	if (*fmt == 'd' || *fmt == 'i')
		var->d = va_arg(var->args, int);
	if (*fmt == 'c')
		var->c = va_arg(var->args, int);
	else if (*fmt == 's')
	{
		var->s = va_arg(var->args, char *);
		if (var->s == NULL)
			var->s = "(null)";
	}
	else if (*fmt == 'u')
		var->u = va_arg(var->args, unsigned int);
	else if (*fmt == 'x' || *fmt == 'X')
		var->x = conv_hexa((unsigned int)va_arg(var->args,
		unsigned long), *fmt, 0);
	else if (*fmt == '%')
		var->c = '%';
	else if (*fmt == 'p')
	{
		var->p = ft_adresse((unsigned long)va_arg(var->args, void*));
		if (var->p == NULL)
			var->p = "0";
	}
}

int				check_conv(const char *fmt)
{
	if (*fmt == 'x' || *fmt == 'X' || *fmt == 'c' ||
	*fmt == 's' || *fmt == 'p' || *fmt == '%')
		return (1);
	else if (*fmt == 'd' || *fmt == 'i')
		return (2);
	else if (*fmt == 'u')
		return (3);
	return (0);
}

void			calc(const char *fmt, t_var *var)
{
	if (*fmt == '%' && var->point == 1)
		var->zero = 0;
	if (var->sp < 0)
		var->sp = -var->sp;
	if (var->valid == 1 || var->point == 1)
	{
		if (var->negative == 1 && var->valid == 1 && var->point != 1)
			var->zero -= 1;
		if (var->zero > var->len_str && *fmt != 's')
			var->zero -= var->len_str;
		else if (*fmt != 's')
			var->zero = 0;
	}
	if (*fmt == 's')
	{
		var->zero = var->zero < 0 ? -var->zero : var->zero;
		if (var->point == 1 && var->zero < var->len_str)
			var->len_str = var->zero;
		var->zero = 0;
	}
	if (var->sp < var->len_str)
		var->sp = 0;
	else
		var->sp = var->sp - var->len_str - var->zero;
}
