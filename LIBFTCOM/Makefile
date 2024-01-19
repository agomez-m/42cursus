# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 13:32:39 by agomez-m          #+#    #+#              #
#    Updated: 2024/01/05 19:10:29 by agomez-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	$ ft_atoi.c \
	$ ft_bzero.c \
	$ ft_calloc.c \
	$ ft_isalnum.c \
	$ ft_isalpha.c \
	$ ft_isascii.c \
	$ ft_isdigit.c \
	$ ft_isprint.c \
	$ ft_itoa.c \
	$ ft_memchr.c \
	$ ft_memcmp.c \
	$ ft_memcpy.c \
	$ ft_memmove.c \
	$ ft_memset.c \
	$ ft_putchar_fd.c \
	$ ft_putendl_fd.c \
	$ ft_putnbr_fd.c \
	$ ft_putstr_fd.c \
	$ ft_split.c \
	$ ft_strchr.c \
	$ ft_strdup.c \
	$ ft_strjoin.c \
	$ ft_strlcat.c \
	$ ft_strlcpy.c \
	$ ft_strlen.c \
	$ ft_strmapi.c \
	$ ft_striteri.c \
	$ ft_strncmp.c \
	$ ft_strnstr.c \
	$ ft_strrchr.c \
	$ ft_strtrim.c \
	$ ft_substr.c \
	$ ft_tolower.c \
	$ ft_toupper.c \
	$ ft_lstadd_back_bonus.c \
	$ ft_lstadd_front_bonus.c \
	$ ft_lstclear_bonus.c \
	$ ft_lstdelone_bonus.c \
	$ ft_lstiter_bonus.c \
	$ ft_lstlast_bonus.c \
	$ ft_lstmap_bonus.c \
	$ ft_lstnew_bonus.c \
	$ ft_lstsize_bonus.c \
	$ ft_printf.c \
	$ ft_print_char.c \
	$ ft_print_str.c \
	$ ft_print_digit.c \
	$ ft_print_digitX.c \
	$ ft_print_poi.c \
	$ get_next_line.c \
	$ ft_strsub.c \
	$ ft_strnew.c \
	$ ft_strlen2.c \
	$ ft_strjoin2.c \
	$ ft_strdel.c \
	$ ft_strcpy.c \
	$ ft_strclr.c\
	$ ft_strchr2.c \
	$ ft_strncat.c


OBJ = $(SRC:.c=.o)

NAME = libftcom.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
    
	
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	$(RM) $(OBJ)
	
fclean: clean
	$(RM) $(NAME)
	
re: fclean all

norm:
	@norminette $(SRC) | grep -v Norme -B1 || true

.PHONY: all clean fclean re