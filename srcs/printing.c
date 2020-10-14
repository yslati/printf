/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslati <yslati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 16:24:45 by yslati            #+#    #+#             */
/*   Updated: 2019/12/09 11:02:15 by yslati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void			print_flag(int len, char c)
{
	while (len > 0)
	{
		ft_putchar(c);
		len--;
	}
}

void			print_conv_helper(const char *fmt, t_var *var)
{
	if (*fmt == 'p')
	{
		ft_putstr("0x");
		ft_putstr(var->p);
	}
	else if (*fmt == 'u')
	{
		(var->u == 0 && ((var->sp_position != 0 && var->point == 1) ||
		(var->point == 1))) ? var->total-- : ft_putnbr_u(var->u);
	}
	else if (*fmt == 'x' || *fmt == 'X')
	{
		if (*var->x == '0' && var->point == 1)
		{
			if ((var->point != 1 && var->sp_position == -1) ||
			(var->point == 1 && var->sp_position == 0))
				var->total--;
			var->x = "";
			if (var->sp > 0)
				ft_putchar(' ');
		}
		ft_putstr(var->x);
	}
}

void			print_conv(const char *fmt, t_var *var)
{
	int i;

	i = 0;
	if (*fmt == 'd' || *fmt == 'i')
	{
		if (var->d == 0 && ((var->sp_position != 0 &&
		var->point == 1) || (var->point == 1)))
			var->total--;
		else
			ft_putnbr_fd(var->d, 1);
	}
	else if (*fmt == 's')
	{
		i = var->len_str;
		while (i-- > 0)
			ft_putchar(*var->s++);
	}
	if (*fmt == 'c')
		ft_putchar(var->c);
	else if (*fmt == '%')
		ft_putchar('%');
	else
		print_conv_helper(fmt, var);
	fmt++;
}

void			print_before(const char *fmt, t_var *var)
{
	if (var->sp_position == -1)
		print_flag(var->sp, ' ');
	if (var->negative == 1)
		ft_putchar('-');
	if (*fmt != 's' && *fmt != 'c')
		print_flag(var->zero, '0');
}

void			print_after(t_var *var)
{
	if (var->sp_position == 1)
		print_flag(var->sp, ' ');
}
