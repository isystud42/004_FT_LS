/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ent_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 11:10:13 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/21 14:22:57 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ent_free(void *ptr, size_t size)
{
	t_lsdata	*data;

	(void)size;
	data = (t_lsdata *)ptr;
	if (data)
	{
		if (data->path)
			ft_strdel(&data->path);
		if (data->dirent)
			ft_memdel((void **)&data->dirent);
		free(data);
	}
}
