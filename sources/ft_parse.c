/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rturcey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 14:58:49 by rturcey           #+#    #+#             */
/*   Updated: 2019/11/03 14:58:51 by rturcey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	ft_backslashzero(char *f)
{
	int	i;

	i = 0;
	while (i < g_nb)
	{
		if (f[i] == -11)
			f[i] = '\0';
		i++;
	}
}

int		ft_parse(char *f, va_list ap, t_list *elt)
{
	int		i;

	i = 0;
	if (f[0] && !ft_isconv(f[0]) && !ft_isdigit(f[0]) && f[0] != '-' \
		&& f[0] != '*' && f[0] != '.')
	{
		elt->content = ft_strdup(&f[0]);
		g_pos++;
		return (0);
	}
	while (ft_isconv(f[i]) == 0)
		i++;
	elt->type = f[i];
	if (i == 0)
	{
		elt->content = ft_putarg(elt->type, ap, elt);
		g_pos++;
	}
	else
		ft_parse_wflags(f, ap, elt, i);
	return (0);
}

void	ft_parse_wflags(char *f, va_list ap, t_list *elt, int i)
{
	char	*flags;

	if (!(flags = malloc(sizeof(char) * (i + 1))))
		return ;
	ft_strlcpy(flags, f, i + 1);
	elt->flags = ft_strdup(flags);
	g_pos += ft_strlen(flags) + 1;
	free(flags);
	ft_checkstar(elt, ap);
}
