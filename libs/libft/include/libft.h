/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 10:18:55 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/07 16:27:25 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef __APPLE__
#  include <stdint.h>
# endif

# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

# define BUFF_SIZE 4096
# define DSINT_MAX 1000000000000000000l

typedef struct	s_stock
{
	char	stock[BUFF_SIZE + 1];
	int		fd;
}				t_stock;

typedef enum	e_dspe
{
	DS_NORMAL = 0,
	DS_SUB,
	DS_ZERO,
	DS_INF,
	DS_NAN
}				t_dspe;

typedef enum	e_dconv_mode
{
	DCONV_E,
	DCONV_F,
	DCONV_G
}				t_dconv_mode;

typedef struct	s_dcomp
{
	int				sign;
	unsigned int	exp;
	unsigned long	man;
	t_dspe			spe;
	int				islong;
	int				exp10;
}				t_dcomp;

typedef struct	s_sint
{
	uintmax_t	*tab;
	size_t		size;
}				t_sint;

typedef struct	s_dsint
{
	uintmax_t	*tab;
	size_t		size;
}				t_dsint;

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

void			*ft_memset(void *b, int c, size_t len);
void			*ft_memrset(void *b, int c, size_t len);
void			*ft_intset(void *b, int c, size_t len);
void			*ft_lintset(void *b, long int c, size_t len);
void			*ft_floatset(void *b, float c, size_t len);
void			ft_intcpy(int *b, int c);
void			ft_bzero(void *s, size_t n);
int				ft_ismemzero(void *mem, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memdeplace(void *dst, const void *src,
								int fill, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *s);
size_t			ft_wstrlen(const wchar_t *s);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack,
							const char *needle, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
uintmax_t		ft_atoui(const char *str);
int				ft_wctoi(wchar_t wch, int *size);
char			*ft_wstrtostr(const wchar_t *wstr, int size, int *out_size);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
void			ft_strtoupper(char *str);
int				ft_tolower(int c);

void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
char			*ft_strnew_fill(size_t size, char c);
void			ft_strdel(char **as);
void			ft_tabdel(char ***tab);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char*));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strnjoin(char const *s1, char const *s2, size_t n);
int				ft_append_free(char **s1, char **s2);
char			*ft_strtrim(char const *s);
char			*ft_strnowhitespace(char const *str);
void			ft_strcpynowhitespace(char *dst, char const *src);
size_t			ft_countnowhitespace(char const *str);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(intmax_t n);
char			*ft_itoa_light(char *str, size_t base, intmax_t n);
char			*ft_uitoa(uintmax_t n);
char			*ft_uitoa_light(char *str, size_t base, uintmax_t n);
char			*ft_itoa_bin_oct_hex(uintmax_t n, size_t base);
t_dcomp			ft_double_struct(double d, int hexa);
t_dcomp			ft_ldouble_struct(long double d, int hexa);
char			*ft_dtoa_hex(t_dcomp d, int prec, int alter);
char			*ft_dtoa_hex_ev(t_dcomp d, int prec, int alter);
int				ft_dtoa_hex_round(t_dcomp *d, int prec, int pow);
char			*ft_dtoa_hex_addprecision(char *buf, int prec);
char			*ft_dtoa_dec(t_dcomp d, t_dconv_mode mode,
								int prec, int alter);
int				ft_dtoa_dsint_calc(t_dcomp *d, t_dsint *fraction);
char			*ft_dtoa_format_e(char *buf, t_dcomp d, int prec, int alter);
char			*ft_dtoa_format_f(char *buf, t_dcomp d, int prec, int alter);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);

t_list			*ft_lstnew(void const *content, size_t content_size);
t_list			*ft_lstnewref(void *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel_n(t_list **lst, int n, void (*del)(void*, size_t));
int				ft_lstadd(t_list **alst, t_list *new);
int				ft_lstradd(t_list **alst, t_list *new);
t_list			*ft_lstat(t_list *lst, size_t n);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstmap_param(t_list *lst, void *param,
				t_list *(*f)(t_list *elem, void *param));
void			*ft_lst_to_array(t_list *lst);
void			ft_lstrev(t_list **lst);

void			*ft_memrcpy(void *dst, const void *src, size_t n);
size_t			ft_strspn(const char *s, const char *charset);
size_t			ft_strcspn(const char *s, const char *charset);
int				ft_isupper(int c);
int				ft_islower(int c);
int				ft_iswhitespace(int c);
int				ft_skipwhitespace(const char *str);
char			*ft_strndup(const char *s1, size_t n);
void			ft_putmem(void const *s, size_t len);
void			ft_putmemendl(void const *s, size_t len);
void			ft_putmem_fd(void const *s, size_t len, int fd);
void			ft_putmemendl_fd(void const *s, size_t len, int fd);
size_t			ft_lstcount(t_list *lst);
t_list			*ft_strsplit_lst(char const *s, char c);

void			ft_swap(int *a, int *b);
int				ft_max(int a, int b);
int				ft_min(int a, int b);
float			ft_fmax(float a, float b);
float			ft_fmin(float a, float b);
float			ft_fclamp(float min, float max, float val);

int				create_dsint(t_dsint *a, size_t size);
void			set_dsint_val(t_dsint a, uintmax_t val);
void			set_dsint_val_all(t_dsint a, uintmax_t val);
void			destroy_dsint(t_dsint a);
void			print_dsint(t_dsint a);
void			lshift_dsint(t_dsint a, unsigned int val);
void			rshift_dsint(t_dsint a, unsigned int val);
void			inc_dsint(t_dsint a);
void			add_dsint(t_dsint a, t_dsint b);
void			sub_dsint(t_dsint a, t_dsint b);
void			mul_dsint(t_dsint a, uintmax_t val);
void			div_dsint(t_dsint a, uintmax_t val);
int				get_pow(intmax_t a, int base);
int				get_pow10_dsint(t_dsint a);
int				set_dsint_precision(t_dsint a, int *exp10,
									int prec, t_dconv_mode mode);
void			dsint_to_alpha_light(char *str, t_dsint n);
char			*dsint_to_alpha(t_dsint n);

int				get_next_line(const int fd, char **line);

#endif
