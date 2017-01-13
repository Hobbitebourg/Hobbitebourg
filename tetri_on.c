/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_on.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 16:53:28 by cbouvell          #+#    #+#             */
/*   Updated: 2017/01/13 15:36:37 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	tetri_on(char **tab, char **tetri, int li, int col)
{
	int i;
	int j;

	i = 0;
	while (tetri[i])
	{
		j = 0;
		while (tetri[j])
		{
			if (tetri[i][j] != '.')
				tab[i + li][j + col] = tetri[i][j];
			j++;
		}
		i++;
	}
}
