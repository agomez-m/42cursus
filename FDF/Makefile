# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 18:39:23 by agomez-m          #+#    #+#              #
#    Updated: 2023/12/18 18:34:01 by agomez-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FRAMEWORKS=-framework OpenGL -framework AppKit
FLAGS=-Werror -Wextra -Wall 
NAME=fdf
SRC=sources/*.c
INCLUDES=LIBFTCOM/libftcom.a minilibx_macos/libmlx.a

all:
	@make -C LIBFTCOM/ all
	@make -C minilibx_macos/ all
	gcc $(SRC) -o $(NAME) $(FLAGS) $(INCLUDES) $(FRAMEWORKS)

clean:
	@make -C LIBFTCOM/ clean
	@make -C minilibx_macos/ clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C LIBFTCOM/ fclean

re: fclean all

norm:
	@make -C LIBFTCOM/ norm
	@norminette $(SRC) 

.PHONY: all clean fclean re