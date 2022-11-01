/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 09:40:43 by mtoia             #+#    #+#             */
/*   Updated: 2022/03/22 10:36:39 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

char			*ft_strchr(const char *str, int c);
void			*ft_memset(void *str, int c, int n);
void			ft_bzero(void *dst, int n);
int				ft_isalnum(int argument);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int x);
int				ft_isprint(int arg);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
int				ft_strlen(const char *str);
char			*ft_strrchr(const char *s, int c);
int				ft_tolower(int ch);
int				ft_toupper(int ch);
int				ft_atoi(const char *str);
void			*ft_calloc(size_t count, size_t size);
void			*ft_memchr(const void *s, int c, size_t num);
int				ft_memcmp(const void *ptr1, const void *ptr2, size_t num);
void			*ft_memcpy(void *dest, const void *source, size_t num);
void			*ft_memmove(void *desti, const void *source, size_t num);
char			*ft_strdup(char *src);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
int				ft_strlen(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *big, const char *lie, size_t len);
int				ft_tolower(int ch);
int				ft_toupper(int ch);
char			*ft_substr(char const *s, size_t start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int num);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void(*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void*));

#endif
