# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/23 16:54:54 by agomez-m          #+#    #+#              #
#    Updated: 2023/10/23 17:36:54 by agomez-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
ARCHIVE = push_swap.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -O2 
MAKE_LIB = ar -rcs
CP = cp

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
LIBFT		= ./libft/libft.a
LIBFT_DIR	= ./libft

all : $(NAME)

$(NAME) : $(ARCHIVE)
	$(CC) $^ -o $@

$(ARCHIVE): $(LIBFT) $(OBJS)
	$(MAKE_LIB) $@ $^

$(LIBFT): 
	@$(MAKE) -C $(LIBFT_DIR)

%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@ 

bonus : 
	cd ../checker && make
	
clean :
	@$(MAKE) clean -C $(LIBFT_DIR)
	rm -f $(OBJS) $(ARCHIVE)

fclean : clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME)
	cd ../checker && make fclean

re : fclean all

.PHONY : all clean fclean re