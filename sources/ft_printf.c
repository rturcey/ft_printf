/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfbis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rturcey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:40:17 by rturcey           #+#    #+#             */
/*   Updated: 2019/10/31 16:40:19 by rturcey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	g_nb = 0;
int	g_pos = 0;

char		*ft_finalstr(t_list *start, char *f)
{
	int		i;

	i = 0;
	if (start->content == NULL)
		return (NULL);
	g_nb += ft_strlen(start->content);
	if (start->len == 1)
		f = ft_strjoinfinal(f, start->content, start->len);
	else
		f = ft_strdup(start->content);
	if (!start->next)
		return (f);
	start = start->next;
	while (start->content)
	{
		i = 0;
		g_nb += ft_strlen(start->content);
		f = ft_strjoinfinal(f, start->content, start->len);
		start = start->next;
	}
	return (f);
}

int			ft_parse_format(char *f, t_list *elt, va_list ap)
{
	while (g_pos < (int)ft_strlen(f))
	{
		if (f[g_pos] != '%')
			elt->content = ft_putstr_f(&f[g_pos]);
		else
		{
			if (ft_parse(&f[++g_pos], ap, elt) == -1)
				return (-1);
		}
		elt->next = ft_lstnew_pf();
		elt = elt->next;
	}
	return (0);
}

char		*ft_strprintf(const char *format, va_list ap)
{
	char	*f;
	t_list	*elt;
	t_list	*start;
	t_list	*begin;

	g_nb = 0;
	g_pos = 0;
	if (format == NULL)
		return (NULL);
	if (!(f = ft_strdup(format)))
		return (NULL);
	elt = ft_lstnew_pf();
	start = elt;
	begin = elt;
	ft_parse_format(f, start, ap);
	free(f);
	f = NULL;
	if (!(f = ft_finalstr(begin, f)))
	{
		ft_lstclear_pf(&elt, &ft_del);
		return (NULL);
	}
	ft_lstclear_pf(&elt, &ft_del);
	g_pos = 0;
	return (f);
}

int			ft_printf(const char *format, ...)
{
	char	*result;
	va_list	ap;
	int		i;

	i = 0;
	va_start(ap, format);
	if (!(result = ft_strprintf(format, ap)))
	{
		va_end(ap);
		return (-1);
	}
	write(1, result, g_nb);
	free(result);
	va_end(ap);
	return (g_nb);
}
