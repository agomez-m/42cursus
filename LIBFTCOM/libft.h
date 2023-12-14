/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:32:33 by agomez-m          #+#    #+#             */
/*   Updated: 2023/12/14 15:35:50 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdarg.h>
# include <fcntl.h>
# define BUFF_SIZE 10
# define MAX(A, B) (A > B ? A : B)
# define MIN(A, B) (A > B ? B : A)

typedef struct s_list1
{
	void			*content;
	struct s_list1	*next;
}				t_list1;

typedef struct s_arr
{
	int				fd;
	char			*rest;
	struct s_arr	*next;
}				t_arr;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
int		ft_toupper(int c);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);

t_list1	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list1 **lst, t_list1 *new);
int		ft_lstsize(t_list1 *lst);
t_list1	*ft_lstlast(t_list1 *lst);
void	ft_lstadd_back(t_list1 **lst, t_list1 *new);
void	ft_lstdelone(t_list1 *lst, void (*del)(void *));
void	ft_lstclear(t_list1 **lst, void (*del)(void *));
void	ft_lstiter(t_list1 *lst, void (*f)(void *));
t_list1	*ft_lstmap(t_list1 *lst, void *(*f)(void *), void (*del)(void *));

int		ft_print_char(int c);
int		ft_print_str(char *str);
int		ft_print_digit(long n, int base);
int		ft_print_digitx(long n, int base);
int		ft_print_u(unsigned int n);
int		ft_putpoi(unsigned long long ptr);
int		ft_printf(const char *format, ...);
int		get_next_line(const int fd, char **line);



char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strjoin2(char const *s1, char const *s2);
char	*ft_strchr2(const char *s, int c);
char	*ft_strcpy(char *dst, const char *src);
void	ft_strclr(char *s);
void	ft_strdel(char **as);
char	*ft_strncat(char *dst, const char *src, size_t n);
char	*ft_strcat(char *restrict str1, const char *restrict str2);
char	*ft_strnew(size_t size);
size_t	ft_strlen2(char const *s);

#endif
