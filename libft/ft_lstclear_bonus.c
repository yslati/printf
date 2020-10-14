/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslati <yslati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 12:42:45 by yslati            #+#    #+#             */
/*   Updated: 2019/10/29 15:00:53 by yslati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *tmp;

	while ((*lst) != NULL)
	{
		tmp = *lst;
		(*del)(tmp->content);
		(*lst) = (*lst)->next;
	}
	free(tmp);
}
