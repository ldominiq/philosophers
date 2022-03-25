/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldominiq <ldominiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:04:49 by ldominiq          #+#    #+#             */
/*   Updated: 2022/03/26 00:00:00 by ldominiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*eat(t_data *data, int i)
{
	if (data->stop)
		return (NULL);
	pthread_mutex_lock(data->philosophers[i].m_rfork);
	print_status(data, MSG_FORK, i, 0);
	pthread_mutex_lock(data->philosophers[i].m_lfork);
	print_status(data, MSG_FORK, i, 0);
	data->philosophers[i].last_meal = get_current_time();
	data->philosophers[i].nb_meal++;
	print_status(data, MSG_EATING, i, 0);
	wait_action(data->time_to_eat);
	if (data->stop)
		return (NULL);
	pthread_mutex_unlock(data->philosophers[i].m_rfork);
	pthread_mutex_unlock(data->philosophers[i].m_lfork);
	print_status(data, MSG_SLEEPING, i, 0);
	wait_action(data->time_to_sleep);
	print_status(data, MSG_THINKING, i, 0);
	return (0);
}

void	*philo_routine(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	i = data->idx++;
	data->philosophers[i].last_meal = get_current_time();
	while (!data->stop)
	{
		eat(data, i);
		if (!data->stop)
		{
			if (data->philosophers[i].nb_meal == data->nb_to_eat)
				data->philosophers[i].full = 1;
		}
	}
	return (NULL);
}

//TODO: fix timestamp / fix one philo stuck after death / fix eating algo to prevent death
void	*grim_reaper_routine(void *arg)
{
	t_data	*data;
	int		i;
	int		count;

	data = (t_data *)arg;
	while (!data->stop)
	{
		i = -1;
		while (++i < data->p_amount && !data->stop)
		{
			if (get_current_time() - data->philosophers[i].last_meal \
				> (unsigned long long)data->time_to_die)
				print_status(data, MSG_DEAD, i, 1);
		}
		i = -1;
		while (++i < data->p_amount && data->nb_to_eat != -1)
		{
			if (data->philosophers[i].nb_meal >= data->nb_to_eat)
				count++;
		}
		if (count == data->p_amount && data->nb_to_eat != -1)
			print_status(data, MSG_FULL, data->p_amount - 1, 1);
	}
	return (NULL);
}
