/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:57:21 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/25 12:15:59 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_dirs(t_list *dir, int opts)
{
	t_list		*dir_r;
	t_list		*ent;
	t_lsdata	*dirdata;
	t_list		*tmp;

	ft_ent_sort(&dir, opts);
	ent = NULL;
	while (dir)
	{
		dirdata = dir->content;
		tmp = dir;
		dir = dir->next;
		ft_lstdel(&ent, &ft_ent_free);
		ent = ft_dir_get_ents(dirdata, &opts);
		ft_ls_files(&ent, &dir, dirdata, &opts);
		ft_lstdelone(&tmp, &ft_ent_free);
		if (opts & OPTS_UR && !(opts & OPTS_LD))
		{
			dir_r = ft_ent_get_dirs(&ent);
			ft_lst_merge(&dir_r, dir);
			dir = dir_r;
		}
	}
	ft_lstdel(&ent, &ft_ent_free);
}

/*
**	COMMENTAIRE 1
**
**	ft_ls_files est la seconde fonction appellée par le main, son role de maniere generale
**	est de prendre les t_list ent et dir (modifiées par ft_ls_parse_files), une
**	liste du type t_lsdata actuellement vide, ainsi que la liste les options sous forme de nombre
**	
**	petite parenthese sur les options, elle son stockés dans un int avec la fonction ft_getopts
**	qui attribue les options aux bits d'un int et elle seront recuperées de la même manières
**
**	ft_ls_files passera par les fonction du fichier lib_ent.c
**	- ft_ent_filter() qui
**	- ft_ent_sort()
**	- ft_ent_print()
**	
*/



void	ft_ls_files(t_list **ent, t_list **dir, t_lsdata *topdir, int *opts)
{
	if (ent)
	{
		ft_ent_filter(ent, *opts);
		ft_ent_sort(ent, *opts);
		ft_ent_print(*ent, opts, topdir, *dir);
	}
}
