#include "libft.h"

void	ft_lstrev(t_list **lst)
{
	t_list *prec;
	t_list *tmp;
	t_list *tmp_n;

	prec = NULL;
	tmp = *lst;
	while (tmp)
	{
		tmp_n = tmp->next;
		tmp->next = prec;
		prec = tmp;
		tmp = tmp_n;
	}
	*lst = prec;
}
