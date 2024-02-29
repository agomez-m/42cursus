# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 15:57:12 by agomez-m          #+#    #+#              #
#    Updated: 2024/02/29 19:45:31 by agomez-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus
CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror  #-g -fsanitize=thread

SRC_DIR = sources/
OBJ_DIR = objects/

SRC = $(wildcard $(SRC_DIR)*.c)
OBJS = $(addprefix $(OBJ_DIR), $(notdir $(SRC:.c=.o)))

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c 
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME) 

re: fclean all
#-g #-fsanitize=thread
.PHONY: all clean fclean re

