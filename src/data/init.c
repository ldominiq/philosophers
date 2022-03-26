/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldominiq <ldominiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:43:14 by ldominiq          #+#    #+#             */
/*   Updated: 2022/03/26 14:27:14 by ldominiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_data(t_data *data, int argc, char *argv[])
{
	data->idx = 0;
	data->p_amount = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->nb_to_eat = ft_atoi(argv[5]);
	else
		data->nb_to_eat = -1;
	data->stop = 0;
}

void	*init_mutex(t_data *data)
{
	int	i;

	data->m_forks = malloc(sizeof(pthread_mutex_t *) * data->p_amount);
	if (!data->m_forks)
		return (NULL);
	i = -1;
	while (++i < data->p_amount)
	{
		data->m_forks[i] = malloc(sizeof(pthread_mutex_t));
		if (!data->m_forks[i])
			return (NULL);
	}
	i = -1;
	while (++i < data->p_amount)
		pthread_mutex_init(data->m_forks[i], NULL);
	data->m_write = malloc(sizeof(pthread_mutex_t));
	if (!data->m_write)
		return (NULL);
	pthread_mutex_init(data->m_write, NULL);
	return (data);
}

void	init_philo(t_data *data, int i)
{
	data->philosophers[i].idx = i + 1;
	data->philosophers[i].nb_meal = 0;
	data->philosophers[i].state = THINKING;
	data->philosophers[i].full = 0;
	data->philosophers[i].m_rfork = data->m_forks[i];
	if (i + 1 == data->p_amount)
		data->philosophers[i].m_lfork = data->m_forks[0];
	else
		data->philosophers[i].m_lfork = data->m_forks[i + 1];
}

void	*init_all_philo(t_data *data)
{
	int	i;

	data->philosophers = malloc(sizeof(t_philo) * data->p_amount);
	if (!data->philosophers)
		return (NULL);
	i = -1;
	while (++i < data->p_amount)
		init_philo(data, i);
	data->t_start = get_current_time();
	return (data);
}

void	*init_all(t_data *data, int argc, char *argv[])
{
	init_data(data, argc, argv);
	if (!init_mutex(data))
		return (NULL);
	if (!init_all_philo(data))
		return (NULL);
	return (data);
}
