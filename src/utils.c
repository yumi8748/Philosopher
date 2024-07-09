/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:56:16 by yu-chen           #+#    #+#             */
/*   Updated: 2024/07/09 18:04:33 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_destory_n_exit(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_nbr)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philos[i].lock);
		i++;
	}
	pthread_mutex_destroy(&data->lock);
	pthread_mutex_destroy(&data->write);
	if (data->tid)
		free(data->tid);
	if (data->forks)
		free(data->forks);
	if (data->philos)
		free(data->philos);
}

int	ft_error(char *str, t_data *data)
{
	printf("%s\n", str);
	if (data)
		ft_destory_n_exit(data);
	return (1);
}

int	ft_usleep(useconds_t time)
{
	u_int64_t	start;

	start = get_time();
	while ((get_time() - start) < time)
		usleep(time / 10);
	return (0);
}

int	check_input(char **av)
{
	int	i;

	i = 1;
	if (!av)
		return (ft_error("NULL INPUT", NULL));
	if (ft_atoi(av[1]) <= 0 && ft_atoi(av[1]) > 200)
		return (ft_error("INVLID NUMBER OF PHILOS:1-200", NULL));
	i++;
	while (av[i] && i <= 5)
	{
		if (ft_atoi(av[i]) <= 0)
			return (ft_error("INPUT NOT IN VALID RANGE:0-2147483647", NULL));
		i++;
	}
	return (0);
}

u_int64_t	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (ft_error("gettimeofday() failed\n", NULL));
	return (tv.tv_sec * (u_int64_t)1000 + tv.tv_usec / 1000);
}
