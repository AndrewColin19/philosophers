/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrew <andrew@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:31:13 by acolin            #+#    #+#             */
/*   Updated: 2021/11/30 19:52:03 by andrew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

unsigned long	get_time(t_time_philo *time)
{
	if (!time->start_s && !time->start_s)
	{
		gettimeofday(&time->current_time, NULL);
		time->start_us = time->current_time.tv_usec;
		time->start_s = time->current_time.tv_sec;
	}
	gettimeofday(&time->current_time, NULL);
	return (((time->current_time.tv_sec - time->start_s) * 1000) +
		((time->current_time.tv_usec - time->start_us) / 1000));
}

void	p_think()
{
	
}

void	p_sleep()
{

}

void	p_eat()
{
	
}

void *routine(void *arg)
{
	t_this_philo	*philo;
	t_philo			*philos;

	philos = (t_philo *) arg;
	philo = &philos->philos[philos->n];
	philo->nb = philos->n + 1;
	philo->me = philos->n;
	while (1)
	{
		if (philo->nb % 2 == 0)
			pthread_mutex_lock(&philos->fork[philo->me]);
		else
		{
			usleep(philos->time_to_eat * 100);
			pthread_mutex_lock(&philos->fork[philo->me]);
		}
		printf("%ld %i %s\n", get_time(&philos->time), philo->nb, TAKE);
		if (philo->nb == philos->nbphilo)
			pthread_mutex_lock(&philos->fork[0]);
		else
			pthread_mutex_lock(&philos->fork[philo->me + 1]);
		printf("%ld %i %s\n", get_time(&philos->time), philo->nb, TAKE);
		printf("%ld %i %s\n", get_time(&philos->time), philo->nb, EAT);
		usleep(philos->time_to_eat * 100);
		pthread_mutex_unlock(&philos->fork[philo->me]);
		if (philo->nb == philos->nbphilo)
			pthread_mutex_unlock(&philos->fork[0]);
		else
			pthread_mutex_unlock(&philos->fork[philo->me + 1]);
		
		printf("%ld %i %s\n", get_time(&philos->time), philo->nb, SLEEP);
		usleep(philos->time_to_sleep * 100);
		printf("%ld %i %s\n", get_time(&philos->time), philo->nb, THINK);
		
	}
	return (NULL);
}