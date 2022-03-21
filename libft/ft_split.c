/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldominiq <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:57:29 by ldominiq          #+#    #+#             */
/*   Updated: 2021/10/18 12:08:55 by ldominiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *str, char c)
{
	int	i;
	int	count;
	int	flag;

	flag = 0;
	i = -1;
	count = 0;
	while (str[++i])
	{
		if (str[i] != c && flag == 0)
		{
			flag = 1;
			count++;
		}
		else if (str[i] == c)
			flag = 0;
	}
	return (count);
}

static char	*word_construct(char const *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	while (start < end)
		word[i++] = str[start++];
	word[i] = 0;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	int		j;
	char	**words;
	int		start;

	if (!s)
		return (NULL);
	i = -1;
	j = 0;
	start = -1;
	words = malloc((word_count(s, c) + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			words[j++] = word_construct(s, start, i);
			start = -1;
		}
	}
	words[j] = 0;
	return (words);
}
