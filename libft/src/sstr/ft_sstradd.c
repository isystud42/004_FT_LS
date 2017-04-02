/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sstradd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:03:58 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/14 16:31:02 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_sstradd(char **sstr, char *new)
{
	int		i;
	int		size;
	char	**newlist;

	i = 0;
	size = 0;
	if (sstr)
		while (sstr[size])
			size++;
	if (!(newlist = (char **)malloc(sizeof(char *) * (size + 2))))
		return (NULL);
	if (sstr)
		while (sstr[i])
		{
			newlist[i] = sstr[i];
			i++;
		}
	newlist[i++] = ft_strdup(new);
	newlist[i] = NULL;
	free(sstr);
	return (newlist);
}
