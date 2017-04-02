/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xattr_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:00:43 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/03 18:00:44 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_xattr_print(char *path)
{
	ssize_t		listlen;
	ssize_t		valuelen;
	char		list[FT_XATTR_SIZE];
	char		value[FT_XATTR_SIZE];
	int			i;

	i = 0;
	listlen = listxattr(path, list, FT_XATTR_SIZE, XATTR_NOFOLLOW);
	if (listlen == -1)
		return (1);
	while (i < listlen)
	{
		valuelen = getxattr(path, list + i, value,
				FT_XATTR_SIZE, 0, XATTR_NOFOLLOW);
		if (valuelen == -1)
			ft_printf("couldn't get value\n");
		else
			ft_printf("%s:\n%s\n", list + i, value);
		i += ft_strlen(list) + 1;
	}
	return (0);
}
