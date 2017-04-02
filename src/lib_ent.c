/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_dirents.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:00:05 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/25 18:27:02 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	ft_ent_filter prend en parametre la liste des entrées soit une liste 
**	d'infomations necessaire à l'affichage des fichiers selon les options
**
**	Si les options a ou f ne sont pas entrées
**		Si l'option grand A n'est pas non plus presente alors om utilise
**		ft_lst_delif qui a pour job de
*/

void	ft_ent_filter(t_list **ent, int opts)
{
	if (!(opts & (OPTS_LA | OPTS_LF)))
	{
		if (!(opts & OPTS_UA))
			ft_lst_delif(ent, ".", &ft_lsdata_cmp0, &ft_ent_free);
		else
			ft_lst_delif(ent, ".", &ft_lsdata_cmpa, &ft_ent_free);
	}
}

void	ft_ent_sort(t_list **ent, int opts)
{
	int			(*ft_sort)();

	ft_lst_reverse(ent);
	ft_sort = &ft_lsdata_cmp_name;
	if (opts & OPTS_LF)
		return ;
	if (opts & OPTS_US)
		ft_sort = &ft_lsdata_cmp_size;
	else if (opts & OPTS_LT)
	{
		if (opts & OPTS_LC)
			ft_sort = &ft_cmp_ctime;
		else if (opts & OPTS_LU)
			ft_sort = &ft_cmp_atime;
		else if (opts & OPTS_UU)
			ft_sort = &ft_cmp_btime;
		else
			ft_sort = &ft_cmp_mtime;
	}
	ft_lstsort(ent, ft_sort);
	if (opts & OPTS_LR)
		ft_lst_reverse(ent);
}

void	ft_ent_print(t_list *ent, int *opts, t_lsdata *topdir, t_list *nextdir)
{
	if (*opts & OPTS_HEAD)
		ft_printf("%s:\n", topdir->path);
	else
		*opts |= OPTS_HEAD;
	if (ent)
	{
		if (*opts & (OPTS_LL | OPTS_LG | OPTS_LO))
			ft_ls_long(ent, topdir, *opts);
		else
			ft_ls_short(ent, topdir, *opts);
	}
	else if (*opts & OPTS_ERR_A)
	{
		*opts &= ~OPTS_ERR_A;
		ft_error_access(topdir->path);
	}
	if ((!topdir && nextdir && ent)
			|| (topdir && nextdir)
			|| (((*opts & OPTS_UR) && !(*opts & OPTS_LD)
				&& ent && ft_ent_has_dir(ent))))
		ft_putchar('\n');
}
