/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 23:23:11 by ldominiq          #+#    #+#             */
/*   Updated: 2022/05/31 12:38:54 by lucas            ###   ########.fr       */
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
		free(data->philosophers[i].philo);
		free(data->m_forks[i]);
	}
	pthread_mutex_destroy(data->m_write);
	free(data->m_write);
	free(data->m_forks);
	free(data->philosophers);
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
	unsigned long long	i;

	i = get_current_time();
	while (1)
	{
		if ((get_current_time() - i) >= time)
			break ;
		usleep(50);
	}
}

int	is_even(int idx)
{
	if (idx % 2 == 0)
		return (1);
	return (0);
}
