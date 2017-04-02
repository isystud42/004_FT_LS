/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:58:45 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/04 13:11:59 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*out;
	size_t	size;

	out = ft_strdup(s);
	while (*out && FT_WS(*out))
		out++;
	size = ft_strlen(out);
	while (size - 1 && FT_WS(out[size - 1]))
	{
		size--;
		out[size] = '\0';
	}
	return (out);
}
