/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rturcey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:39:40 by rturcey           #+#    #+#             */
/*   Updated: 2019/10/31 16:39:44 by rturcey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	ft_del(char *content, char *flags)
{
	if (content)
		free(content);
	content = NULL;
	if (flags)
		free(flags);
	flags = NULL;
}

t_list	*ft_lstnew_pf(void)
{
	t_list	*newelem;

	if (!(newelem = malloc(sizeof(t_list))))
		return (NULL);
	newelem->content = NULL;
	newelem->flags = NULL;
	newelem->type = '\0';
	newelem->zerordash = '\0';
	newelem->width = -1;
	newelem->precision = -2;
	newelem->len = 0;
	newelem->next = NULL;
	return (newelem);
}

void	ft_lstclear_pf(t_list **lst, void (*del)(char *, char *))
{
	t_list	*buf;
	t_list	*buf2;

	buf = NULL;
	buf2 = NULL;
	if (lst && *lst && del)
	{
		buf = *lst;
		while (buf)
		{
			buf2 = buf->next;
			(*del)(buf->content, buf->flags);
			free(buf);
			buf = NULL;
			buf = buf2;
		}
		*lst = NULL;
	}
}
