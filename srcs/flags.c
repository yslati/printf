/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslati <yslati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 16:26:03 by yslati            #+#    #+#             */
/*   Updated: 2019/12/14 19:10:21 by yslati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void			flag_etoil(t_var *var)
{
	if (var->valid == 1 || var->point == 1)
		var->zero = va_arg(var->args, int);
	else
		var->sp = va_arg(var->args, int);
	if (var->sp > 0 && var->sp_position != 1)
		var->sp_position = -1;
	else
	{
		var->sp_position = 1;
		if (var->sp < 0)
			var->sp = -var->sp;
	}
}

void			flag_point_etoil(t_var *var)
{
	if (var->zero < 0 && var->zero != var->i)
	{
		if (var->sp_position == -1 || var->sp_position == 1)
			var->zero = 0;
		var->point = 0;
	}
	else
		var->point = 1;
}

void			flag_point(char **fmt, t_var *var)
{
	++*fmt;
	if (**fmt != '*')
	{
		if (var->valid == 1)
		{
			var->sp = var->zero;
			var->sp_position = -1;
		}
		if (**fmt == '0')
			++*fmt;
		var->zero = ft_atoi(*fmt);
		var->i = var->zero;
	}
	else
	{
		var->zero = va_arg(var->args, int);
		if (var->sp_position == -1 && var->zero < 0)
		{
			if (var->valid == 1)
				var->sp = -var->zero;
		}
		++*fmt;
	}
	flag_point_etoil(var);
}

void			flag_helper(char **fmt, t_var *var)
{
	if (ft_isdigit(**fmt))
	{
		var->sp = ft_atoi(*fmt);
		var->i = var->sp;
		if (var->sp_position != 1)
			var->sp_position = -1;
	}
	else if (**fmt == '-')
	{
		while (**fmt == '-' || **fmt == '0')
			++*fmt;
		var->sp = ft_atoi(*fmt);
		var->i += var->sp;
		if (var->sp_position != -1)
			var->sp_position = 1;
	}
	else if (**fmt == '*')
	{
		flag_etoil(var);
		++*fmt;
	}
}

char			*flags(char *fmt, t_var *var)
{
	if (*fmt == '0')
	{
		fmt++;
		if (*fmt != '*')
			var->zero = ft_atoi(fmt);
		var->i = var->zero;
		if (*fmt == '*')
		{
			var->zero = va_arg(var->args, int);
			fmt++;
		}
		if (var->zero < 0)
		{
			var->sp = -var->zero;
			var->zero = 0;
			var->sp_position = 1;
		}
		else
			var->valid = 1;
	}
	else if (*fmt == '.')
		flag_point(&fmt, var);
	else if (ft_isdigit(*fmt) || *fmt == '*' || *fmt == '-')
		flag_helper(&fmt, var);
	return ((char *)fmt);
}
