/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_tetra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 10:43:15 by cbouvell          #+#    #+#             */
/*   Updated: 2017/01/09 15:06:22 by cbouvell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char	**ft_strsplit(char const *s, char c);
void	ft_puttab(char **tab);

int	empty_li(char **tetra)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tetra[i])
	{
		j = 0;
		while (tetra[i][j])
		{
			if (tetra[i][j] != '.')
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

int empty_col(char **tetra)
{
	int i;
	int j;
	int col;

	i = 0;
	j = 0;
	col = 4;
	while (tetra[i])
	{
		j = 0;
		while (tetra[i][j])
		{
			if (tetra[i][j] != '.' && j < col)
				col = j;
			j++;
		}
		i++;
	}
	return (col);
}

char	**mv_tetra(char **tetra)
{
	int i;
	int j;
	int li;
	int col;

	li = empty_li(tetra);
	col = empty_col(tetra);
	i = 0;
	while (i < 4 - li)
	{
		j = 0;
		while (j < 4 - col)
		{
			if (tetra[li + i][col + j])
				tetra[i][j] = tetra[li + i][col + j];
			j++;
		}
		/*while (j >= 4 - col && j < 4)
		{
			tetra[i][j] = '.';
			j++;
		}
		tetra[i][4] = '\0';*/
		i++;
	}
	while (i >= 4 - li && i < 4)
	{
		j = 4;
		while (j < 4)
		{
			tetra[i][j] = '.';
			j++;
		}
		tetra[i][j] = '\0';
		i++;
	}	
	return (tetra);
}

int main()
{
	char *s;
	char **tab;

	s = "..#. ..#. .##. ....";
	tab = ft_strsplit(s, ' ');
	ft_puttab(tab);
	mv_tetra(tab);
	write(1, "\n", 1);
	ft_puttab(tab);
	return (0);
}
