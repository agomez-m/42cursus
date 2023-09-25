/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:23:14 by agomez-m          #+#    #+#             */
/*   Updated: 2023/09/25 19:04:48 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_len_uns(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

char	*ft_utoa(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_len_uns(n);
	num = (char *)malloc(sizeof(char *) * (len + 1));
	if (!num)
		return (NULL);
	while (n != 0)
	{
		num[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (num);
}

int	ft_print_u(unsigned int n)
{
	int		len;
	char	*num;

	len = 0;
	if (n == 0)
		len = write(1, "0", 1);
	else
	{
		num = ft_utoa(n);
		len = len + ft_print_str(num);
		free(num);
	}
	return (len);
}
