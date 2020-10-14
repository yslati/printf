/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslati <yslati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:56:04 by yslati            #+#    #+#             */
/*   Updated: 2019/10/28 13:47:25 by yslati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*d;
	unsigned char		*s;

	i = -1;
	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	while (++i < n)
	{
		d[i] = s[i];
		if (d[i] == (unsigned char)c)
			return ((void*)(d + i + 1));
	}
	return (0);
}
