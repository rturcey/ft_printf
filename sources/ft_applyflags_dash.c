/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_applyflags_dash.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rturcey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:39:29 by rturcey           #+#    #+#             */
/*   Updated: 2019/10/31 16:39:31 by rturcey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void		ft_parse_x(t_list *elt)
{
	int		i;

	i = 0;
	if (elt->content[1] != 'x' && elt->content[0] != ' ')
	{
		while (elt->content[i] != 'x')
			i++;
		if (elt->content[i])
		{
			elt->content[i] = '0';
			elt->content[1] = 'x';
		}
	}
}

void		ft_writeright_p(t_list *elt)
{
	int	len;

	if (elt->type == 'p' && elt->precision == -1 && \
		!ft_memcmp(elt->content, "0x0", 4))
		elt->content[2] = '\0';
	if (elt->type == 's' && (elt->precision == -1 || elt->content[0] == '\0'))
	{
		elt->content[0] = '\0';
		return ;
	}
	len = (int)ft_strlen(elt->content);
	if (ft_isnumber(elt->type) && len == 1 && (elt->precision < 1))
		elt->content[0] = '\0';
	if (elt->type == 'c' || elt->type == 'p' || (elt->type == 's' && len < \
		elt->precision) || elt->precision == -1 || (len == elt->precision || \
		(len > elt->precision && ft_isnumber(elt->type))))
		return ;
	if (ft_isnumber(elt->type) && elt->content[0] == '-')
		len--;
	if (len > elt->precision)
		elt->content[elt->precision] = '\0';
	else
		ft_writeright_p2(elt, len);
}

void		ft_writeright_p2(t_list *elt, int len)
{
	int		i;
	char	*buf;

	i = elt->precision - len;
	if (!(buf = malloc((i + 1) * sizeof(char))))
		return ;
	ft_memset(buf, ' ', i);
	buf[i] = '\0';
	elt->content = ft_strjoin(elt->content, buf);
}

void		ft_writeright_wd(t_list *elt)
{
	int		i;
	int		len;
	char	c;
	char	*buf;

	len = ft_strlen(elt->content);
	c = ' ';
	if (elt->width <= len)
		return ;
	i = elt->width - len;
	if (!(buf = malloc((i + 1) * sizeof(char))))
		return ;
	ft_memset(buf, ' ', i);
	buf[i] = '\0';
	if (elt->type == c && elt->len == 1)
		elt->len += len + i;
	elt->content = ft_strjoin(elt->content, buf);
}
