/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldominiq <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 10:47:08 by ldominiq          #+#    #+#             */
/*   Updated: 2021/10/12 17:22:55 by ldominiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*srcstr;
	char	*dststr;

	srcstr = (char *)src;
	dststr = dst;
	if (dst != NULL || src != NULL)
	{
		if (dststr < srcstr)
		{
			while (len--)
				*dststr++ = *srcstr++;
		}
		else
		{
			srcstr += (len - 1);
			dststr += (len - 1);
			while (len--)
				*dststr-- = *srcstr--;
		}
	}
	return (dst);
}
