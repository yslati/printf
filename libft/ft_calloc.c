/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslati <yslati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 11:39:51 by yslati            #+#    #+#             */
/*   Updated: 2019/11/05 14:35:51 by yslati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_calloc(size_t count, size_t size)
{
	size_t	total;
	void	*p;

	total = count * size;
	p = malloc(total);
	if (!p)
		return (0);
	return (ft_memset(p, 0, total));
}
