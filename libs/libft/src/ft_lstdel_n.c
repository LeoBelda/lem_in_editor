#include "libft.h"

void	ft_lstdel_n(t_list **lst, int n, void (*del)(void*, size_t))
{
	t_list	*it;
	t_list	*prec;
	int		i;

	it = *lst;
	i = 0;
	while (i++ < n)
	{
		prec = it;
		it = it->next;
	}
	if (it == *lst)
	{
		it = it->next;
		ft_lstdelone(lst, del);
		*lst = it;
	}
	else
	{
		prec->next = it->next;
		ft_lstdelone(&it, del);
	}
}
