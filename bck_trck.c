/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bck_trck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 15:06:33 by cbouvell          #+#    #+#             */
/*   Updated: 2017/01/10 17:29:57 by cbouvell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	**crea_tab(int size)
{
	int i;
	int j;
	char **res;

	i = 0;
	if (!(res = (char **)malloc(sizeof(char *) * size)))
		return (NULL);
	while (i < size)
	{
		j = 0;
		res[i] = (char *)malloc(sizeof(char) * size);
		while (j < size)
		{
			res[i][j] = '.';
			j++;
		}
		res[i][j] = '\0';
		i++;
	}
	return (res);
}

int		bck_trck(char **tetra, char **tab, int i, int j)
{
	if (tetra_cmp(tab, i, j, tetra) == 1)
	{
		tetri_on(tab, pc, i, j);
		if (bck_trck((char **)(tetra + 1), tab, i, j) == 1)
			return (1);
		tetri_off(tab, tetra, i, j);
		swap_tetri((char **)tetra,(char **)(tetra + 1))
	}
	else if (tab[i][j + 1])
		bck_trck(tetra, tab, i, j + 1);
	else if (tab[i + 1])
		bck_trck(tetra, tab, i + 1, 0);
	else
		return (0);
}
