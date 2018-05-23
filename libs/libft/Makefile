# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbelda <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 09:59:44 by lbelda            #+#    #+#              #
#    Updated: 2018/04/25 12:47:28 by lbelda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR=src/
FILES_LIBFT=ft_printf.c ft_dprintf.c ft_snprintf.c ft_sprintf.c ft_asprintf.c \
			 ft_genprintf.c init.c conclude.c \
			 cast_arg.c \
			 \
			 treat_integer.c treat_integer_base.c treat_biguint.c \
			 treat_float_dec.c treat_float_hex.c \
			 treat_char.c treat_wchar.c treat_string.c treat_wstring.c \
			 treat_memory.c treat_size_to_ptr.c treat_pixel_buffer.c \
			 treat_invalid.c \
			 \
			 flag_funcs1.c flag_funcs2.c type_funcs1.c \
			 float_funcs1.c float_funcs2.c \
			 decimal_funcs.c base_funcs1.c base_funcs2.c \
			 char_funcs.c ptr_funcs.c \
			 number_funcs.c misc_funcs.c bonus_funcs.c \
			 \
			 \
			 ft_intset.c \
			 ft_lintset.c \
			 ft_floatset.c \
			 ft_intcpy.c \
			 ft_bzero.c \
			 ft_ismemzero.c \
			 ft_memcpy.c \
			 ft_memccpy.c \
			 ft_memmove.c \
			 ft_memdeplace.c \
			 ft_memset.c \
			 ft_memrset.c \
			 ft_memchr.c \
			 ft_memcmp.c \
			 ft_strlen.c \
			 ft_wstrlen.c \
			 ft_strdup.c \
			 ft_strcpy.c \
			 ft_strncpy.c \
			 ft_strcat.c \
			 ft_strncat.c \
			 ft_strlcat.c \
			 ft_strchr.c \
			 ft_strrchr.c \
			 ft_strstr.c \
			 ft_strnstr.c \
			 ft_strcmp.c \
			 ft_strncmp.c \
			 ft_atoi.c \
			 ft_atoui.c \
			 ft_wctoi.c \
			 ft_wstrtostr.c \
			 ft_isalpha.c \
			 ft_isdigit.c \
			 ft_isalnum.c \
			 ft_isascii.c \
			 ft_isprint.c \
			 ft_toupper.c \
			 ft_strtoupper.c \
			 ft_tolower.c \
			 \
			 ft_memalloc.c \
			 ft_memdel.c \
			 ft_strnew.c \
			 ft_strnew_fill.c \
			 ft_strdel.c \
			 ft_tabdel.c \
			 ft_strclr.c \
			 ft_striter.c \
			 ft_striteri.c \
			 ft_strmap.c \
			 ft_strmapi.c \
			 ft_strequ.c \
			 ft_strnequ.c \
			 ft_strsub.c \
			 ft_strjoin.c \
			 ft_strnjoin.c \
			 ft_append_free.c \
			 ft_append_fromstack_free.c \
			 ft_append_tostack_free.c \
			 ft_strtrim.c \
			 ft_strnowhitespace.c \
			 ft_strsplit.c \
			 ft_itoa.c \
			 ft_itoa_light.c \
			 ft_uitoa.c \
			 ft_uitoa_light.c \
			 ft_itoa_bin_oct_hex.c \
			 ft_double_struct.c \
			 ft_ldouble_struct.c \
			 ft_dtoa_hex.c \
			 ft_dtoa_hex_ev.c \
			 ft_dtoa_hex_precision.c \
			 ft_dtoa_dec.c \
			 ft_dtoa_dsint_calc.c \
			 ft_dtoa_format.c \
			 ft_putchar.c \
			 ft_putstr.c \
			 ft_putendl.c \
			 ft_putnbr.c \
			 ft_putchar_fd.c \
			 ft_putstr_fd.c \
			 ft_putendl_fd.c \
			 ft_putnbr_fd.c \
			 \
			 ft_lstnew.c \
			 ft_lstnewref.c \
			 ft_lstdelone.c \
			 ft_lstdel.c \
			 ft_lstdel_n.c \
			 ft_lstadd.c \
			 ft_lstradd.c \
			 ft_lstat.c \
			 ft_lstiter.c \
			 ft_lstmap.c \
			 ft_lstmap_param.c \
			 ft_lst_to_array.c \
			 ft_lstrev.c \
			 \
			 ft_memrcpy.c \
			 ft_strspn.c \
			 ft_strcspn.c \
			 ft_isupper.c \
			 ft_islower.c \
			 ft_iswhitespace.c \
			 ft_skipwhitespace.c \
			 ft_strndup.c \
			 ft_putmem.c \
			 ft_putmemendl.c \
			 ft_putmem_fd.c \
			 ft_putmemendl_fd.c \
			 ft_lstcount.c \
			 ft_strsplit_lst.c \
			 \
			 ft_swap.c \
			 ft_max.c \
			 ft_min.c \
			 ft_fclamp.c \
			 \
			 create_dsint.c \
			 shift_dsint.c \
			 add_dsint.c \
			 mul_dsint.c \
			 div_dsint.c \
			 dsint_to_alpha_light.c \
			 dsint_to_alpha.c \
			 get_pow10.c \
			 set_dsint_precision.c \
			 \
			 get_next_line.c

SRC_LIBFT=$(addprefix $(SRC_DIR), $(FILES_LIBFT))
	
INCDIR=include/
INCFILES=ft_printf.h libft.h
INC=$(addprefix $(INCDIR), $(INCFILES))

BUILD_DIR= build/
OBJ=$(addprefix $(BUILD_DIR), $(FILES_LIBFT:%.c=%.o))

NAME=libft.a
CC=gcc
CFLAGS=-Wall -Wextra -Werror

MKDIR_P=mkdir -p

all: $(NAME)

$(NAME_TEST): $(SRC_TEST) all
	$(CC) $(CFLAGS) -Wno-error -o $(NAME_TEST) -I$(INCDIR) $< $(NAME)

$(NAME): $(BUILD_DIR) $(OBJ) $(INC)
	-@ar rc $(NAME) $(OBJ)
	-@ranlib $(NAME)
	-@echo "Libft ready."

$(BUILD_DIR)%.o: $(SRC_DIR)%.c $(INC)
	$(CC) $(CFLAGS) -o $@ -I$(INCDIR) -c $<

$(BUILD_DIR):
	-@$(MKDIR_P) $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(NAME_TEST)

re: fclean all

.PHONY: all clean fclean re
