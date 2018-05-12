/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 18:40:46 by lbelda            #+#    #+#             */
/*   Updated: 2018/04/20 13:25:16 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <wchar.h>
# include "libft.h"

# define OR 0
# define CPY 1
# define SZE_BFF 256
# define SZE_NULLSTR 6
# define NULLSTR "(null)"
# define NULLWSTR L"(null)"

enum			e_flags
{
	F_ALTERNATE_FORM = 1,
	F_ZERO_PADDING = 1 << 1,
	F_NEGATIVE_FIELD = 1 << 2,
	F_BLANK_POSITIVE = 1 << 3,
	F_SIGN_POSITIVE = 1 << 4,
	F_SEPARATOR = 1 << 5,
	F_PRECISION_ON = 1 << 6,
	F_TSHORT = 1 << 8,
	F_TSHORTSHORT = 1 << 9,
	F_TLONG = 1 << 10,
	F_TLONGLONG = 1 << 11,
	F_TSIZE = 1 << 12,
	F_TMAX = 1 << 13,
	F_TLONGDOUBLE = 1 << 14,
	F_INTEGER = 1 << 16,
	F_FLOAT = 1 << 17,
	F_CHAR = 1 << 18,
	F_STRING = 1 << 19,
	F_MEMORY = 1 << 20,
	F_WIDE = 1 << 21,
	F_SIGNED = 1 << 22,
	F_UNSIGNED = 1 << 23,
	F_UPPERCASE = 1 << 24,
	F_INVALID = 1 << 31
};

typedef enum	e_types
{
	T_INTEGER = 0,
	T_INTEGER_BASE,
	T_BIGUINT,
	T_FLOAT_HEX,
	T_FLOAT_DEC,
	T_FLOAT_DEC_E,
	T_FLOAT_DEC_F,
	T_FLOAT_DEC_G,
	T_CHAR,
	T_WCHAR,
	T_STRING,
	T_WSTRING,
	T_MEMORY,
	T_SIZE_TO_PTR,
	T_PIXEL_BUFFER,
	T_WPIXEL_BUFFER,
	T_INVALID,
	T_MAX
}				t_types;

typedef struct	s_arg_info
{
	char		*conv_str;
	wchar_t		*conv_wstr;
	int			conv_size;
	int			tot_conv_size;
	char		*arg_str;
	int			arg_size;
	char		prefix[2];
	int			pref_size;
	int			sep_size;
	char		invalid_char;
	int			wchar;
	int			flags;
	t_types		type;
	int			precision_val;
	int			field_width_val;
	int			base;
	int			arg_i;
	int			arg_f;
	va_list		args_ref;
	const char	*fmt_ref;
}				t_arg_info;

typedef struct	s_ptenv
{
	t_list		*string_parts;
	char		*final_str;
	int			fpos;
	int			arg_pos_i;
	int			arg_pos_f;
	int			total;
	int			(*funcs[SZE_BFF])(t_arg_info*);
	int			(*treat_funcs[T_MAX])(struct s_ptenv*m, va_list args);
	t_arg_info	info;
}				t_ptenv;

int				ft_printf(const char *format, ...);
int				ft_sprintf(char *str, const char *format, ...);
int				ft_snprintf(char *str, size_t size, const char *format, ...);
int				ft_asprintf(char **ret, const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);

int				ft_vprintf(const char *format, va_list ap);
int				ft_vsprintf(char *str, const char *format, va_list ap);
int				ft_vsnprintf(char *str, size_t size,
								const char *format, va_list ap);
int				ft_vasprintf(char **ret, const char *format, va_list ap);
int				ft_vdprintf(int fd, const char *format, va_list ap);

int				ft_genprintf(const char *format, va_list ap, t_ptenv *e);
int				init_ptenv(t_ptenv *e);
int				pad_string(t_ptenv *e);

int				get_total_size(t_list *str_parts);
int				build_final_string(char **final_str, t_list *str_parts);
int				cleanup(t_list *str_parts);

int				treat_integer(t_ptenv *e, va_list args);
int				treat_integer_base(t_ptenv *e, va_list args);
int				treat_biguint(t_ptenv *e, va_list args);
int				treat_float_hex(t_ptenv *e, va_list args);
int				treat_float_dec(t_ptenv *e, va_list args);
int				treat_char(t_ptenv *e, va_list args);
int				treat_wchar(t_ptenv *e, va_list args);
int				treat_string(t_ptenv *e, va_list args);
int				treat_wstring(t_ptenv *e, va_list args);
int				treat_memory(t_ptenv *e, va_list args);
int				treat_size_to_ptr(t_ptenv *e, va_list args);
int				treat_pixel_buffer(t_ptenv *e, va_list args);
int				treat_invalid(t_ptenv *e, va_list args);

uintmax_t		cast_unsigned_arg(t_ptenv *e, va_list args);
intmax_t		cast_signed_arg(t_ptenv *e, va_list args);
void			cast_ptr_arg(t_ptenv *e, va_list args);

int				p_hashtag_flag(t_arg_info *inf);
int				p_zero_flag(t_arg_info *inf);
int				p_minus_flag(t_arg_info *inf);
int				p_space_flag(t_arg_info *inf);
int				p_plus_flag(t_arg_info *inf);
int				p_separator_flag(t_arg_info *inf);
int				p_asterisk_width_flag(t_arg_info *inf);

int				p_tshort_flag(t_arg_info *inf);
int				p_tlong_flag(t_arg_info *inf);
int				p_tsize_flag(t_arg_info *inf);
int				p_tmax_flag(t_arg_info *inf);
int				p_tlongdouble_flag(t_arg_info *inf);

int				p_parse_number(t_arg_info *inf);
int				p_precision_flag(t_arg_info *inf);

int				p_d_converter(t_arg_info *inf);
int				p_upd_converter(t_arg_info *inf);
int				p_u_converter(t_arg_info *inf);
int				p_upu_converter(t_arg_info *inf);
int				p_i_converter(t_arg_info *inf);
int				p_x_converter(t_arg_info *inf);
int				p_upx_converter(t_arg_info *inf);
int				p_o_converter(t_arg_info *inf);
int				p_upo_converter(t_arg_info *inf);
int				p_c_converter(t_arg_info *inf);
int				p_upc_converter(t_arg_info *inf);
int				p_s_converter(t_arg_info *inf);
int				p_ups_converter(t_arg_info *inf);
int				p_p_converter(t_arg_info *inf);

int				p_a_converter(t_arg_info *inf);
int				p_upa_converter(t_arg_info *inf);
int				p_e_converter(t_arg_info *inf);
int				p_upe_converter(t_arg_info *inf);
int				p_f_converter(t_arg_info *inf);
int				p_upf_converter(t_arg_info *inf);
int				p_g_converter(t_arg_info *inf);
int				p_upg_converter(t_arg_info *inf);
int				p_n_converter(t_arg_info *inf);
int				p_b_converter(t_arg_info *inf);
int				p_upb_converter(t_arg_info *inf);
int				p_m_converter(t_arg_info *inf);
int				p_y_converter(t_arg_info *inf);
int				p_upy_converter(t_arg_info *inf);

int				p_invalid_flag(t_arg_info *inf);
int				p_backslash_zero(t_arg_info *inf);

#endif
