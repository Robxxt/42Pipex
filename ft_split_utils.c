/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 14:39:55 by rdragan           #+#    #+#             */
/*   Updated: 2023/03/26 14:41:59 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*(s++))
		len++;
	return (len);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*ldst;
	char	*lsrc;
	size_t	i;

	if (!src && !dst)
		return (NULL);
	ldst = (char *)dst;
	lsrc = (char *)src;
	i = -1;
	while (++i < n)
		ldst[i] = lsrc[i];
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ldst;
	unsigned char	*lsrc;

	if ((!dst && !src))
		return (NULL);
	ldst = (unsigned char *)dst;
	lsrc = (unsigned char *)src;
	if (ldst > lsrc)
	{
		while (len--)
			ldst[len] = lsrc[len];
	}
	else
		ft_memcpy(ldst, lsrc, len);
	return (ldst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	slen;
	int		max;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	max = slen - start;
	if (slen < start)
		len = 0;
	if ((size_t)max > len)
		max = len;
	res = malloc((max + 1) * sizeof(char));
	if (!res)
		return (0);
	ft_memmove(res, s + start, max);
	res[max] = '\0';
	return (res);
}
