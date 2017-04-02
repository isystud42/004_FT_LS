/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:49:05 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/23 18:46:16 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_cmp_mtime(t_lsdata *dat1, t_lsdata *dat2)
{
	if (dat2->stat.st_mtime - dat1->stat.st_mtime)
		return (dat2->stat.st_mtime - dat1->stat.st_mtime);
	else
		return (ft_strcmp(dat1->path, dat2->path));
}

int		ft_cmp_ctime(t_lsdata *dat1, t_lsdata *dat2)
{
	if (dat2->stat.st_ctime - dat1->stat.st_ctime)
		return (dat2->stat.st_ctime - dat1->stat.st_ctime);
	else
		return (ft_strcmp(dat1->path, dat2->path));
}

int		ft_cmp_atime(t_lsdata *dat1, t_lsdata *dat2)
{
	if (dat2->stat.st_atime - dat1->stat.st_atime)
		return (dat2->stat.st_atime - dat1->stat.st_atime);
	else
		return (ft_strcmp(dat1->path, dat2->path));
}

int		ft_cmp_btime(t_lsdata *dat1, t_lsdata *dat2)
{
	if (dat2->stat.st_birthtime - dat1->stat.st_birthtime)
		return (dat2->stat.st_birthtime - dat1->stat.st_birthtime);
	else
		return (ft_strcmp(dat1->path, dat2->path));
}
