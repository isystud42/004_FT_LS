/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_short.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:56:28 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/23 18:50:46 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_short(t_list *ent, t_lsdata *topdir, int opts)
{
	while (ent)
	{
		ft_lsdata_filename(ent->content, topdir, opts);
		ft_printf("\n");
		ent = ent->next;
	}
}
