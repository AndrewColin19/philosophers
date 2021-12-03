/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:31:13 by acolin            #+#    #+#             */
/*   Updated: 2021/12/03 12:23:07 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	philo_use_fork(t_philo *philo,
			int (*mutex_action)(), char *message)
{
	mutex_action(philo->table->forks);
	aff_msg_p(philo, message);
	mutex_action(philo->table->forks);
	aff_msg_p(philo, message);
}

void	p_think(t_philo *philo)
{
	philo->action.think = 1;
	aff_msg_p(philo, THINK);
	philo->action.think = 0;
}

void	p_sleep(t_philo *philo)
{
	philo->action.sleep = 1;
	aff_msg_p(philo, SLEEP);
	usleep_perso(philo->table->time_to_sleep);
	philo->action.sleep = 0;
}

void	p_eat(t_philo *philo)
{
	philo_use_fork(philo, sem_wait, TAKE);
	philo->time_eat = get_ms_now();
	aff_msg_p(philo, EAT);
	philo->action.eat = 1;
	usleep_perso(philo->table->time_to_eat);
	philo->action.eat = 0;
	philo->eat++;
	philo_use_fork(philo, sem_post, NULL);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	if (philo->nb % 2 == 0)
		usleep_perso(10);
	while (!philo->table->death)
	{
		p_eat(philo);
		p_sleep(philo);
		p_think(philo);
	}
	return (NULL);
}
