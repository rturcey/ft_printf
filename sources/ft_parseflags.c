/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rturcey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:39:54 by rturcey           #+#    #+#             */
/*   Updated: 2019/10/31 16:39:59 by rturcey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void		ft_checkstar(t_list *elt, va_list ap)
{
	int		i;
	char	*buf;
	char	*itoa;

	i = 0;
	while (elt->flags[i])
	{
		if (elt->flags[i] == '*')
		{
			itoa = ft_itoa((long)(int)(va_arg(ap, int)));
			if (!(buf = malloc(sizeof(char) * (ft_strlen(elt->flags) + \
			ft_strlen(itoa) + 1))))
				return ;
			ft_removestar(elt, itoa, buf);
			i = 0;
			free(itoa);
			free(elt->flags);
			elt->flags = buf;
		}
		i++;
	}
	ft_parseflags(elt, ap);
}

void		ft_removestar(t_list *elt, char *itoa, char *buf)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while (elt->flags[++i] != '*')
		buf[i] = elt->flags[i];
	if (ft_isdigit(elt->flags[i + 1]) == 0)
	{
		while (itoa[j])
			buf[i++] = itoa[j++];
	}
	j = i - j + 1;
	while (elt->flags[j])
		buf[i++] = elt->flags[j++];
	buf[i] = '\0';
}

void		ft_parseflags(t_list *elt, va_list ap)
{
	int	i;

	i = 0;
	if (elt->flags[i] == '0')
	{
		elt->zerordash = '0';
		if (elt->flags[++i] == '0')
		{
			elt->width = ft_atoi(&elt->flags[i]);
			while (ft_isdigit(elt->flags[i]))
				i++;
		}
	}
	if (elt->flags[i] == '-')
	{
		elt->zerordash = '-';
		while (elt->flags[i] == '-')
			i++;
		while (elt->flags[i] == '0')
			i++;
	}
	ft_parseflags2(elt, ap, i);
}

void		ft_parseflags2(t_list *elt, va_list ap, int i)
{
	if (elt->flags[i] >= '1' && elt->flags[i] <= '9')
	{
		elt->width = ft_atoi(&elt->flags[i]);
		while (ft_isdigit(elt->flags[i]))
			i++;
	}
	if (elt->flags[i] == '.')
	{
		elt->precision = -1;
		if (ft_isdigit(elt->flags[++i]))
		{
			elt->precision = ft_atoi(&elt->flags[i]);
			while (ft_isdigit(elt->flags[i]))
				i++;
		}
		else if (elt->flags[i] == '-')
			elt->precision = -2;
	}
	ft_write_argts(elt, ap);
}
