/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfutils_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rturcey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 14:59:02 by rturcey           #+#    #+#             */
/*   Updated: 2019/11/03 14:59:04 by rturcey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		ft_atoi(const char *str)
{
	int	i;
	int number;
	int	sign;

	i = 0;
	number = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + str[i] - '0';
		i++;
	}
	return (sign * number);
}

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	*ft_intarr(char *result, long i, long j, long k)
{
	if (j == 1)
		result[0] = '-';
	while (i >= 1)
	{
		result[j] = ((k / i) % 10) + '0';
		i /= 10;
		j++;
	}
	result[j] = '\0';
	return (result);
}

char	*ft_itoa(long n)
{
	long	i;
	long	j;
	long	k;
	char	*result;

	i = 1;
	j = 0;
	k = n;
	if (n < 0)
		k = -k;
	while (k / i >= 10)
	{
		j++;
		i *= 10;
	}
	if (n == 0)
		j = -1;
	if (!(result = malloc((j + 3) * sizeof(char))))
		return (NULL);
	j = 0;
	if (n < 0)
		return (ft_intarr(result, i, 1, k));
	else
		return (ft_intarr(result, i, 0, k));
}
