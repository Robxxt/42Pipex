/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 09:16:12 by rdragan           #+#    #+#             */
/*   Updated: 2023/03/26 14:43:07 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
Returns the count of how many words are separated by 'c' in 's'
*/
static size_t	list_len(const char *s, char c)
{
	int		state;
	size_t	counter;
	size_t	i;

	counter = 0;
	state = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] != c && state == 0)
		{
			counter++;
			state = 1;
		}
		else if (s[i] == c && state == 1)
			state = 0;
	}
	return (counter);
}

static int	add_all_words_to_split(char **list, const char *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;

	index = -1;
	i = -1;
	j = -1;
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			list[++j] = ft_substr(s, index, (int)i - index);
			if (!list[j])
				return (0);
			index = -1;
		}
	}
	return (1);
}

/* Frees memory */
static void	*clear(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free (arr[i++]);
	free (arr);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	char	**split;
	size_t	split_len;

	if (!s)
		return (NULL);
	split_len = list_len(s, c);
	split = malloc((split_len + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	if (!add_all_words_to_split(split, s, c))
		return (clear(split));
	split[split_len] = NULL;
	return (split);
}
