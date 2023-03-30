/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 14:45:22 by rdragan           #+#    #+#             */
/*   Updated: 2023/03/26 15:22:31 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	k;
	size_t	j;
	size_t	slen;

	i = 0;
	while (i < dstsize && dst[i] != '\0')
		i++;
	slen = ft_strlen(src);
	if (dstsize == i)
		return (i + slen);
	j = 0;
	k = i;
	while (j < slen)
	{
		if (i < dstsize - 1)
		{
			dst[k] = src[j];
			k++;
		}
		i++;
		j++;
	}
	dst[k] = '\0';
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	len;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	len = s1_len + s2_len + 1;
	res = malloc(len * sizeof(char));
	if (res)
	{
		ft_memcpy(res, s1, s1_len + 1);
		ft_strlcat(res, s2, len);
	}
	else
		return ((void *)0);
	return (res);
}
