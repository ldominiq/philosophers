/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_starter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldominiq <ldominiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:53:01 by ldominiq          #+#    #+#             */
/*   Updated: 2022/03/22 19:19:36 by ldominiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*start_threads(t_data *data)
{
	pthread_t	*threads;
	pthread_t	*grim_reaper;
	int			i;

	i = -1;
	threads = malloc(sizeof(pthread_t) * data->p_amount);
	if (!threads)
		return (NULL);
	while (++i < data->p_amount)
		pthread_create(threads + i, NULL, philo_routine, data);
	grim_reaper = malloc(sizeof(pthread_t));
	if (!grim_reaper)
		return (NULL);
	pthread_create(grim_reaper, NULL, grim_reaper_routine, data);
	i = -1;
	while (++i < data->p_amount)
		pthread_join(threads[i], NULL);
	return (0);
}
