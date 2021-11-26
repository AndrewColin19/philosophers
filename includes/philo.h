/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:18:00 by acolin            #+#    #+#             */
/*   Updated: 2021/11/26 16:20:37 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <time.h>
# include <sys/time.h>
# include <pthread.h>

# define TAKE "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIE "died"

typedef struct s_time_philo
{
	struct timeval current_time;
	suseconds_t start_us;
	time_t start_s;
}	t_time_philo;

typedef struct s_this_philo
{
	int			nb;
	int			me;
	pthread_t	thread_p;
	int			nb_fork;
}	t_this_philo;

typedef struct s_philo
{
	int				n;
	int				nbphilo;
	int				time_to_sleep;
	int				time_to_eat;
	int				time_to_die;
	int				number_of_eat;
	t_time_philo	time;
	t_this_philo	*philos;
	pthread_mutex_t	*fork;
}	t_philo;

/*utils*/
int	ft_isdigit(int c);
int	ft_atoi(const char *nptr);
/*parse*/
int	parse_arg(int argc, char **argv, t_philo *philo);
/*routine*/
void *routine(void *arg);

#endif