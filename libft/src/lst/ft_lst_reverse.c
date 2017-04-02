/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 13:20:13 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/04 11:09:34 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_reverse(t_list **begin_list)
{
	t_list	*new_start;
	t_list	*tmp;

	new_start = NULL;
	while (*begin_list)
	{
		tmp = (*begin_list)->next;
		(*begin_list)->next = new_start;
		new_start = *begin_list;
		*begin_list = tmp;
	}
	*begin_list = new_start;
}
