/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:29:20 by yu-chen           #+#    #+#             */
/*   Updated: 2024/07/09 17:40:04 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_alloc(t_data *data)
{
	data->tid = malloc(sizeof(pthread_t) * data->philo_nbr);
	if (!data->tid)
		return (ft_error("ERROR WHILE ALLOCATING THREAD IDS", data));
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
	data->death_duration = (u_int64_t)ft_atoi(av[2]);
	data->eat_duration = (u_int64_t)ft_atoi(av[3]);
	data->sleep_duration = (u_int64_t)ft_atoi(av[4]);
	if (ac == 6)
		data->meals_nbr = ft_atoi(av[6]);
	else
		data->meals_nbr = -1;
	if (data->philo_nbr <= 0 || data->philo_nbr > 200)
		return (ft_error("INVALID NUMBER OF PHILOS:1-200", NULL));
	data->dead = 0;
	data->finished = 0;
	pthread_mutex_init(&data->write, NULL);
	pthread_mutex_init(&data->lock, NULL);
	return (0);
}

int	init_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_nbr)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	data->philos[0].left_fork = &data->forks[0];
	data->philos[0].right_fork = &data->forks[data->philo_nbr - 1];
	i = 1;
	while (i < data->philo_nbr)
	{
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[i - 1];
		i++;
	}
	return (0);
}

void	init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_nbr)
	{
		data->philos[i].data = data;
		data->philos[i].eat_count = 0;
		data->philos[i].eating = 0;
		data->philos[i].id = i + 1;
		data->philos[i].time_to_die = data->death_duration;
		pthread_mutex_init(&data->philos->lock, NULL);
		i++;
	}
}

int	init(t_data *data, int ac, char **av)
{
	if (init_data(data, ac, av))
		return (1);
	if (ft_alloc(data))
		return (1);
	if (init_forks(data))
		return (1);
	init_philo(data);
	return (0);
}
