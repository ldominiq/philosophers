/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldominiq <ldominiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 23:23:11 by ldominiq          #+#    #+#             */
/*   Updated: 2022/03/30 20:22:32 by ldominiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	clean_exit(t_data *data)
{
	int	i;

	i = -1;
	data->stop = 1;
	while (++i < data->p_amount)
	{
		pthread_mutex_destroy(data->philosophers[i].m_lfork);
		pthread_mutex_destroy(data->philosophers[i].m_rfork);
		pthread_detach(*data->philosophers[i].philo);
		free(data->philosophers[i].philo);
		free(data->m_forks[i]);
	}
	pthread_mutex_destroy(data->m_write);
	free(data->m_write);
	free(data->m_forks);
	free(data->philosophers);
	pthread_detach(*data->grim_reaper);
	free(data->grim_reaper);
}

unsigned long long	get_current_time(void)
{
	struct timeval	current;

	gettimeofday(&current, NULL);
	return ((current.tv_sec * 1000) + (current.tv_usec / 1000));
}

void	print_status(t_data *data, char *msg, int i, int done)
{
	if (!data->stop)
	{
		pthread_mutex_lock(data->m_write);
		printf("| 🕰️  %lld | 👴 %d | %s\n",
			get_current_time() - data->t_start, i + 1, msg);
		if (done)
			clean_exit(data);
		pthread_mutex_unlock(data->m_write);
	}
}

void	wait_action(unsigned long long time)
{
	usleep(time * 1000);
}

int	is_even(int idx)
{
	if (idx % 2 == 0)
		return (1);
	return (0);
}
