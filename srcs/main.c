/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:11:41 by acolin            #+#    #+#             */
/*   Updated: 2021/11/26 16:35:48 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int main(int argc, char *argv[])
{
	t_philo	philo;

	if (argc == 5 || argc == 6)
	{
		if (!parse_arg(argc, argv, &philo))
			return (0);
		philo.philos = malloc(sizeof(t_this_philo) * philo.nbphilo);
		philo.fork = malloc(sizeof(pthread_mutex_t) * philo.nbphilo);
		while (philo.n <= philo.nbphilo)
		{
			pthread_create(&philo.philos[philo.n].thread_p, NULL, routine, &philo);
			pthread_mutex_init(&philo.fork[philo.n], NULL);
			usleep(100);
			philo.n++;
		}
		while (1);
	}	
	return (1);
}
