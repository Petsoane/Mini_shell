/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 08:06:08 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/09/05 12:49:08 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include "get_next_line.h"
# include <stdarg.h>

typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;
void					*ft_memset(void *s, int c, size_t len);
void					*ft_memalloc(size_t size);
void					*ft_memalloc(size_t size);
char					*ft_strnew(size_t size);
void					ft_strclr(char *s);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s,
						char (*f)(unsigned int, char));
int						ft_strequ(char const *s1, char const *s2);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
char					*ft_strsub(char const *s,
						unsigned int start, size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strtrim(char const *s);
char					**ft_strsplit(char const *s, char c);
char					*ft_itoa(int n);
char					*ft_strtrimc(char const *s, char c);
void					ft_putchar(char c);
void					ft_putstr(char const *s);
void					ft_putendl(char const *s);
void					ft_putnbr(int n);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putnbr_fd(int n, int fd);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					*ft_memccpy(void *dst, const void *src,
						int c, size_t n);
void					*ft_memmove(void *dst, const void *src, size_t n);
void					*ft_memchr(const void *s, int c, size_t n);
void					ft_memdel(void **ptr);
void					ft_bzero(void *s, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
char					*ft_strstr(const char *n, const char *h);
char					*ft_strnstr(const char *n, const char *h, size_t len);
int						ft_atoi(const char *num);
int						ft_isalpha(int ch);
int						ft_isascii(int ch);
int						ft_isdigit(int ch);
int						ft_isalnum(int ch);
int						ft_isprint(int ch);
int						ft_tolower(int ch);
int						ft_toupper(int ch);
char					*ft_itoa(int n);
char					**ft_strsplit(char const *s, char c);
char					*ft_strdup(char const *s);
int						ft_strlen(char const *s);
char					*ft_strcpy(char *dst, char const *src);
char					*ft_strcat(char *dst, char const *src);
char					*ft_strncat(char *dst, char const *src, size_t n);
char					*ft_strncpy(char *dst, char const *src, size_t n);
size_t					ft_strlcat(char *dst, char const *src, size_t n);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
void					ft_strdel(char **s);
int						ft_wordlen(char const *ss, char c);
int						ft_wordcount(char const *s, char c);
void					ft_removeend(char **out, int i);
int						ft_digitlen(int num);
void					ft_baseconv(int input, int base);
char					*ft_strrev(char *s);
char					*ft_ifalloc(int isneg, int size);
int						ft_max_wordlen(const char *s, char c);
char					*ft_strtimc(const char *s, char c);
char					*ft_strndup(const char *s, size_t n);
int						print_form(const char *form, ...);
#endif
