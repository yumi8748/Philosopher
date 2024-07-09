/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:55:10 by yu-chen           #+#    #+#             */
/*   Updated: 2024/07/09 16:02:31 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(char *nbr)
{
	int					i;
	unsigned long long	un_ll;
	int					s;

	i = 0;
	un_ll = 0;
	s = 1;
	if (!nbr)
		return (0);
	while (nbr[i] && ((nbr[i] >= 9 && nbr[i] <= 13) || nbr[i] == 32))
		i++;
	if (nbr[i] == '-' || nbr[i] == '+')
	{
		if (nbr[i] == '-')
			s = -1;
		i++;
	}
	while (nbr[i] && (nbr[i] - '0' >= 0 && nbr[i] - '0' <= 9))
	{
		un_ll = 10 * un_ll + (nbr[i] - '0');
		i++;
		if ((un_ll > 2147483647 && s == 1) || (un_ll > 2147483648 && s == -1))
			return (-1);
	}
	if (i == 0 || i != (int)ft_strlen(nbr))
		return (-1);
	return ((int)un_ll * s);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(char *)s1 - *(char *)s2);
}
