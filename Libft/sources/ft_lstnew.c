/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:19:58 by agomez-m          #+#    #+#             */
/*   Updated: 2023/09/12 18:21:06 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstnew(void *content)
{
    t_list *new;

    if (!(new = (t_list *)malloc(sizeof(t_list))))
        return (NULL);
    new->content = content;
    new->next = NULL;
    return (new);
}

/* crea un nuevo elemento de la lista */
