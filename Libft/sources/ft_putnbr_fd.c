/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:56:48 by agomez-m          #+#    #+#             */
/*   Updated: 2023/09/12 17:57:06 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putnbr_fd(int n, int fd)
{
    long int nb;

    nb = n;
    if (nb < 0)
    {
        ft_putchar_fd('-', fd);
        nb = -nb;
    }
    if (nb >= 10)
    {
        ft_putnbr_fd(nb / 10, fd);
        ft_putnbr_fd(nb % 10, fd);
    }
    else
        ft_putchar_fd(nb + '0', fd);
}

/* imprime un numero en el fd indicado */