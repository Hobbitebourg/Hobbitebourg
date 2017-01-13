/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 13:52:54 by rcolleau          #+#    #+#             */
/*   Updated: 2017/01/06 13:52:56 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		check_tbl(char **tbl)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	c = 65;
	while (tbl[i])
	{
		if (tbl[i][0] == '\n')
			return (0);
		while (tbl[i][j])
		{
			if (tbl[i][j] == '#')
				tbl[i][j] = c;
			j++;
		}
		j = 0;
		c++;
		i++;
	}
	return (1);
}

char		**first_split(char *str)
{
	int		i;
	int		r;
	char	**tbl;

	i = 0;
	r = 20;
	tbl = NULL;
	while (str[i] != '\0')
	{
		if (i == r)
		{
			if (str[i] != '\n')
				return (tbl = ft_strsplit("ERROR", '1'));
			str[i] = '1';
			r += 21;
		}
		i++;
	}
	tbl = ft_strsplit(str, '1');
	if (check_tbl(tbl) == 0)
		*tbl = "ERROR";
	return (tbl);
}
