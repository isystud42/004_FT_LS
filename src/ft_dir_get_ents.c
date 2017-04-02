/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_dirs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:58:49 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/23 16:20:39 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list	*ft_dir_get_ents(t_lsdata *topdir, int *opts)
{
	t_list			*ent;
	struct dirent	*dirent;
	t_lsdata		data;
	DIR				*stream;
	char			*prepath;

	ent = NULL;
	if (!(stream = opendir(topdir->path)))
	{
		*opts |= OPTS_ERR_A;
		return (NULL);
	}
	prepath = ft_strjoin(topdir->path, "/");
	while ((dirent = readdir(stream)))
	{
		data.path = ft_strjoin(prepath, dirent->d_name);
		lstat(data.path, &data.stat);
		data.dirent = ft_memalloc(sizeof(*dirent) + 1);
		ft_memcpy(data.dirent, dirent, sizeof(*dirent));
		ft_lstadd(&ent, ft_lstnew(&data, sizeof(data)));
	}
	ft_strdel(&prepath);
	closedir(stream);
	return (ent);
}
