# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/09 17:55:16 by rcolleau          #+#    #+#              #
#    Updated: 2017/01/09 19:51:57 by rcolleau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS =	main.c \
		open_file.c \
		first_split.c \
		final_split.c\
		
INC = 	fillit.h \

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)
	make clean

$(OBJS):
	gcc $(FLAGS) -c $(SRCS) -I $(INC)

$(NAME): $(OBJS)
	gcc $(FLAGS) -o $(NAME) $(OBJS) ../phoky-repo/libft/libft.a -I $(INC)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
