/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfutils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rturcey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 14:59:23 by rturcey           #+#    #+#             */
/*   Updated: 2019/11/03 14:59:27 by rturcey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	i;

	i = 0;
	if (s1 == NULL)
		return (NULL);
	while (s1[i])
		i++;
	if (!(s2 = malloc((i + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t length;

	i = 0;
	length = 0;
	while (src[length])
		length++;
	if (dstsize == 0)
		return (length);
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (length);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	size_t	i;
	size_t	j;
	size_t	len;

	s3 = NULL;
	i = 0;
	j = 0;
	len = 0;
	if (!(s3 = malloc((ft_strlen(s1) + ft_strlen(s2) + 2) \
		* sizeof(char))))
		return (s3);
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		s3[i++] = s2[j++];
	s3[i] = '\0';
	free(s1);
	free(s2);
	return (s3);
}

char	*ft_strjoinfinal(char *s1, char *s2, int lev)
{
	char	*s3;
	int		i;
	size_t	j;
	int		len;

	s3 = NULL;
	i = -1;
	j = 0;
	len = (int)ft_strlen(s2);
	if (!(s3 = malloc((g_nb + len + 2) * sizeof(char))))
		return (s3);
	while (++i < g_nb - len && s1 != NULL)
		s3[i] = s1[i];
	while (s2[j] != '\0')
		s3[i++] = s2[j++];
	s3[i] = '\0';
	free(s1);
	s1 = NULL;
	if (lev == 1)
		ft_backslashzero(s3);
	return (s3);
}
