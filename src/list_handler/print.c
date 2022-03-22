/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldominiq <ldominiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:33:34 by ldominiq          #+#    #+#             */
/*   Updated: 2022/03/22 12:33:52 by ldominiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_list(t_list *list)
{
	t_philo *current;
	if (list != NULL)
	{
		current = list->first;
		while (current != NULL)
		{
			printf("%d -> ", current->pos);
			current = current->next;
		}
	}
	printf("NULL\n");
}
