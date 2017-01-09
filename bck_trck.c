/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bck_trck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 15:06:33 by cbouvell          #+#    #+#             */
/*   Updated: 2017/01/06 13:19:15 by cbouvell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char **crea_tab(int size)
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

int	bck_trck(t_list tetra,char **tab, int i, int j)
{
	if (tab[i][j] == '.')
	{
		while (tetra != NULL)
		{
			if (tetra_cmp(tab, i, j, tetra) == 1)
			{
				pl_tetra_tab(tab, pc, i, j);
				if (bck_trck(tetra->next, tab, i, j) == 1)
					return (1);
				rp_pc_pt(tab, tetra	, i, j);
				swap_tetra(tetra);
			}
		}
	}
	else if (tab[i][j + 1])
		bck_trck(tetra, tab, i, j + 1);
	else if (tab[i + 1])
		bck_trck(tetra, tab, i + 1, 0);
	else
		return (0);
}
