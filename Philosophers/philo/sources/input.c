/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:51:46 by agomez-m          #+#    #+#             */
/*   Updated: 2024/02/04 12:26:15 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_input_digits(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	wrong_input_check(int argc, char **argv)
{
	if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[1]) > 200)
	{
		printf("Error: Wrong number of philosophers\n");
		return (1);
	}
	if (ft_atoi(argv[2]) < 60 || ft_atoi(argv[3]) < 60 || ft_atoi(argv[4]) < 60)
	{
		printf("Error: Wrong time\n");
		return (1);
	}
	if (argc == 6 && ft_atoi(argv[5]) <= 0)
	{
		printf("Error: Wrong number of meals\n");
		return (1);
	}
	return (0);
}

int	ft_check_args(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		printf("Error: Wrong number of arguments\n");
		return (1);
	}
	if (check_input_digits(argc, argv) == 1)
	{
		printf("Error: Wrong input (or negative/letters) \
			Only numbers (0-200 philos) DIE EAT SLEEP");
		return (1);
	}
	if (wrong_input_check(argc, argv) == 1)
		return (1);
	return (0);
}

/*
comprobamos que todos sean numeros y no caracteres
comprobamos si el tiempo es menor que 60 segundos
comprobamos si el numero de filosofos es menor que 1 o mayor que 200
comprobamos si el numero de comidas es menor o igual que 0

*/