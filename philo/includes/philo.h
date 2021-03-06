/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:18:00 by acolin            #+#    #+#             */
/*   Updated: 2021/12/02 13:58:41 by acolin           ###   ########.fr       */
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
# define M 1000

typedef struct s_action
{
	int	eat;
	int	sleep;
	int	think;
}	t_action;

typedef struct s_philo
{
	int				nb;
	pthread_t		thread_p;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*fork_other;
	struct s_table	*table;
	size_t			time_eat;
	int				eat;
	t_action		action;
}	t_philo;

typedef struct s_table
{
	int				nbphilo;
	int				number_of_eat;
	int				death;
	size_t			time_to_sleep;
	size_t			time_to_eat;
	size_t			time_to_die;
	t_philo			*philos;
	struct timeval	time;
	pthread_mutex_t	p_print;
}	t_table;

/*utils*/
int				ft_isdigit(int c);
int				ft_atoi(const char *nptr);
void			aff_msg_p(t_philo *philo, char *message);
size_t			ft_strlen(const char *s);
/*parse*/
int				parse_arg(int argc, char **argv, t_table *table);
/*routine*/
void			*routine(void *arg);
/*time*/
void			usleep_perso(size_t	usec);
size_t			get_ms_to_start(t_table *table);
size_t			get_ms_now(void);
struct timeval	get_now(void);
/*check action*/
void			p_check_death(t_table *table);

#endif