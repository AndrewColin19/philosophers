/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:11:41 by acolin            #+#    #+#             */
/*   Updated: 2021/12/03 12:48:36 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	set_p_num_table(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->nbphilo)
	{
		table->philos[i].nb = i + 1;
		table->philos[i].table = table;
		table->philos[i].eat = 0;
		table->philos[i].time_eat = get_ms_now();
	}
	return (1);
}

int	init_philo(t_table *table)
{
	sem_unlink("p_print");
	sem_unlink("forks");
	table->p_print = sem_open("p_print", O_CREAT, 0666, 1);
	table->forks = sem_open("forks", O_CREAT, 0666, table->nbphilo);
	table->philos = malloc(sizeof(t_philo) * table->nbphilo);
	if (!table->philos || !set_p_num_table(table))
		return (0);
	return (1);
}

void	supp_table(t_table *table)
{
	sem_unlink("p_print");
	sem_unlink("forks");
	free(table->philos);
}

void	creat_thread(t_table *table)
{
	int	i;

	table->time = get_now();
	i = -1;
	while (++i < table->nbphilo)
		pthread_create(&table->philos[i].thread_p, NULL, routine,
			&table->philos[i]);
}

int	main(int argc, char *argv[])
{
	t_table	table;

	if (argc == 5 || argc == 6)
	{
		if (!parse_arg(argc, argv, &table))
			return (0);
		if (!init_philo(&table))
			return (0);
		creat_thread(&table);
		p_check_death(&table);
		supp_table(&table);
	}
	else
	{
		printf("usage: <number of philosophers> <Time to die> <Time to eat>");
		printf(" <Time to sleep> <Nullable number of eat>\n");
	}
	return (1);
}
