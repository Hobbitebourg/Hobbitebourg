/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 18:02:00 by rcolleau          #+#    #+#             */
/*   Updated: 2017/01/13 12:57:04 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_error(char *str)
{
	int		i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] != '.' && str[i] != '#' && str[i] != '\n')
			return (0);
		i++;
	}
	if (i < 20 || i > 546)
		return (0);
	return (1);
}

char		*open_file(char *str)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];
	char	*sf;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("read error\n");
		return ("ERROR");
	}
	if ((sf = ft_memalloc(BUF_SIZE + 1)) == NULL)
		return (NULL);
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		sf = ft_strjoin(sf, buf);
	}
	if (check_error(sf) == 0)
		return ("ERROR");
	else
		return (sf);
}
