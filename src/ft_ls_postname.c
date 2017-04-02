/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_postname.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 14:19:17 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/25 15:59:56 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_postname(mode_t m, int opts)
{
	char	c;

	c = 0;
	if (opts & OPTS_UF)
	{
		c = S_ISDIR(m) ? '/' : c;
		c = S_ISREG(m) && (S_IXUGO & m) ? '*' : c;
		c = S_ISLNK(m) ? '@' : c;
		c = S_ISSOCK(m) ? '=' : c;
		c = S_ISWHT(m) ? '%' : c;
		c = S_ISFIFO(m) ? '|' : c;
	}
	else if (opts & OPTS_LP && S_ISDIR(m))
		c = '/';
	if (c)
		ft_putchar(c);
}
