/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_ls_long.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:59:51 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/27 11:57:47 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_ls_long_middle(struct stat *stat, t_pads *pads, int opts)
{
	struct passwd	*pwd;
	struct group	*grp;

	if ((pwd = getpwuid(stat->st_uid)) == NULL)
		return (1);
	if ((grp = getgrgid(stat->st_gid)) == NULL)
		return (1);
	ft_printf(" %*hu ", pads->nlink, stat->st_nlink);
	if (!(opts & OPTS_LG))
		ft_printf("%-*s", pads->name, pwd->pw_name);
	if (!(opts & (OPTS_LO | OPTS_LG)))
		ft_putstr("  ");
	if (!(opts & OPTS_LO))
		ft_printf("%-*s", pads->gr_name, grp->gr_name);
	if (S_ISBLK(stat->st_mode) || S_ISCHR(stat->st_mode))
		ft_printf("  % *i,% *i",
				pads->major + 1, major(stat->st_rdev),
				pads->minor + 1, minor(stat->st_rdev));
	else
		ft_printf("  %*lld", pads->size, stat->st_size);
	return (0);
}

void	ft_ls_long_date(struct stat *stat, int opts)
{
	time_t		st_time;
	t_mytime	*time;

	if (opts & OPTS_LC)
		st_time = stat->st_ctime;
	else if (opts & OPTS_LU)
		st_time = stat->st_atime;
	else if (opts & OPTS_UU)
		st_time = stat->st_birthtime;
	else
		st_time = stat->st_mtime;
	time = ft_mytime_get(st_time);
	if (opts & OPTS_UT)
		ft_printf(" %s %s %s:%s:%s %s", time->month, time->day, time->hour,
				time->min, time->sec, time->year);
	else if (ft_time_isrecent(st_time))
		ft_printf(" %s %s %s:%s",
				time->month, time->day, time->hour, time->min);
	else
		ft_printf(" %s %s  %s", time->month, time->day, time->year);
	ft_mytime_free(&time);
}

void	ft_ls_long_type(mode_t m)
{
	char	type;

	type = '\0';
	type = S_ISREG(m) ? '-' : type;
	type = S_ISDIR(m) ? 'd' : type;
	type = S_ISFIFO(m) ? 'p' : type;
	type = S_ISSOCK(m) ? 's' : type;
	type = S_ISCHR(m) ? 'c' : type;
	type = S_ISBLK(m) ? 'b' : type;
	type = S_ISLNK(m) ? 'l' : type;
	ft_printf("%c", type);
}
