/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslati <yslati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:43:20 by yslati            #+#    #+#             */
/*   Updated: 2019/11/06 16:43:24 by yslati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*p;
	char			*q;

	if (!s)
		return (NULL);
	if (start > (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	if (!(p = (char*)malloc((len + 1) * sizeof(char))))
		return (NULL);
	q = p;
	s = s + start;
	while (len-- > 0)
		*p++ = *s++;
	*p++ = '\0';
	return (q);
}
