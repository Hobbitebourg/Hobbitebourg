/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp_tetri_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 16:06:02 by cbouvell          #+#    #+#             */
/*   Updated: 2017/01/09 15:47:41 by cbouvell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	**ft_strsplit(const char *s, char c);
void	tetri_on(char **tab, char **tetri, int li, int col);
void	ft_puttab(char **tab);

int	cmp_tetri_tab(char **tetri, char **tab, int li, int col)
{
	int i;
	int j;
	int flag;

	flag = 1;
	i = 0;
	while (tetri[i])
	{
		j = 0;
		while (tetri[i][j])
		{
			if (!tab[li + i] && tetri[i][j] != '.')
				flag = 0;
			else if (tetri[i][j] != '.' && !tab[li + i][col + j])
				flag = 0;
			else if (tetri[i][j] != '.' && tab[li + i][col + j] && tab[li + i][col + j] != '.')
				flag = 0;
			j++;
		}
		i++;
	}
	return (flag);
}

int main()
{
	char **tab;
	char **tetra;
	char *lst;
	char *s2;
	int li;
	int col;

	li = 4;
	col = 2;
	lst = "A..B... ABBB... A...... A...... ....... ....... .......";
	tab = ft_strsplit(lst, ' ');
	tetra = (char **)malloc(sizeof(char *) * 4);
	tetra[0] = "#...";
	tetra[1] = "#...";
	tetra[2] = "##..";
	tetra[3] = "....";
	tetra[4] = NULL;
	if (cmp_tetri_tab(tetra, tab, li, col) == 1)
		tetri_on(tab, tetra, li, col);
	ft_puttab(tab);
	return (0);
}
