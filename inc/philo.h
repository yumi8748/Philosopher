/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:36:17 by yu-chen           #+#    #+#             */
/*   Updated: 2024/07/09 15:24:46 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/types.h>
# include <unistd.h>

# define TAKE_FORKS "has taken a fork"
# define THINKING "is thinking"
# define SLEEPING "is sleeping"
# define EATING "is eating"
# define DIED "died"

# define THREAD_ERR "ERROR WHILE CREATING THREADS"
# define JOIN_ERR "ERROR WHILE JOINING THREADS"

struct s_data;

typedef struct s_philo
{
	struct s_data	*data;
	pthread_t		t1;
	int				id;
	int				eat_count;
	int				eating;
	u_int64_t		time_to_die;
	pthread_mutex_t	lock;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
}					t_philo;

typedef struct s_data
{
	t_philo			*philos;
	pthread_t		*tid;
	int				philo_nbr;
	int				meals_nbr;
	u_int64_t		death_duration;
	u_int64_t		eat_duration;
	u_int64_t		sleep_duration;
	u_int64_t		start_duration;
	int				dead;
	int				finished;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	pthread_mutex_t	write;
}					t_data;

int					check_input(char **av);
int					thread_init(t_data *data);
int					init(t_data *data, int ac, char **av);
void				*routine(void *philo_ptr);
void				*check_each_philo(void *philo_ptr);
void				*check_all_philo(void *data_ptr);
int					ft_error(char *str, t_data *data);
int					ft_usleep(useconds_t time);
u_int64_t			get_time(void);
void				ft_destory_n_exit(t_data *data);
void				eat(t_philo *philo);
void				messages(char *str, t_philo *philo);

int					ft_isdigit(int c);
int					ft_isspace(char c);
int					ft_atoi(char *s);
int					ft_strcmp(char *s1, char *s2);

#endif