/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:13:32 by acolin            #+#    #+#             */
/*   Updated: 2021/11/26 14:14:58 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
