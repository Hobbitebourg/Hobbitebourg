/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 13:53:08 by rcolleau          #+#    #+#             */
/*   Updated: 2017/01/06 13:54:08 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FILLIT_H
# define _FILLIT_H

# include "../libft/libft.h"
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>

# define BUF_SIZE 39

//typedef struct			s_list
//{
//	char				**tetri;
//	struct s_list		*prev;
//	struct s_list		*next;
//}						t_list

int						main(int argc, char **argv);
char					*open_file(char *str);
char					**first_split(char *str);
char					***final_split(char **tbl);

#endif
