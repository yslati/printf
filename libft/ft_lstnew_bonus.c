/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslati <yslati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 12:46:03 by yslati            #+#    #+#             */
/*   Updated: 2019/10/29 15:01:10 by yslati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list				*ft_lstnew(void *content)
{
	t_list			*list;

	list = (t_list *)malloc(sizeof(list));
	if (list)
	{
		list->content = content;
		list->next = NULL;
	}
	return (list);
}
