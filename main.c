/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 15:40:29 by rcolleau          #+#    #+#             */
/*   Updated: 2017/01/13 12:57:49 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//int		dtbllen(char ***tbl)
//{
//	int	i;
//
//	i = 0;
//	while (*tbl)
//	{
//		i++;
//		tbl++;
//	}
//	return (i);
//}
//
//void	printtbl(char ***tbl)
//{
//	int	i;
//	int	j;
//
//	i = 0;
//	j = 0;
//	while (i < dtbllen(tbl))
//	{
//		while (tbl[i][j])
//		{
//			ft_putstr(tbl[i][j]);
//			j++;
//		}
//		j = 0;
//		i++;
//	}
//}
//
//void	affichetbl(char **tbl)
//{
//	while (*tbl)
//	{
//		ft_putstr(*tbl);
//		tbl++;
//	}
//}



int		main(int argc, char **argv)
{
	char	**tbl;
	char	***tf;
	int		i;

	tbl = NULL;
	tf = NULL;
	i = 0;
	if (argc != 2)
	{
		if (argc == 1)
			ft_putendl("Missing File");
		else
			ft_putendl("Too Many Files");
		return (0);
	}
	tbl = first_split(open_file(argv[1]));
	if ((ft_strequ(*tbl, "ERROR")) == 1)
	{
		ft_putendl("Error");
		return (0);
	}
	tf = final_split(tbl);
	while (tf[i])
	{
		mv_tetra(tf[i]);
		ft_puttab(tf[i]);
		printf("chk %d = %d\n\n", i, chk_tetri(tf[i]));
		i++;
	}
	return (0);
}
