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

