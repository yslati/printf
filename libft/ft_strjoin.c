/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslati <yslati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:42:08 by yslati            #+#    #+#             */
/*   Updated: 2019/11/29 11:10:03 by yslati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	char	*q;

	if (!s1 || !s2)
		return (NULL);
	if (!(p = (char*)malloc((ft_strlen(s1) + ft_strlen(s2) + 1)
		* sizeof(char))))
		return (NULL);
	q = p;
	while (*s1 != '\0')
		*p++ = *s1++;
	while (*s2 != '\0')
		*p++ = *s2++;
	*p = '\0';
	return (q);
}
