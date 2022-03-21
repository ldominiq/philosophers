/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldominiq <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:15:05 by ldominiq          #+#    #+#             */
/*   Updated: 2021/10/18 12:00:05 by ldominiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	i = start;
	j = 0;
	if (start + len > ft_strlen(s))
		ptr = malloc(ft_strlen(s) + 1 * sizeof(char));
	else
		ptr = malloc(len + 1 * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (s[i] && j < len && start < ft_strlen(s))
		ptr[j++] = s[i++];
	ptr[j] = 0;
	return (ptr);
}
