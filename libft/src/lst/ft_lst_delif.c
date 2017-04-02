#include "libft.h"

void	ft_lst_delif(t_list **alst,	void *data_ref,	int (*cmp)(),
		void (*del_fonction)(void *, size_t))
{
	t_list	*tmp;
	t_list	**indirect;

	indirect = alst;
	while (*indirect)
	{
		if ((*cmp)((*indirect)->content, data_ref) == 0)
		{
			tmp = (*indirect);
			(*indirect) = (*indirect)->next;
			ft_lstdelone(&tmp, del_fonction);
		}
		else
			indirect = &(*indirect)->next;
	}
}
