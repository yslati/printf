/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslati <yslati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 12:45:00 by yslati            #+#    #+#             */
/*   Updated: 2019/10/29 15:15:17 by yslati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *tmp;
	t_list *new;

	new = NULL;
	if (lst)
	{
		if (!(new = ft_lstnew((*f)(lst->content))))
			return (NULL);
		tmp = new;
		lst = lst->next;
		while (lst != NULL)
		{
			if (!(tmp->next = ft_lstnew((*f)(lst->content))))
			{
				ft_lstclear(&new, del);
				return (NULL);
			}
			tmp = tmp->next;
			lst = lst->next;
		}
	}
	return (new);
}
