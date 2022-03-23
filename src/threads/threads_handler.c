/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldominiq <ldominiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:04:49 by ldominiq          #+#    #+#             */
/*   Updated: 2022/03/24 00:03:40 by ldominiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	eat(t_data *data, int i)
{
	pthread_mutex_lock(data->philosophers[i].m_rfork);
	print_status(data, MSG_FORK, i);
	pthread_mutex_lock(data->philosophers[i].m_lfork);
	print_status(data, MSG_FORK, i);
	data->philosophers[i].last_meal = get_current_time();
	data->philosophers[i].nb_meal++;
	print_status(data, MSG_EATING, i);
	wait_action(data->time_to_eat);
	pthread_mutex_unlock(data->philosophers[i].m_rfork);
	pthread_mutex_unlock(data->philosophers[i].m_lfork);
	print_status(data, MSG_SLEEPING, i);
	wait_action(data->time_to_sleep);
	print_status(data, MSG_THINKING, i);
}

void	*philo_routine(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	i = data->idx++;
	data->philosophers[i].last_meal = get_current_time();
	while (1)
	{
		eat(data, i);
		if (data->philosophers[i].nb_meal == data->nb_to_eat)
			data->philosophers[i].full = 1;
	}
	return (NULL);
}

//TODO: Handling of dead/full philosopher: stop threads, free memory | fix timestamp
void	*grim_reaper_routine(void *arg)
{
	t_data 	*data;
	int		i;
	int		count;

	data = (t_data *)arg;
	while (1)
	{
		i = -1;
		while (++i < data->p_amount)
		{
			if (get_current_time() - data->philosophers[i].last_meal \
				> (unsigned long long)data->time_to_die)
				print_status(data, MSG_DEAD, i);
		}
		i = -1;
		while (++i < data->p_amount)
		{
			if (data->philosophers[i].nb_meal >= data->nb_to_eat)
				count++;
		}
		if (count == data->p_amount)
			print_status(data, MSG_FULL, data->p_amount - 1);
	}
	return (NULL);
}
