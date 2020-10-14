/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslati <yslati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:41:33 by yslati            #+#    #+#             */
/*   Updated: 2019/11/06 16:47:06 by yslati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ndigits(int n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (n < 0)
		j = n * -1;
	else
		j = n;
	while (j > 0)
	{
		i++;
		j /= 10;
	}
	return (i + 1);
}

static int		exp(unsigned int i)
{
	unsigned int j;

	j = 1;
	while (i-- > 1)
		j *= 10;
	return (j);
}

char			*ft_itoa(int n)
{
	char			*p;
	unsigned int	i;
	unsigned int	j;
	char			*q;

	p = (char*)malloc((ndigits(n) + 1) * sizeof(char));
	if (!p)
		return (p);
	q = p;
	if (n < 0)
	{
		j = n * -1;
		*p++ = '-';
	}
	else
		j = n;
	i = exp(ndigits(n) - 1);
	while (i > 0)
	{
		*p++ = j / i + 48;
		j %= i;
		i /= 10;
	}
	*p = '\0';
	return (q);
}
