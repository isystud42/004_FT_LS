/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_ls_long2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:01:01 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/27 13:08:09 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_long_rights(mode_t m)
{
	ft_putchar(m & S_IRUSR ? 'r' : '-');
	ft_putchar(m & S_IWUSR ? 'w' : '-');
	if (m & S_ISUID)
		ft_putchar(m & S_IXUSR ? 's' : 'S');
	else
		ft_putchar(m & S_IXUSR ? 'x' : '-');
	ft_putchar(m & S_IRGRP ? 'r' : '-');
	ft_putchar(m & S_IWGRP ? 'w' : '-');
	if (m & S_ISGID)
		ft_putchar(m & S_IXGRP ? 's' : 'S');
	else
		ft_putchar(m & S_IXGRP ? 'x' : '-');
	ft_putchar(m & S_IROTH ? 'r' : '-');
	ft_putchar(m & S_IWOTH ? 'w' : '-');
	if (m & S_ISVTX)
		ft_putchar(m & S_IXOTH ? 't' : 'T');
	else
		ft_putchar(m & S_IXOTH ? 'x' : '-');
}

int		ft_ls_long_lnk(t_lsdata *data)
{
	int				ret;
	char			buf[1024];

	if (S_ISLNK(data->stat.st_mode))
	{
		if ((ret = readlink(data->path, buf, 1024)) < 0)
			return (-1);
		buf[ret] = '\0';
		ft_printf(" -> %s\n", buf);
	}
	else
		ft_putendl("");
	return (0);
}

int		ft_ls_long_xattr(mode_t m, char *path)
{
	char		x;
	acl_t		acl;

	x = ' ';
	if (!S_ISBLK(m) && !S_ISCHR(m) && ft_xattr_count(path) > 0)
		x = '@';
	else if ((acl = acl_get_file(path, ACL_TYPE_EXTENDED)))
	{
		x = '+';
		acl_free((void*)acl);
	}
	ft_putchar(x);
	return (0);
}

void	ft_ls_long_total(t_list *ent)
{
	struct stat		stat;
	t_lsdata		*data;
	int				total;

	total = 0;
	while (ent)
	{
		data = ent->content;
		stat = data->stat;
		ent = ent->next;
		total += stat.st_blocks;
	}
	ft_printf("total %i\n", total);
}

#define FT_MAX_WR(a,b)	a = FT_MAX(a,b)

int		ft_ls_long_pads(t_list *ent, t_pads *pads)
{
	struct passwd	*pwd;
	struct group	*grp;
	struct stat		stat;

	ft_bzero(pads, sizeof(*pads));
	while (ent)
	{
		stat = ((t_lsdata*)ent->content)->stat;
		ent = ent->next;
		if (!(pwd = getpwuid(stat.st_uid)))
			return (1);
		if (!(grp = getgrgid(stat.st_gid)))
			return (1);
		FT_MAX_WR(pads->name, (int)ft_strlen(pwd->pw_name));
		FT_MAX_WR(pads->gr_name, (int)ft_strlen(grp->gr_name));
		FT_MAX_WR(pads->nlink, (int)ft_uilen(stat.st_nlink));
		FT_MAX_WR(pads->size, (int)ft_ilen(stat.st_size));
		if (S_ISCHR(stat.st_mode) || S_ISBLK(stat.st_mode))
			FT_MAX_WR(pads->minor, (int)ft_ilen(minor(stat.st_rdev)));
		if (S_ISCHR(stat.st_mode) || S_ISBLK(stat.st_mode))
			FT_MAX_WR(pads->major, (int)ft_ilen(major(stat.st_rdev)));
	}
	pads->size = FT_MAX(pads->size, pads->minor ?
			pads->minor + pads->major + 3 : pads->size);
	return (0);
}
