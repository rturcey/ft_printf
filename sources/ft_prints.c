/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printsbis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rturcey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:40:25 by rturcey           #+#    #+#             */
/*   Updated: 2019/10/31 16:40:27 by rturcey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

char	*ft_printchar(char c)
{
	char	*str;

	if (!(str = malloc(sizeof(char) * 2)))
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

char	*ft_printstr(char *str)
{
	char	*s;

	if (str == NULL)
		return (ft_strdup("(null)"));
	else
	{
		s = ft_strdup(str);
		free(str);
		return (s);
	}
}

char	*ft_intarrhex(char *result, unsigned long long i, \
	unsigned long long n, char *hexa)
{
	int	j;

	j = 0;
	while (i >= 1)
	{
		result[j] = hexa[((n / i) % 16)];
		i /= 16;
		j++;
	}
	result[j] = '\0';
	return (result);
}

char	*ft_ulltoahex(unsigned long long n, char *hexa)
{
	unsigned long long	i;
	unsigned long long	j;
	char				*result;

	i = 1;
	j = 0;
	while (n / i >= 16)
	{
		j++;
		i *= 16;
	}
	if (!(result = malloc((j + 2) * sizeof(char))))
		return (NULL);
	j = 0;
	return (ft_intarrhex(result, i, n, hexa));
}

char	*ft_printhex(unsigned long long n, char c)
{
	char		*hexa;
	char		*result;

	if (n == 0)
		return (ft_strdup("0"));
	if (c == 'x')
		hexa = "0123456789abcdef";
	else
		hexa = "0123456789ABCDEF";
	result = ft_ulltoahex(n, hexa);
	return (result);
}
