/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:36:17 by yu-chen           #+#    #+#             */
/*   Updated: 2024/06/27 17:54:53 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "../libft/inc/libft.h"
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define TAKE_FORKS "has taken a fork"
# define THINKING "is thinking"
# define SLEEPING "is sleeping"
# define EATING "is eating"
# define DIED "died"

struct s_data;

typedef struct s_philo
{
	struct s_data	*data;
	pthread_t		t1; //?
	int				id;
	int				eat_count;
	int				status;
	int				eating;
	u_int64_t		time_to_die;
	pthread_mutex_t	lock;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
}					t_philo;

typedef struct s_data
{
	t_philo			*philos; //?
	pthread_t		*tid; //?
	int				philo_nbr;
	int				meals_nbr;
	u_int64_t		time_to_die;
	u_int64_t		time_to_eat;
	u_int64_t		time_to_sleep;
	int				dead;
	int				finished;
	pthread_mutex_t	*forks; //?
	pthread_mutex_t	lock; //?
	pthread_mutex_t	write; //?
}					t_data;

#endif