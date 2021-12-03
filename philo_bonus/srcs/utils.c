/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:13:32 by acolin            #+#    #+#             */
/*   Updated: 2021/12/03 12:23:17 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"
/**
 * vérifie si l'on a un chiffre (0 à 9).
 *
 * \param	c	caractère a tester
 * \return		Les valeurs renvoyées sont non nulles 
 *				si le caractère c entre dans la catégorie testée, et zéro sinon
 */
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int	ft_overflow(int neg)
{
	if (neg < 0)
		return (0);
	return (-1);
}

/**
 * convertit le début de la chaîne pointée par nptr en entier de type int .
 *
 * \param	nptr	chaine à convertir
 * \return			Le résultat de la conversion.
 */
int	ft_atoi(const char *nptr)
{	
	int	neg;
	int	num;

	num = 0;
	neg = 1;
	while (*nptr == ' ' || *nptr == '\n'
		|| *nptr == '\t' || *nptr == '\r'
		|| *nptr == '\v' || *nptr == '\f')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			neg = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		if ((num * 10 + (*nptr - '0')) / 10 != num)
			return (ft_overflow(neg));
		num *= 10;
		num += *nptr - '0';
		nptr++;
	}
	return (num * neg);
}

void	aff_msg_p(t_philo *philo, char *message)
{
	if (message != NULL)
	{
		sem_wait(philo->table->p_print);
		if (!philo->table->death)
			printf("%lu %i %s\n", get_ms_to_start(philo->table),
				philo->nb, message);
		sem_post(philo->table->p_print);
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
