/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:32:59 by alaparic          #+#    #+#             */
/*   Updated: 2023/08/11 12:52:31 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>

//	Bonus t_list type
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

// define default value for GNL buffer
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

//	Libc Functions
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
int		ft_str_isdigit(char *str);

//	malloc Functions
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);

//	Additional Functions
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

//	Bonus Functions
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// printf functions
int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putstr(char *c);
int		ft_putnbr(int n);
int		ft_puthex(unsigned int n, int flag);
int		ft_putunsig(unsigned int n);
int		ft_putpoint(unsigned long n);

// GNL functions
char	*gnl_strjoin(char const *s1, char const *s2);
char	*gnl_strchr(const char *s, int c);
void	*gnl_memchr(const void *s, int c, size_t n);
char	*get_next_line(int fd);

// math functions
int		ft_abs(long n);

// extra
void	free_matrix(char **matrix);
void	ft_printmatrix(char **matrix);
char	*ft_fstrjoin(char *s1, char *s2);
void	ft_lstadd_new(t_list **list, void *context);
int		ft_strcmp(const char *s1, const char *s2);
char	**ft_sort_matrix(char **mat);
int		ft_get_matrix_size(char **env);

#endif