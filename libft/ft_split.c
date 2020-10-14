/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslati <yslati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:41:49 by yslati            #+#    #+#             */
/*   Updated: 2019/11/06 16:41:51 by yslati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char		*help(char *p, const char *s, int i)
{
	while (i-- > 0)
		*p++ = *s++;
	*p = '\0';
	return (s);
}

static int				build(char const *s, char c, char **q)
{
	int			i;
	char		*p;
	int			n;

	n = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			n++;
			i = 0;
			while (s[i] != c && s[i] != '\0')
				i++;
			p = (char*)malloc((i + 1) * sizeof(char));
			if (!p)
				return (-n);
			*q++ = p;
			s = help(p, s, i);
		}
		if (*s != '\0')
			s++;
	}
	*q = 0;
	return (n);
}

static void				clearall(char **q, char **q1, int i)
{
	int j;

	j = 0;
	while (j++ < i)
	{
		free(*q);
		(*q)++;
	}
	free(*q);
	free(q);
	free(q1);
}

char					**ft_split(char const *s, char c)
{
	char		**q;
	int			i;
	char		**q1;

	if (!s)
		return (NULL);
	q = (char**)malloc((ft_strlen(s) + 1) * sizeof(char*));
	if (!q)
		return (q);
	i = build(s, c, q);
	q1 = (char**)malloc((i + 1) * sizeof(char*));
	if (i < 0 || !q1)
	{
		i *= -1;
		clearall(q, q1, i);
		return (NULL);
	}
	ft_memmove(q1, q, ((i + 1) * sizeof(char*)));
	free(q);
	return (q1);
}
