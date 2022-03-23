/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldominiq <ldominiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:40:52 by ldominiq          #+#    #+#             */
/*   Updated: 2022/03/24 00:02:37 by ldominiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "../libft/libft.h"
# include <pthread.h>
# include <time.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define THINKING 0
# define HUNGRY 1
# define EATING 2
# define SLEEPING 3

# define MSG_FORK "has taken a fork"
# define MSG_EATING "is eating"
# define MSG_SLEEPING "is sleeping"
# define MSG_THINKING "is thinking"
# define MSG_DEAD "died"
# define MSG_FULL "philosophers are full"

typedef struct s_philo
{
	int				idx;
	int				nb_meal;
	unsigned long long				last_meal;
	int				full;
	int				state;
	pthread_mutex_t	*m_lfork;
	pthread_mutex_t	*m_rfork;
}			t_philo;

typedef struct s_data
{
	int					idx;
	int					p_amount;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					nb_to_eat;
	t_philo				*philosophers;
	pthread_mutex_t		*m_write;
	pthread_mutex_t		**m_forks;
	unsigned long long	t_start;
	struct timeval		timer;
}			t_data;

int					check_args(int argc, char *argv[]);
void				*init_all(t_data *data, int argc, char *argv[]);
void				*start_threads(t_data *data);
void				*philo_routine(void *arg);
void				*grim_reaper_routine(void *arg);
unsigned long long	get_current_time(void);
void				print_status(t_data *data, char *msg, int i);
void				wait_action(unsigned long long time);

#endif