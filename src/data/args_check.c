/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldominiq <ldominiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:44:16 by ldominiq          #+#    #+#             */
/*   Updated: 2022/03/22 19:21:45 by ldominiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_args(int argc, char *argv[])
{
	int	tmp;

	if (argc != 5 && argc != 6)
		return (1);
	tmp = ft_atoi(argv[1]);
	if (tmp <= 0)
		return (1);
	tmp = ft_atoi(argv[2]);
	if (tmp <= 0)
		return (1);
	tmp = ft_atoi(argv[3]);
	if (tmp <= 0)
		return (1);
	tmp = ft_atoi(argv[4]);
	if (tmp <= 0)
		return (1);
	if (argc == 6)
	{
		tmp = ft_atoi(argv[5]);
		if (tmp < 0)
			return (1);
	}
	return (0);
}
