/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslati <yslati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:43:06 by yslati            #+#    #+#             */
/*   Updated: 2019/11/06 16:43:09 by yslati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check(char c, char const *set)
{
	int i;

	i = 0;
	while (*set != '\0')
		if (*set++ == c)
			return (0);
	return (1);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char		*p;
	char		*q;
	int			j;
	int			i;

	if (!s1)
		return (NULL);
	j = ft_strlen(s1) - 1;
	while (!check(s1[j], set) && j > 0)
		j--;
	if (!j)
		return (ft_strdup(""));
	i = 0;
	while (!check(s1[i], set))
		i++;
	if (!(p = (char*)malloc((j - i + 2) * sizeof(char))))
		return (NULL);
	q = p;
	while (i <= j)
		*p++ = s1[i++];
	*p = '\0';
	return (q);
}
