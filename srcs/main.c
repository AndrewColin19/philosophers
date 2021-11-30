/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrew <andrew@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:11:41 by acolin            #+#    #+#             */
/*   Updated: 2021/11/30 22:20:16 by andrew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int init_philo(t_table *table)
{
	int	i;

	i = 0;
	table->philos = malloc(sizeof(t_philo) * table->nbphilo);
	if (!table->philos)
		return (0);
	while (i < table->nbphilo)
	{
		table->philos[i].fork = malloc(sizeof(pthread_mutex_t));
		if (!table->philos[i].fork)
			return (0);
		pthread_mutex_init(&table->philos[i++].fork, NULL);
	}
	i = -1;
	if (table->nbphilo != 1)
	{
		table->philos[table->nbphilo - 1].fork_other = table->philos[0].fork;
		while (++i < table->nbphilo - 1)
			table->philos[i].fork_other = table->philos[i + 1].fork;
	}
	return (1);
}

int main(int argc, char *argv[])
{
	t_table table;

	if (argc == 5 || argc == 6)
	{
		if (!parse_arg(argc, argv, &table))
			return (0);
		if (!init_philo(&table))
			return (0);
		while (philo.n <= philo.nbphilo)
		{
			pthread_create(&philo.philos[philo.n].thread_p, NULL, routine, &philo);
			usleep(100);
			philo.n++;
		}
		while (1);
	}	
	return (1);
}
