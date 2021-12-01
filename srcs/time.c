/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrew <andrew@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 19:52:17 by andrew            #+#    #+#             */
/*   Updated: 2021/12/01 18:51:16 by andrew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

struct timeval	get_now(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time);
}

size_t	get_ms(struct timeval time)
{
	return (time.tv_sec * M + time.tv_usec / M);
}

size_t	get_ms_now(void)
{
	return (get_ms(get_now()));
}

size_t	get_ms_to_start(t_table *table)
{
	return (get_ms_now() - get_ms(table->time));
}

void	usleep_perso(size_t	usec)
{
	size_t	current;

	current = get_ms_now();
	while (usec > get_ms_now() - current)
		usleep(usec * 10);
}
