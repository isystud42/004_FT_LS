/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ent_has_dir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 15:42:54 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/23 18:24:47 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_ent_has_dir(t_list *ent)
{
	t_lsdata		*data;
	struct dirent	*dirent;

	while (ent)
	{
		data = ent->content;
		dirent = data->dirent;
		if (dirent->d_type == DT_DIR
				&& ft_strcmp(ft_path_notdir(data->path), ".")
				&& ft_strcmp(ft_path_notdir(data->path), ".."))
		{
			return (1);
		}
		ent = ent->next;
	}
	return (0);
}
