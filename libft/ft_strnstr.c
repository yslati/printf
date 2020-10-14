/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslati <yslati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:34:15 by yslati            #+#    #+#             */
/*   Updated: 2019/10/29 18:03:38 by yslati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char		*str1;
	char		*str2;
	size_t		i;
	size_t		j;

	i = 0;
	str1 = (char *)haystack;
	str2 = (char *)needle;
	if (str2[0] == '\0')
		return (str1);
	while (i < len && str1[i] != '\0')
	{
		if (str1[i] == str2[0])
		{
			j = 0;
			while (str1[i + j] == str2[j] && (i + j) < len)
			{
				if (str2[j + 1] == '\0')
					return (str1 + i);
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
