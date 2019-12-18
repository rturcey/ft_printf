/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rturcey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:40:08 by rturcey           #+#    #+#             */
/*   Updated: 2019/10/31 16:40:11 by rturcey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

char	*ft_putarg(char c, va_list ap, t_list *elt)
{
	char	*str;

	str = NULL;
	if (c == 'c')
	{
		str = ft_printchar((char)va_arg(ap, int));
		if (str[0] == '\0')
		{
			elt->len = 1;
			str[0] = -11;
		}
	}
	else if (c == '%')
		str = ft_strdup("%");
	else if (c == 's')
		str = ft_printstr(ft_strdup((char *)va_arg(ap, char *)));
	else if (c == 'p' || c == 'x' || c == 'X')
		str = ft_printarg_hexp(c, ap);
	else if (c == 'd' || c == 'i')
		str = ft_printstr(ft_itoa((long)(int)va_arg(ap, int)));
	else if (c == 'u')
		str = ft_printstr(ft_itoa((long)(unsigned int)\
			va_arg(ap, unsigned int)));
	return (str);
}

int		ft_isnumber(char c)
{
	if (c == 'd' || c == 'i' || c == 'p' || c == 'x' || c == 'X' || c == 'u')
		return (1);
	return (0);
}

int		ft_isconv(char c)
{
	if (ft_isnumber(c) == 1 || c == 's' || c == 'c' || c == 'p' || c == '%')
		return (1);
	return (0);
}

char	*ft_putstr_f(char *str)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	if (str == NULL)
		return (NULL);
	while (str[i] && (str[i] != '%' || (str[i] == '%' && str[i + 1] == '&')))
	{
		if (str[i++] == '%')
			i++;
	}
	if (!(s = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (str[i] && (str[i] != '%' || (str[i] == '%' && str[i + 1] == '&')))
	{
		if (str[i] == '%')
			i++;
		s[j++] = str[i++];
	}
	s[j] = '\0';
	g_pos += ft_strlen(s);
	return (s);
}

char	*ft_printarg_hexp(char c, va_list ap)
{
	char	*str;
	char	*s;
	int		i;
	int		j;

	i = 2;
	j = 0;
	if (c == 'p')
	{
		s = ft_printhex(((unsigned long long)va_arg(ap, void *)), 'x');
		if (!(str = malloc((ft_strlen(s) + 3) * sizeof(char))))
			return (NULL);
		str[0] = '0';
		str[1] = 'x';
		while (s[j])
			str[i++] = s[j++];
		str[i] = '\0';
		free(s);
		return (str);
	}
	else
	{
		str = ft_printhex((unsigned long long)va_arg(ap, unsigned int), c);
		return (str);
	}
}
