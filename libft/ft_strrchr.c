/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslati <yslati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:39:22 by yslati            #+#    #+#             */
/*   Updated: 2019/10/27 12:31:08 by yslati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	size_t			i;
	char			*p;
	unsigned char	ch;

	ch = c;
	i = 0;
	p = (char *)s;
	while (p[i])
		i++;
	i++;
	while (i-- > 0)
	{
		if (p[i] == ch)
			return (p + i);
	}
	return (0);
}
