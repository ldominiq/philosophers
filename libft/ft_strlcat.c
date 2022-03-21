/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldominiq <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:08:47 by ldominiq          #+#    #+#             */
/*   Updated: 2021/10/13 17:59:10 by ldominiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	i;
	size_t	j;

	dstlen = ft_strlen(dst);
	i = dstlen;
	j = -1;
	if (!dstsize)
		return (ft_strlen(src));
	if (dstsize < i)
		i = dstsize;
	while (src[++j])
	{
		if (i < dstsize - 1)
			dst[i] = src[j];
		i++;
	}
	dst[i] = 0;
	return (i);
}
