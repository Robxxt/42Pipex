/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotation_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:42:11 by rdragan           #+#    #+#             */
/*   Updated: 2023/03/29 19:10:18 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	first_quotation_mark(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\'' || s[i] == '"')
			return (i);
		i++;
	}
	return (-1);
}

int	l_q_mark(char *s)
{
	int	i;

	i = ft_strlen(s);
	while (i > 0)
	{
		if (s[i] == '\'' || s[i] == '"')
			return (i);
		i--;
	}
	return (i);
}

int	first_word(char *s)
{
	int	i;

	i = 0;
	if (s[i] == ' ')
		return (1);
	while (s[i])
	{
		if (s[i] == ' ')
			return (i - 1);
		i++;
	}
	return (i - 1);
}
