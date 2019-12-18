/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_applyflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rturcey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:39:20 by rturcey           #+#    #+#             */
/*   Updated: 2019/10/31 16:39:24 by rturcey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void		ft_write_argts(t_list *elt, va_list ap)
{
	int	i;

	i = 0;
	elt->content = ft_putarg(elt->type, ap, elt);
	if (elt->zerordash != '-')
	{
		if (elt->precision > -2)
			ft_writeleft_p(elt);
		if (elt->width > -1)
			ft_writeleft_wd(elt);
	}
	else
	{
		if (elt->precision == -1)
			ft_writeright_p(elt);
		else if (elt->precision > -2)
			ft_writeleft_p(elt);
		if (elt->width > -1)
			ft_writeright_wd(elt);
	}
	if (ft_isnumber(elt->type))
		ft_parse_dash(elt);
	if (elt->type == 'p' && (elt->zerordash == '0' || elt->precision > -2))
		ft_parse_x(elt);
}

void		ft_parse_dash(t_list *elt)
{
	int	i;

	i = -1;
	while (elt->content[++i])
		if (elt->content[i] == '-' && i != 0)
		{
			if (elt->content[0] != ' ')
			{
				elt->content[i] = '0';
				elt->content[0] = '-';
				return ;
			}
			else
			{
				elt->content[i] = '0';
				while (elt->content[i] == '0')
					i--;
				if (i == 0)
					i--;
				elt->content[i + 1] = '-';
				return ;
			}
		}
}

void		ft_writeleft_p(t_list *elt)
{
	int		len;
	char	c;

	c = ' ';
	if (ft_isnumber(elt->type))
		c = '0';
	if (elt->type == 'p' && (elt->precision == -1 || elt->precision == 0) && \
	ft_memcmp(elt->content, "0x0", 4) == 0)
		elt->content[2] = '\0';
	len = (int)ft_strlen(elt->content);
	if (ft_isnumber(elt->type) && elt->content[0] == '-')
		len--;
	if (elt->type == 'p')
		len -= 2;
	if (ft_isnumber(elt->type) && len == 1 && (elt->precision < 1) \
		&& elt->content[0] == '0')
		elt->content[0] = '\0';
	if (elt->type == 'c' || (elt->type == 's' && elt->content[0] == '\0') || \
		(elt->type == 's' && len < elt->precision) || (len == elt->precision \
			|| (len > elt->precision && ft_isnumber(elt->type)) || \
			(elt->precision == -1 && elt->type != 's') || elt->type == '%'))
		return ;
	ft_writeleft_p2(elt, len, c);
}

void		ft_writeleft_p2(t_list *elt, int len, char c)
{
	char	*buf;
	int		i;

	if (elt->type == 's' && len > elt->precision \
		&& elt->precision == -1)
		elt->content[0] = '\0';
	else if (len > elt->precision)
		elt->content[elt->precision] = '\0';
	else
	{
		i = elt->precision - len;
		if (!(buf = malloc((i + 1) * sizeof(char))))
			return ;
		ft_memset(buf, c, i);
		buf[i] = '\0';
		elt->content = ft_strjoin(buf, elt->content);
	}
}

void		ft_writeleft_wd(t_list *elt)
{
	int		i;
	int		len;
	char	c;
	char	*buf;

	len = ft_strlen(elt->content);
	c = ' ';
	if (elt->zerordash == '0' && (elt->precision == -2 || elt->type == '%'))
		c = '0';
	if (elt->width <= len)
		return ;
	i = elt->width - len;
	if (!(buf = malloc((i + 1) * sizeof(char))))
		return ;
	ft_memset(buf, c, i);
	buf[i] = '\0';
	elt->content = ft_strjoin(buf, elt->content);
}
