/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_pad_sharp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:33:48 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/16 17:56:42 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pad_sharp_o(char *str, t_fmt *fmt)
{
	char	buf[100];

	(void)fmt;
	ft_bzero(buf, 100);
	if (str[0] != '0')
		ft_strcatf(buf, "0");
}

void	ft_pad_sharp_xb(char *str, t_fmt *fmt)
{
	char	buf[100];
	int		i;

	i = 0;
	ft_bzero(buf, 100);
	ft_strcpy(buf, "0");
	ft_strcat(buf, &fmt->conversion);
	if (*str == '0')
		i++;
	if (*str == '0')
		i++;
	ft_strcat(buf, str + i);
	ft_strcpy(str, buf);
}
