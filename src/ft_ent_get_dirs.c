/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ent_get_dirs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 15:46:27 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/16 18:18:47 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list	*ft_ent_get_dirs(t_list **ent)
{
	t_lsdata		*data;
	struct dirent	*dirent;
	t_list			*dir;
	t_list			*lst;
	t_list			*tmp;

	dir = NULL;
	lst = *ent;
	while (lst)
	{
		tmp = lst;
		data = lst->content;
		dirent = data->dirent;
		lst = lst->next;
		if (dirent->d_type == DT_DIR
				&& ft_strcmp(ft_path_notdir(data->path), ".")
				&& ft_strcmp(ft_path_notdir(data->path), ".."))
		{
			ft_lsteadd(&dir, ft_lst_removeif(ent, tmp->content, &ft_addrcmp));
		}
	}
	return (dir);
}
