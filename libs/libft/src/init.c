/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 10:08:30 by lbelda            #+#    #+#             */
/*   Updated: 2018/04/17 17:42:56 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_flag_funcs(int (*funcs[SZE_BFF])(t_arg_info*))
{
	size_t	i;

	i = '1' - 1;
	while (++i < '9' + 1)
		funcs[i] = &p_parse_number;
	funcs['.'] = &p_precision_flag;
	funcs['*'] = &p_asterisk_width_flag;
	funcs['#'] = &p_hashtag_flag;
	funcs['0'] = &p_zero_flag;
	funcs['-'] = &p_minus_flag;
	funcs[' '] = &p_space_flag;
	funcs['+'] = &p_plus_flag;
	funcs['\''] = &p_separator_flag;
	funcs['h'] = &p_tshort_flag;
	funcs['l'] = &p_tlong_flag;
	funcs['L'] = &p_tlongdouble_flag;
	funcs['z'] = &p_tsize_flag;
	funcs['j'] = &p_tmax_flag;
}

static void	init_bonus_converter_funcs(int (*funcs[SZE_BFF])(t_arg_info*))
{
	funcs['a'] = &p_a_converter;
	funcs['A'] = &p_upa_converter;
	funcs['e'] = &p_e_converter;
	funcs['E'] = &p_upe_converter;
	funcs['f'] = &p_f_converter;
	funcs['F'] = &p_upf_converter;
	funcs['g'] = &p_g_converter;
	funcs['G'] = &p_upg_converter;
	funcs['n'] = &p_n_converter;
	funcs['b'] = &p_b_converter;
	funcs['B'] = &p_upb_converter;
	funcs['m'] = &p_m_converter;
	funcs['y'] = &p_y_converter;
	funcs['Y'] = &p_upy_converter;
}

static void	init_converter_funcs(int (*funcs[SZE_BFF])(t_arg_info*))
{
	funcs['d'] = &p_d_converter;
	funcs['D'] = &p_upd_converter;
	funcs['u'] = &p_u_converter;
	funcs['U'] = &p_upu_converter;
	funcs['i'] = &p_i_converter;
	funcs['x'] = &p_x_converter;
	funcs['X'] = &p_upx_converter;
	funcs['o'] = &p_o_converter;
	funcs['O'] = &p_upo_converter;
	funcs['c'] = &p_c_converter;
	funcs['C'] = &p_upc_converter;
	funcs['s'] = &p_s_converter;
	funcs['S'] = &p_ups_converter;
	funcs['p'] = &p_p_converter;
	init_bonus_converter_funcs(funcs);
}

static void	init_treat_arg_funcs(int (*funcs[T_MAX])(t_ptenv*, va_list args))
{
	funcs[T_INTEGER] = &treat_integer;
	funcs[T_INTEGER_BASE] = &treat_integer_base;
	funcs[T_BIGUINT] = &treat_biguint;
	funcs[T_FLOAT_HEX] = &treat_float_hex;
	funcs[T_FLOAT_DEC] = &treat_float_dec;
	funcs[T_FLOAT_DEC_E] = &treat_float_dec;
	funcs[T_FLOAT_DEC_F] = &treat_float_dec;
	funcs[T_FLOAT_DEC_G] = &treat_float_dec;
	funcs[T_CHAR] = &treat_char;
	funcs[T_WCHAR] = &treat_wchar;
	funcs[T_STRING] = &treat_string;
	funcs[T_WSTRING] = &treat_wstring;
	funcs[T_MEMORY] = &treat_memory;
	funcs[T_SIZE_TO_PTR] = &treat_size_to_ptr;
	funcs[T_PIXEL_BUFFER] = &treat_pixel_buffer;
	funcs[T_WPIXEL_BUFFER] = &treat_pixel_buffer;
	funcs[T_INVALID] = &treat_invalid;
}

int			init_ptenv(t_ptenv *e)
{
	size_t	i;

	i = -1;
	ft_bzero(e, sizeof(t_ptenv));
	while (++i < SZE_BFF)
		e->funcs[i] = &p_invalid_flag;
	e->funcs['\0'] = &p_backslash_zero;
	init_flag_funcs(e->funcs);
	init_converter_funcs(e->funcs);
	init_treat_arg_funcs(e->treat_funcs);
	return (0);
}
