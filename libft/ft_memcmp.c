/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslati <yslati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 10:44:12 by yslati            #+#    #+#             */
/*   Updated: 2019/10/27 12:28:09 by yslati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*sr1;
	unsigned char	*sr2;

	i = -1;
	sr1 = (unsigned char *)s1;
	sr2 = (unsigned char *)s2;
	while (++i < n)
	{
		if (sr1[i] != sr2[i])
			return (sr1[i] - sr2[i]);
	}
	return (0);
}
