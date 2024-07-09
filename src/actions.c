/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 17:37:26 by yu-chen           #+#    #+#             */
/*   Updated: 2024/07/09 18:06:06 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <bits/types.h>

void	messages(char *str, t_philo *philo)
{
	u_int64_t	time;

	pthread_mutex_lock(&philo->data->write);
	time = get_time() - philo->data->start_duration;
	if (ft_strcmp(str, DIED) == 0 && philo->data->dead == 0)
	{
		printf("%lu %d %s\n", time, philo->id, str);
		philo->data->dead = 1;
	}
	if (!philo->data->dead)
		printf("%lu %d %s\n", time, philo->id, str);
	pthread_mutex_unlock(&philo->data->write);
}

void	take_two_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	messages(TAKE_FORKS, philo);
	pthread_mutex_lock(philo->left_fork);
	messages(TAKE_FORKS, philo);
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	messages(SLEEPING, philo);
	ft_usleep(philo->data->sleep_duration);
}

void	eat(t_philo *philo)
{
	take_two_forks(philo);
	pthread_mutex_lock(&philo->lock);
	philo->eating = 1;
	// philo->time_to_die = get_time() + philo->data->death_duration;
	messages(EATING, philo);
	philo->eat_count++;
	ft_usleep(philo->data->eat_duration);
	philo->eating = 0;
	pthread_mutex_unlock(&philo->lock);
	drop_forks(philo);
}
