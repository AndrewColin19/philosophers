/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrew <andrew@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:18:00 by acolin            #+#    #+#             */
/*   Updated: 2021/11/30 20:01:11 by andrew           ###   ########.fr       */
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

typedef struct s_time
{
	struct timeval current_time;
	suseconds_t start_us;
	time_t start_s;
}	t_time;

typedef struct s_philo
{
	int				nb;
	pthread_t		thread_p;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*fork_other;
}	t_philo;

typedef struct s_table
{
	int		nbphilo;
	int		time_to_sleep;
	int		time_to_eat;
	int		time_to_die;
	int		number_of_eat;
	t_time	time;
	t_philo	*philos;
}	t_table;

/*utils*/
int	ft_isdigit(int c);
int	ft_atoi(const char *nptr);
/*parse*/
int	parse_arg(int argc, char **argv, t_philo *philo);
/*routine*/
void *routine(void *arg);

#endif