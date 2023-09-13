/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:25:44 by agomez-m          #+#    #+#             */
/*   Updated: 2023/09/13 11:10:09 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/* devuelve el ultimo elemento de la lista 
while (lst->next): Este bucle while verifica si el puntero next del elemento 
actual (lst) no es nulo. Esto significa que mientras haya un elemento siguiente 
en la lista (es decir, la lista no ha llegado al final),
 el bucle continuará ejecutándose.

lst = lst->next;: En cada iteración del bucle, el puntero lst se actualiza 
para que apunte al siguiente elemento de la lista (lst->next). 
Esto mueve el puntero lst hacia adelante en la lista, avanzando 
al siguiente elemento.*/