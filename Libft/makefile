# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 13:32:39 by agomez-m          #+#    #+#              #
#    Updated: 2023/09/12 18:41:45 by agomez-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS_DIR = ./sources/

OBJS    =	ft_atoi.o ft_bzero.o ft_calloc.o ft_isalnum.o ft_isalpha.o \
            ft_isascii.o ft_isdigit.o ft_isprint.o ft_itoa.o ft_memccpy.o \
            ft_memchr.o ft_memcmp.o ft_memcpy.o ft_memmove.o ft_memset.o \
            ft_putchar_fd.o ft_putendl_fd.o ft_putnbr_fd.o ft_putstr_fd.o \
            ft_split.o ft_strchr.o ft_strdup.o ft_strjoin.o ft_strlcat.o \
            ft_strlcpy.o ft_strlen.o ft_strmapi.o ft_strncmp.o ft_strnstr.o \
            ft_strrchr.o ft_strtrim.o ft_substr.o ft_tolower.o ft_toupper.o\

OBJS_BONUS_DIR = ./bonus/

OBJS_BONUS = ft_lstadd_back_bonus.o ft_lstadd_front_bonus.o \
            ft_lstclear_bonus.o ft_lstdelone_bonus.o ft_lstiter_bonus.o \
            ft_lstlast_bonus.o ft_lstmap_bonus.o ft_lstnew_bonus.o \
            ft_lstsize_bonus.o\

NAME    =   libft.a

CC      =   gcc

RM      =   rm -f

CFLAGS  =   -Wall -Wextra -Werror

.c.o:
            ${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
            
${NAME}:    ${OBJS}
            ar rc ${NAME} ${OBJS}
            ranlib ${NAME}
            
all:        ${NAME}

bonus:      ${OBJS} ${OBJS_BONUS}
            ar rc ${NAME} ${OBJS} ${OBJS_BONUS}
            ranlib ${NAME}
            
clean:
            ${RM} ${OBJS} ${OBJS_BONUS}
            
fclean:     clean
            ${RM} ${NAME}
            
re:         fclean all

.PHONY:     all clean fclean re bonus
