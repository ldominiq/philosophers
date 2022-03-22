/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldominiq <ldominiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:31:32 by ldominiq          #+#    #+#             */
/*   Updated: 2022/03/22 12:31:47 by ldominiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_list	*init_list()
{
	t_list *list;
	t_philo *philo;

	list = malloc(sizeof(*list));
	philo = malloc(sizeof(*philo));
	if (list == NULL || philo == NULL)
		return (NULL);
	philo->pos = 1;
	philo->next = NULL;
	list->first = philo;
	return (list);
}

void	insert_philo(t_list *list, int pos)
{
	t_philo *new_philo;
	
	new_philo = malloc(sizeof(*new_philo));
	if (list != NULL && new_philo != NULL)
	{
		new_philo->pos = pos;
		new_philo->next = list->first;
		list->first = new_philo;
	}
}
