/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldominiq <ldominiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:41:57 by ldominiq          #+#    #+#             */
/*   Updated: 2022/03/25 22:25:21 by ldominiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (check_args(argc, argv))
		return (1);
	if (!init_all(&data, argc, argv))
		return (2);
	if (!start_threads(&data))
		return (3);
	return (0);
}
