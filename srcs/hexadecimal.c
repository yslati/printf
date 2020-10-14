/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslati <yslati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 16:17:40 by yslati            #+#    #+#             */
/*   Updated: 2019/12/07 20:22:13 by yslati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

char				print_hexa(long long d, char c)
{
	if (d || d == 0)
	{
		if (d >= 0 && d <= 9)
			return (d + '0');
		else
		{
			if (c == 'X')
				return (55 + d);
			else if (c == 'x')
				return (87 + d);
		}
	}
	return (0);
}

char				*conv_hexa(unsigned long d, char c, int s)
{
	static char		str[18];
	static int		i;

	i = 0;
	(!s) ? ft_bzero(str, 18) : 0;
	if (d / 16)
		conv_hexa(d / 16, c, 1);
	str[i++] = print_hexa(d % 16, c);
	return (str);
}

char				*ft_adresse(unsigned long long p)
{
	char		*str;
	char		*str2;
	char		*ptr;
	int			i;

	i = 0;
	if (p)
	{
		str2 = conv_hexa(p, 'x', 0);
		if (!(str = malloc(sizeof(char) * (ft_strlen(str2) + 3))))
			return (NULL);
		ptr = str;
		while (*str2)
		{
			str[i++] = *str2;
			str2++;
		}
		str[i] = '\0';
		if (str)
			free(str);
		return (ptr);
	}
	return (NULL);
}
