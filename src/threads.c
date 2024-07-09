/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 17:37:51 by yu-chen           #+#    #+#             */
/*   Updated: 2024/07/09 18:08:59 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*check_all_philo(void *data_ptr)
{
	t_philo	*philo;

	philo = (t_philo *)data_ptr;
	while (philo->data->dead == 0)
	{
		pthread_mutex_lock(&philo->lock);
		if (philo->data->finished >= philo->data->philo_nbr)
			philo->data->dead = 1;
		pthread_mutex_unlock(&philo->lock);
	}
	return ((void *)0);
}

void	*check_each_philo(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *)philo_ptr;
	while (philo->data->dead == 0)
	{
		pthread_mutex_lock(&philo->lock);
		if (get_time() >= philo->time_to_die && philo->eating == 0)
			messages(DIED, philo); //
		if (philo->eat_count == philo->data->meals_nbr)
		{
			pthread_mutex_lock(&philo->data->lock);
			philo->data->finished++;
			philo->eat_count++; // why
			pthread_mutex_unlock(&philo->data->lock);
		}
		pthread_mutex_unlock(&philo->lock);
	}
	return ((void *)0);
}

void	*routine(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *)philo_ptr;
	philo->time_to_die = philo->data->death_duration + get_time();
	if (pthread_create(&philo->t1, NULL, &check_each_philo, (void *)philo))
		return ((void *)1);
	while (philo->data->dead == 0)
	{
		eat(philo);
		messages(THINKING, philo); //
	}
	if (pthread_join(philo->t1, NULL))
		return ((void *)1);
	return ((void *)0);
}

int	thread_init(t_data *data)
{
	pthread_t	t0;
	int			i;

	data->start_duration = get_time();
	if (data->meals_nbr > 0)
	{
		if (pthread_create(&t0, NULL, &check_all_philo, &data->philos[0]))
			return (ft_error(THREAD_ERR, data));
	}
	i = 0;
	while (i < data->philo_nbr)
	{
		if (pthread_create(&data->tid[i], NULL, &routine, &data->philos[i]))
			return (ft_error(THREAD_ERR, data));
		ft_usleep(1); //?
		i++;
	}
	i = 0;
	while (i < data->philo_nbr)
	{
		if (pthread_join(data->tid[i], NULL))
			return (ft_error(JOIN_ERR, data));
		i++;
	}
	return (0);
}
