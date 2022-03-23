/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldominiq <ldominiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 23:23:11 by ldominiq          #+#    #+#             */
/*   Updated: 2022/03/24 00:02:19 by ldominiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

unsigned long long get_current_time(void)
{
	struct timeval	current;

	gettimeofday(&current, NULL);
	return ((current.tv_sec * 1000) + (current.tv_usec / 1000));
}

void	print_status(t_data *data, char *msg, int i)
{
	pthread_mutex_lock(data->m_write);
	printf("%lld %d %s\n", get_current_time(), i + 1, msg);
	pthread_mutex_unlock(data->m_write);

}

void	wait_action(unsigned long long time)
{
	usleep(time * 1000);
}