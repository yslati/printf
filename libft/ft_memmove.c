/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslati <yslati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 17:50:19 by yslati            #+#    #+#             */
/*   Updated: 2019/11/05 13:16:22 by yslati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*s;
	char		*d;

	s = (const char *)src;
	d = (char *)dst;
	if (!s && !d)
		return (0);
	if (d <= s)
		return (ft_memcpy(d, s, len));
	while (len)
	{
		d[len - 1] = s[len - 1];
		len--;
	}
	return (d);
}
