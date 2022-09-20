/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:36:29 by iostancu          #+#    #+#             */
/*   Updated: 2022/02/19 19:01:34 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/**
 * @return True if 'c' is alphanumeric.
 */
int		ft_isalpha(int c);
/**
 * @return True if 'c' is digit(0-9).
 */
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int 	ft_isspace(int c);
int		ft_isascii(int c);
/**
 * @return True if 'c' is printable.
 */
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
/**
 * Fills the first n bytes of the memory area pointed to by 'b' with 
 * the constant byte c.
 * 
 * @param[in] b Pointer to memory to fill.
 * @param[in] c Byte to fill with.
 * @param[in] len Number of bytes to fill.
 */
void	*ft_memset(void *b, int c, size_t len);
/**
 * Erases the data in the n bytes of the memory starting at the location 
 * pointed to by 's', by writing zeros (bytes containing '\0') to that area.
 * 
 * @param[in] s Pointer to memory where to fill with zeros.
 * @param[in] n Number of bytes.
 */
void	ft_bzero(void *s, size_t n);
/**
 * Copies n bytes from memory area src to memory area dest.
 * 
 * @param[in] dest Where the copy will be saved.
 * @param[in] src Source to be copied.
 * @param[in] n Number of bytes.
 *
 * @return Pointer to dest
 */
void	*ft_memcpy(void *dest, const void *src, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
int 	ft_atoi_base(const char *str, int base);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
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
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
