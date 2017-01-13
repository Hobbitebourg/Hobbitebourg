/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_r_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 13:22:03 by cbouvell          #+#    #+#             */
/*   Updated: 2017/01/13 16:23:55 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//	static int	chk_r_tetri(char **tetri, char ***r_tetri)
//	{
//		int j;
//		int k;
//		int l;
//		int flag;
//	
//		j = 0;
//		while (r_tetri[j])
//		{
//			flag = 0;
//			k = 1;
//			while (tetri[k])
//			{
//				l = 0;
//				while (tetri[k][l])
//				{
//					if (r_tetri[j][k][l] == '.' && tetri[k][l] != '.')
//						flag++;
//					else if (r_tetri[j][k][l] != '.' && tetri[k][l] == '.')
//						flag++;
//					l++;
//				}
//				k++;
//			}
//			if (flag == 0)
//				return (1);
//			j++;
//		}
//		return (0);
//	}

int	chk_tetri(char **tetri)
{
	int i;
	int j;
	int lg_tetri;
	int flag;

	i = 0;
	flag++;
	while (tetri[i])
	{
		j = 0;
		while (tetri[i][j])
		{
			if (tetri[i][j] != '.')
			{
				lg_tetri++;
				if (tetri[i][j + 1] && tetri[i][j + 1] != '.')
					flag++;
				if (tetri[i + 1] && tetri[i + 1][j] && tetri[i + 1][j] != '.')
					flag++;
			}
			j++;
		}
		i++;
	}
	if (lg_tetri == 4 && flag > 4)
		return (1);
	return (0);
}
