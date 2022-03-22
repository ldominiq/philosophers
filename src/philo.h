/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldominiq <ldominiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:40:52 by ldominiq          #+#    #+#             */
/*   Updated: 2022/03/22 19:17:06 by ldominiq         ###   ########.fr       */
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

typedef struct s_philo
{
	int				idx;
	int				nb_meal;
	int				last_meal;
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

int		check_args(int argc, char *argv[]);
void	*init_all(t_data *data, int argc, char *argv[]);
void	*start_threads(t_data *data);
void	*philo_routine(void *arg);
void	*grim_reaper_routine(void *arg);

#endif