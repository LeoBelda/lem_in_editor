SRC_DIR=src/

ROOT_FILES=main.c lem_in_visu.c

PARSE_DIR=parse/
PARSE_FILES=parse.c parse_to_map.c \
			parse_funcs.c parse_funcs_spe.c parse_utils.c clean_parse.c

INIT_DIR=init/
INIT_FILES=init_context.c init_controls.c init_matrices.c \
		   init_scene.c init_scene_edit.c \
		   create_room_model.c init_scene_helpers.c

GRAPHICS_DIR=graphics/
GRAPHICS_FILES=render.c update_uniforms.c update_turns.c
CONTROLS_DIR=controls/
CONTROLS_FILES=handle_events.c \
			   kb_misc.c kb_forward.c kb_play.c kb_startend.c \
			   ms_room.c ms_bind.c ms_move.c ms_utils.c ms_utils_link.c

UTILS_DIR=utils/
UTILS_FILES=ogl_utils.c build_ogl_program.c \
			print_map.c error_map.c \
			clean_env.c lstdels.c \
			error.c protec.c debug.c

SRC_DIRS=$(PARSE_DIR) $(INIT_DIR) $(GRAPHICS_DIR) $(UTILS_DIR) $(CONTROLS_DIR)
SRC_FILES=$(addprefix $(INIT_DIR), $(INIT_FILES)) \
		   $(addprefix $(PARSE_DIR), $(PARSE_FILES)) \
		   $(addprefix $(GRAPHICS_DIR), $(GRAPHICS_FILES)) \
		   $(addprefix $(CONTROLS_DIR), $(CONTROLS_FILES)) \
		   $(addprefix $(UTILS_DIR), $(UTILS_FILES)) \
		   $(ROOT_FILES)

SRC=$(addprefix $(SRC_DIR), $(SRC_FILES))

INC_DIR=include/
INC_FILES=visu.h common.h \
		  map.h parse.h scene.h controls.h \
		  objects.h matrices.h \
		  common.h ogl_utils.h debug.h
INC=$(addprefix $(INC_DIR), $(INC_FILES))

BUILD_DIR=build/
BUILD_ARB=$(addprefix $(BUILD_DIR), $(SRC_DIRS))
OBJ=$(addprefix $(BUILD_DIR), $(SRC_FILES:%.c=%.o))

LIBFT_DIR=libs/libft/
LIBFT_LIB=libft.a
LIBFT_LK=ft
LIBFT_INCDIR=$(addprefix $(LIBFT_DIR), include/)
LIBFT_INCFILES=ft_printf.h libft.h
LIBFT_INC=$(addprefix $(LIBFT_INCDIR), $(LIBFT_INCFILES))
LIBFT=$(addprefix $(LIBFT_DIR), $(LIBFT_LIB))

LIBFTMT_DIR=libs/libftmath/
LIBFTMT_LIB=libftmath.a
LIBFTMT_LK=ftmath
LIBFTMT_INCDIR=$(LIBFTMT_DIR)
LIBFTMT_INCFILES=libftmath.h
LIBFTMT_INC=$(addprefix $(LIBFTMT_INCDIR), $(LIBFTMT_INCFILES))
LIBFTMT=$(addprefix $(LIBFTMT_DIR), $(LIBFTMT_LIB))

SDL_ROOT=libs/SDL2/
SDL_LIBROOT=lib/
SDL_LIB=libSDL2.a
SDL_INCROOT=include/SDL2/
SDL_SRCROOT=sources/
SDL_LK=SDL2
ORIGIN=\$$ORIGIN/
SDL_SRCDIR=$(addprefix $(SDL_ROOT), $(SDL_SRCROOT))
SDL_INCDIR=$(addprefix $(SDL_ROOT), $(SDL_INCROOT))
SDL_LIBDIR=$(addprefix $(SDL_ROOT), $(SDL_LIBROOT))
SDL_RPATH=$(addprefix $(ORIGIN), $(SDL_LIBDIR))
SDL=$(addprefix $(SDL_LIBDIR), $(SDL_LIB))

LIB_FLAGS=-L$(LIBFT_DIR) -l$(LIBFT_LK) -L$(LIBFTMT_DIR) -l$(LIBFTMT_LK)\
		  -L$(SDL_LIBDIR) -l$(SDL_LK) -lm

UNAME:=$(shell uname -s)
ifeq ($(UNAME),Darwin)
	LIB_FLAGS+= -framework OpenGL
else
	LIB_FLAGS+= -lGL -lGLU -lGLEW
endif

ALL_INC=$(INC) $(LIBFT_INC)
-I_ALL_INC=-I$(INC_DIR) -I$(LIBFT_INCDIR) -I$(LIBFTMT_INCDIR) -I$(SDL_INCDIR)

NAME=visu

MAKE=make
MKDIR_P=mkdir -p
CC=gcc
CFLAGS=-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(BUILD_ARB) $(LIBFT) $(LIBFTMT) $(SDL) $(OBJ) $(ALL_INC)
	$(CC) -o $(NAME) $(OBJ) $(-I_ALL_INC) \
		$(LIB_FLAGS) -Wl,-rpath,$(SDL_RPATH)

$(BUILD_DIR)%.o: $(SRC_DIR)%.c $(ALL_INC)
	$(CC) $(CFLAGS) -o $@ $(-I_ALL_INC) -c $<

$(BUILD_ARB):
	-@$(MKDIR_P) $(BUILD_ARB)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(LIBFTMT):
	$(MAKE) -C $(LIBFTMT_DIR)

$(SDL):
	cd $(SDL_SRCDIR) && ./configure --prefix=$$PWD/../
	$(MAKE) -C $(SDL_SRCDIR) install

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(LIBFTMT_DIR) clean
	rm -rf $(BUILD_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(LIBFTMT_DIR) fclean
	rm -rf $(NAME)
	$(MAKE) -C $(SDL_SRCDIR) uninstall
	rm -rf $(SDL_ROOT)bin
	rm -rf $(SDL_ROOT)include
	rm -rf $(SDL_ROOT)lib
	rm -rf $(SDL_ROOT)share

re: fclean all

.PHONY: all clean fclean re
