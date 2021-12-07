/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:17:05 by acolin            #+#    #+#             */
/*   Updated: 2021/12/03 14:21:13 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

static int	check_arg(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		if (ft_strlen(argv[i]) > 9 && ft_atoi(argv[i]) == -1)
			return (0);
	}
	return (1);
}

int	parse_arg(int argc, char **argv, t_table *table)
{
	if (!check_arg(argc, argv))
	{
		printf("Error args\n");
		return (0);
	}
	table->death = 0;
	table->nbphilo = ft_atoi(argv[1]);
	if (table->nbphilo == 0)
	{
		printf("Error args\n");
		return (0);
	}
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	table->number_of_eat = -1;
	if (argc == 6)
		table->number_of_eat = ft_atoi(argv[5]);
	return (1);
}
