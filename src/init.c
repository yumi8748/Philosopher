/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:29:20 by yu-chen           #+#    #+#             */
/*   Updated: 2024/06/27 18:41:41 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_malloc(t_data *data)
{
	data->tid = malloc(sizeof(pthread_t) * data->philo_nbr);
	if (!data->tid)
		return (ft_error("ERROR WHILE ALLOCATING THREAD IDs", data));
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_nbr);
	if (!data->forks)
		return (ft_error("ERROR WHILE ALLOCATING FORKS", data));
	data->philos = malloc(sizeof(t_philo) * data->philo_nbr);
	if (!data->philos)
		return (ft_error("ERROR WHILE ALLOCATING PHILOS", data));
	return (0);
}

int	init_data(t_data *data, int ac, char **av)
{
	data->philo_nbr = ft_atoi(av[1]);
	data->time_to_die = (u_int64_t)ft_atoi(av[2]);
	data->time_to_eat = (u_int64_t)ft_atoi(av[3]);
	data->time_to_sleep = (u_int64_t)ft_atoi(av[4]);
	if (ac == 6)
		data->meals_nbr = ft_atoi(av[6]);
	else
		data->meals_nbr = -1;
	if (data->philo_nbr < 0 || data->philo_nbr > 200)
		return (ft_error("INVALID INPUT VALUES", NULL));
	data->dead = 0;
	data->finished = 0;
	pthread_mutex_init(&data->write, NULL);
	pthread_mutex_init(&data->lock, NULL);
	return (0);
}

int	init(t_data *data, int ac, char **av)
{
	if (init_data(data, ac, av))
		return (1);
	if (ft_malloc(data))
		return (1);
	// init_forks
}
