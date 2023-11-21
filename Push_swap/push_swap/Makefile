# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/23 16:54:54 by agomez-m          #+#    #+#              #
#    Updated: 2023/10/23 20:06:40 by agomez-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
ARCHIVE = push_swap.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -O2 
MAKE_LIB = ar -rcs

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(ARCHIVE)
	$(CC) $< -o $@

$(ARCHIVE) : $(OBJS)
	$(MAKE_LIB) $(ARCHIVE) $^

%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@ 

bonus : 
	cd ../checker && make
	
clean :
	rm -f $(OBJS) $(ARCHIVE)

fclean : clean
	rm -f $(NAME)
	cd ../checker && make fclean

re : fclean all

.PHONY : all clean fclea re