/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:39:11 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/27 11:57:02 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_color(mode_t m)
{
	t_color	color;

	ft_color_mk(&color, FG_DEFAULT, BG_DEFAULT);
	ft_color_mkif(&color, S_ISDIR(m), FG_BLUE, BG_DEFAULT);
	ft_color_mkif(&color, S_ISLNK(m), FG_MAGENTA, BG_DEFAULT);
	ft_color_mkif(&color, S_ISLNK(m), FG_MAGENTA, BG_DEFAULT);
	ft_color_mkif(&color, S_ISSOCK(m), FG_GREEN, BG_DEFAULT);
	ft_color_mkif(&color, S_ISFIFO(m), FG_YELLOW, BG_DEFAULT);
	ft_color_mkif(&color, S_ISREG(m) && (S_IXUGO & m), FG_RED, BG_DEFAULT);
	ft_color_mkif(&color, S_ISBLK(m), FG_BLUE, BG_CYAN);
	ft_color_mkif(&color, S_ISCHR(m), FG_BLUE, BG_YELLOW);
	ft_color_mkif(&color, S_ISREG(m) && (S_IXUGO & m) && (S_ISGID & m),
			FG_BLACK, BG_CYAN);
	ft_color_mkif(&color, S_ISREG(m) && (S_IXUGO & m) && (S_ISUID & m),
			FG_BLACK, BG_RED);
	ft_color_mkif(&color, S_ISDIR(m) && (S_IWOTH & m) && (S_ISVTX & m),
			FG_BLACK, BG_GREEN);
	ft_color_mkif(&color, S_ISDIR(m) && (S_IWOTH & m) && !(S_ISVTX & m),
			FG_BLACK, BG_YELLOW);
	ft_color_set(color);
}
