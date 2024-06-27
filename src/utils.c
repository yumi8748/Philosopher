/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:56:16 by yu-chen           #+#    #+#             */
/*   Updated: 2024/06/27 17:21:37 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_destory_exit(t_data *data);
{
	
}

int	ft_error(char *str, t_data *data)
{
	printf("%s", str);
	if (data)
		ft_destory_exit(data);
	return (1);
}

int	check_input(char **av)
{
	int i;
	int j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == ' ' || av[i][j] == '\t')
			{
				i++;
				continue ;
			}
			if (av[i][j] < 48 || av[i][j] > 57)
				return (ft_error("INVALID INPUT CHARACTER", NULL));
			j++;
		}
		i++;
	}
	return (0);
}
