# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 13:32:39 by agomez-m          #+#    #+#              #
#    Updated: 2023/09/12 13:32:40 by agomez-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS = ft_isalnum.c ft_isdigit.c ft_isalpha.c

all: $(OBJS)
    cc -c $(OBJS)      # Compila archivos fuente en objetos
    ar rcs libft.a *.o  # Crea la biblioteca estática
    rm -f *.o           # Elimina archivos objeto

%.o: %.c
    cc -c $< -o $@

clean:  
    rm -f $(OBJS)

fclean: clean
    rm -f libft.a

re: fclean all
