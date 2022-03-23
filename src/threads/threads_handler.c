/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldominiq <ldominiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:04:49 by ldominiq          #+#    #+#             */
/*   Updated: 2022/03/23 17:26:47 by ldominiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

//TODO: Statuses handling (EATING/SLEEPING/THINKING...)
void	*philo_routine(void *arg)
{
	t_data *data;

	data = arg;
	printf("%d\n", data->philosophers->state);

	return (NULL);
}

//TODO: Handling of dead philosopher
void	*grim_reaper_routine(void *arg)
{
	(void) arg;

	return (NULL);
}
