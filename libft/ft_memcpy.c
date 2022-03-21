/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldominiq <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 10:24:09 by ldominiq          #+#    #+#             */
/*   Updated: 2021/10/12 17:22:34 by ldominiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*strsrc;
	char	*strdst;
	size_t	i;

	strsrc = (char *)src;
	strdst = dst;
	i = -1;
	if (dst != NULL || src != NULL)
	{
		while (++i < n)
			strdst[i] = strsrc[i];
	}
	return (dst);
}
