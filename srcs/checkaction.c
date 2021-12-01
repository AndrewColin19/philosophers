/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkaction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrew <andrew@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:38:22 by andrew            #+#    #+#             */
/*   Updated: 2021/12/01 18:51:10 by andrew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	p_check_eat(t_table *table)
{
	int	i;

	if (table->number_of_eat < 0)
		return (0);
	i = -1;
	while (++i < table->nbphilo)
	{
		if (table->philos[i].eat < table->number_of_eat)
			return (0);
	}
	return (1);
}

void	p_check_death(t_table *table)
{
	int	i;

	if (table->nbphilo == 1)
		aff_msg_p(table->philos, DIE);
	while (table->nbphilo > 1)
	{
		i = -1;
		while (++i < table->nbphilo)
		{
			if (table->philos[i].action.eat)
				continue ;
			if ((get_ms_now() - table->philos[i].time_eat)
				>= table->time_to_die && table->philos[i].time_eat != 0)
			{
				aff_msg_p(&table->philos[i], DIE);
				table->death = 1;
				return ;
			}
		}
		if (p_check_eat(table))
			break ;
	}
	table->death = 1;
}
