/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslati <yslati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:17:06 by yslati            #+#    #+#             */
/*   Updated: 2019/12/06 10:32:13 by yslati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct		s_var
{
	char			c;
	char			*s;
	char			*p;
	long long		d;
	unsigned int	u;
	char			*x;
	int				sp;
	int				zero;
	int				point;
	int				sp_position;
	int				valid;
	int				negative;
	int				len_str;
	int				i;
	int				neg_e;
	int				total;

	va_list			args;
}					t_var;

int					ft_printf(const char *fmt, ...);
char				print_hexa(long long d, char c);
char				*conv_hexa(unsigned long d, char c, int s);
char				*ft_adresse(unsigned long long p);
void				get_val(const char *fmt, t_var *var);
int					len_str(t_var *var, char c);
int					len_num(t_var *var);
int					len_num_u(t_var *var);
void				print_flag(int len, char c);
void				print_conv(const char *fmt, t_var *var);
int					check_conv(const char *fmt);
void				flag_etoil(t_var *var);
void				flag_point(char **fmt, t_var *var);
void				flag_helper(char **fmt, t_var *var);
char				*flags(char *fmt, t_var *var);
void				calc(const char *fmt, t_var *var);
void				print_before(const char *fmt, t_var *var);
void				print_after(t_var *var);
void				all_zero(t_var *var);
void				check_get(const char *fmt, t_var *var);
char				*manager(const char *fmt, t_var *var);

#endif
