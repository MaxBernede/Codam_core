/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:05:51 by jmeruma           #+#    #+#             */
/*   Updated: 2023/04/24 15:18:56 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int			ft_tolower(int c);
int			ft_toupper(int c);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isspace(int c);
int			ft_isprint(int c);
int			ft_lstsize(t_list *lst);
int			ft_strlen(const char *s);
int			ft_atoi(const char *str);
int			ft_2d_arrlen(char **p_arr);
int			ft_atoi_overflow(const char *str, int *numb);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			put_basetoa(const char *baseset, int base, unsigned long nb);
long		ft_atol(const char *nb);
char		*ft_itoa(int n);
char		*ft_strdup(const char *s1);
char		*ft_strchr(const char *s, int c);
char		**ft_split(char const *s, char c);
char		*ft_strrchr(const char *s, int c);
char		**ft_2d_add(char *arr[], char *str);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_strjoin_free(char *s1, char const *s2);
char		*ft_string_injection(char *line, int index, char *str);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_basetoa(const char *baseset, int base, unsigned long nb);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
void		ft_2dfree(char **p_arr);
void		ft_putnbr_fd(int n, int fd);
void		*ft_bzero(void *s, size_t n);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		*ft_calloc(size_t count, size_t size);
void		*ft_memset(void *b, int c, size_t len);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		*ft_memchr(const void *s, int c, size_t n);
void		ft_lstiter(t_list *lst, void (*f)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
size_t		ft_strlcat(char *dst, char *src, size_t dstsize);
size_t		ft_strlcpy(char *dst, char *src, size_t dstsize);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstnew(void *content);
t_list		*ft_lstmap(t_list *lst, void *(f)(void *), void (*del)(void *));
uint32_t	ft_atohex(const char *hex);

int			ft_printf(char const *format, ...);
char		*get_next_line(int fd);

#endif
