/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldominiq <ldominiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:32:50 by ldominiq          #+#    #+#             */
/*   Updated: 2022/03/22 12:33:57 by ldominiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	remove_philo(t_list *list)
{
	t_philo *philo;

	if (list != NULL)
	{
		if (list->first != NULL)
		{
			philo = list->first;
			list->first = list->first->next;
			free(philo);
		}
	}
}
