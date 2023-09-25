# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/25 13:07:26 by agomez-m          #+#    #+#              #
#    Updated: 2023/09/25 18:23:04 by agomez-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

LIBFT		= ./libft/libft.a
LIBFT_DIR	= ./libft

SRC			= ./srcs

PRINTF_SRCS	= ft_printf.c \
				ft_print_char.c \
				ft_print_str.c \
				ft_print_digit.c \
				ft_print_digitX.c \
				ft_print_u.c \
				ft_print_poi.c

OBJS		= $(PRINTF_SRCS:.c=.o)

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs
RM			= rm -f
CP			= cp

all:		$(NAME)

$(NAME):	$(LIBFT) $(OBJS)
				$(CP) $(LIBFT) $(NAME)
				$(AR) $(NAME) $(OBJS)
			
# Esta parte del Makefile define una regla para construir el objetivo $(NAME), 
# que es un archivo estático. Para hacerlo, primero copia el contenido 
# del archivo $(LIBFT) a $(NAME) y luego agrega los archivos objeto $(OBJS) 
# al archivo estático $(NAME) utilizando el comando ar.

$(LIBFT):	$(LIBFT_DIR)
				@$(MAKE) -C $(LIBFT_DIR)

# esta parte del Makefile se utiliza para asegurarse de que el contenido 
# en $(LIBFT_DIR) se construya antes de construir el objetivo $(LIBFT) 
# La notación @ antes de $(MAKE) suprime la salida en la terminal, 
# por lo que no veremos los detalles de construcción de $(LIBFT)

%.o: 		$(SRC)/%.c 
				@$(CC) $(CFLAGS) -c $< -o $@

# se utiliza para compilar archivos fuente (.c) en archivos objeto (.o) 
# utilizando el compilador y las banderas especificadas en las variables 
# CC y CFLAGS. 
# -o $(SRC)/$(@F) asegura que el archivo objeto se coloque en 
# el directorio especificado por $(SRC) y se le dé el mismo nombre que 
#el archivo fuente, pero con la extensión .o. Esto garantiza que los archivos
#  objeto se almacenen en el directorio de origen, en lugar de en el directorio 
# actual o en cualquier otro lugar.

clean:
				@$(MAKE) clean -C $(LIBFT_DIR)
				@$(RM) $(OBJS)

fclean:		clean
				@$(MAKE) fclean -C $(LIBFT_DIR)
				@$(RM) $(NAME)

re:				fclean all

.PHONY:		all clean fclean re