/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslati <yslati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 12:07:03 by yslati            #+#    #+#             */
/*   Updated: 2019/11/06 12:00:23 by yslati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	char			*s;
	unsigned int	s_len;
	unsigned int	d_len;
	unsigned int	len;
	unsigned int	i;

	s = (char *)src;
	s_len = ft_strlen(src);
	if (!dst && size == 0)
		return (s_len);
	d_len = ft_strlen(dst);
	len = d_len;
	i = 0;
	if (size <= d_len)
		return (size + s_len);
	else if (size > d_len)
	{
		while (s[i] && d_len < size - 1)
			dst[d_len++] = s[i++];
		dst[d_len] = '\0';
		return (s_len + len);
	}
	return (0);
}
