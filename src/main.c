/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:38:29 by yu-chen           #+#    #+#             */
/*   Updated: 2024/07/08 17:56:45 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	handle_one(t_data *data)
{
	data->start_duration = get_time();
	if (pthread_create(&data->tid[0], NULL, &routine, &data->philos[0]))
		return (ft_error("ERROR WHILE CREATING THREADs", data));
	pthread_detach(data->tid[0]);
	while (data->dead == 0)
		ft_usleep(0);
	ft_destory_n_exit(data);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac > 6 || ac < 5)
	{
		ft_error("INVALID NUMBER OF INPUTS", NULL);
		return (1);
	}
	if (check_input(av))
		return (1);
	if (init(&data, ac, av))
		return (1);
	if (data.philo_nbr == 1)
		return (handle_one(&data));
	if (thread_init(&data))
		return (1);
	ft_destory_n_exit(&data);
	return (0);
}
