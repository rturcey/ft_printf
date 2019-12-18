/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rturcey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 15:10:02 by rturcey           #+#    #+#             */
/*   Updated: 2019/10/31 16:40:43 by rturcey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# define BUFF_SIZE 32

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

extern int		g_nb;
extern int		g_pos;

typedef	struct	s_list
{
	struct s_list	*next;
	char			*content;
	char			*flags;
	char			zerordash;
	int				width;
	int				precision;
	char			type;
	int				len;
}				t_list;

size_t			ft_strlen(const char *s);
int				ft_atoi(const char *str);
int				ft_isdigit(int c);
char			*ft_intarr(char *result, long i, long j, long k);
char			*ft_itoa(long n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memset(void *b, int c, size_t len);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char *s1, char *s2);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
int				ft_parse_format(char *f, t_list *elt, va_list ap);
char			*ft_strjoinfinal(char *s1, char *s2, int lev);
void			ft_parse_wflags(char *f, va_list ap, t_list *elt, int i);
void			ft_backslashzero(char *f);
void			*ft_memchr(const void *s, int c, size_t n);
void			ft_parse_x(t_list *elt);
void			ft_del(char *content, char *flags);
t_list			*ft_lstnew_pf();
void			ft_lstclear_pf(t_list **lst, void (*del)(char *, char *));
char			*ft_putarg(char c, va_list ap, t_list *elt);
char			*ft_printarg_hexp(char c, va_list ap);
int				ft_parse(char *f, va_list ap, t_list *elt);
char			*ft_finalstr(t_list *start, char *f);
char			*ft_strprintf(const char *format, va_list ap);
int				ft_printf(const char *format, ...);
void			ft_parseflags(t_list *elt, va_list ap);
void			ft_parseflags2(t_list *elt, va_list ap, int i);
void			ft_parse_dash(t_list *elt);
void			ft_write_argts(t_list *elt, va_list ap);
void			ft_writeleft_p(t_list *elt);
void			ft_writeleft_p2(t_list *elt, int len, char c);
void			ft_writeleft_wd(t_list *elt);
void			ft_writeright_p(t_list *elt);
void			ft_writeright_p2(t_list *elt, int len);
void			ft_writeright_wd(t_list *elt);
void			ft_checkstar(t_list *elt, va_list ap);
void			ft_removestar(t_list *elt, char *itoa, char *buf);
int				ft_isnumber(char c);
int				ft_isconv(char c);
char			*ft_putstr_f(char *str);
char			*ft_printchar(char c);
char			*ft_printstr(char *str);
char			*ft_intarrhex(char *result, unsigned long long i,\
					unsigned long long n, char *hexa);
char			*ft_ulltoahex(unsigned long long n, char *hexa);
char			*ft_printhex(unsigned long long n, char c);

#endif
