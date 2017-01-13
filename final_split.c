/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 13:55:59 by rcolleau          #+#    #+#             */
/*   Updated: 2017/01/13 13:56:07 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		tbllen(char **tbl)
{
	int	i;

	i = 0;
	while (*tbl)
	{
		i++;
		tbl++;
	}
	return (i);
}

char		***final_split(char **tbl)
{
	char	***tf;
	int		i;

	i = 0;
	tf = NULL;
	if ((tf = (char ***)malloc(sizeof(char **) * (tbllen(tbl) + 1))) == NULL)
		return (NULL);
	while (i < tbllen(tbl))
	{
		tf[i] = ft_strsplit(tbl[i], '\n');
		i++;
	}
	tf[tbllen(tbl)] = NULL;
	return (tf);
}
