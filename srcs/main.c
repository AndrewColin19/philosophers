/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrew <andrew@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:11:41 by acolin            #+#    #+#             */
/*   Updated: 2021/12/01 18:53:27 by andrew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	set_p_num_table(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->nbphilo)
	{
		table->philos[i].nb = i + 1;
		table->philos[i].table = table;
		table->philos[i].fork = malloc(sizeof(pthread_mutex_t));
	}
}

int	init_philo(t_table *table)
{
	int	i;

	i = 0;
	pthread_mutex_init(&table->p_print, NULL);
	table->philos = malloc(sizeof(t_philo) * table->nbphilo);
	if (!table->philos)
		return (0);
	set_p_num_table(table);
	while (i < table->nbphilo)
		pthread_mutex_init(table->philos[i++].fork, NULL);
	i = -1;
	if (table->nbphilo != 1)
	{
		table->philos[table->nbphilo - 1].fork_other = table->philos[0].fork;
		while (++i < table->nbphilo - 1)
			table->philos[i].fork_other = table->philos[i + 1].fork;
	}
	else
		table->philos[0].fork_other = table->philos[0].fork_other;
	return (1);
}

void	creat_thread(t_table *table)
{
	int	i;

	table->time = get_now();
	i = -1;
	while (++i < table->nbphilo)
		pthread_create(&table->philos[i].thread_p, NULL, routine,
			&table->philos[i]);
	table->start = 1;
}

int	main(int argc, char *argv[])
{
	t_table	table;
	int		i;

	if (argc == 5 || argc == 6)
	{
		if (!parse_arg(argc, argv, &table))
			return (0);
		if (!init_philo(&table))
			return (0);
		creat_thread(&table);
		p_check_death(&table);
		i = -1;
		while (++i < table.nbphilo)
		{
			pthread_mutex_destroy(table.philos[i].fork);
			free(table.philos[i].fork);
		}
		pthread_mutex_destroy(&table.p_print);
		free(table.philos);
	}	
	return (1);
}
