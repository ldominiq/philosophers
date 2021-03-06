/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_starter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldominiq <ldominiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:53:01 by ldominiq          #+#    #+#             */
/*   Updated: 2022/03/30 18:52:03 by ldominiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*start_threads(t_data *data)
{
	int			i;

	i = -1;
	while (++i < data->p_amount)
	{
		data->philosophers[i].philo = (pthread_t *)malloc(sizeof(pthread_t));
		if (!data->philosophers[i].philo)
			return (NULL);
	}
	data->grim_reaper = (pthread_t *)malloc(sizeof(pthread_t));
	if (!data->grim_reaper)
		return (NULL);
	i = -1;
	while (++i < data->p_amount)
		pthread_create(data->philosophers[i].philo, NULL, philo_routine, data);
	pthread_create(data->grim_reaper, NULL, grim_reaper_routine, data);
	i = -1;
	if (!data->stop)
		pthread_join(*data->grim_reaper, NULL);
	while (++i < data->p_amount && !data->stop)
		pthread_join(*data->philosophers[i].philo, NULL);
	return (0);
}
