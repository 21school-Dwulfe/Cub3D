/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:42:20 by dwulfe            #+#    #+#             */
/*   Updated: 2022/03/02 11:42:25 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*res;

	if (!lst)
		return (NULL);
	res = ft_lstnew((*f)(lst->content));
	if (!res)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		node = ft_lstnew((*f)(lst->content));
		if (!node)
		{
			ft_lstclear(&res, &(*del));
			return (NULL);
		}
		ft_lstadd_back(&res, node);
	}
	return (res);
}
