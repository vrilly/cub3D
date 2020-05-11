# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tjans <tjans@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2020/03/02 19:01:43 by tjans         #+#    #+#                  #
#    Updated: 2020/03/02 19:01:44 by tjans         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRC_DIR	= src src/map src/gfx src/sprite src/bmp
INC_DIR	= inc
OBJ_DIR = obj

TARGET	:= $(shell uname -s)
ifeq ($(TARGET),Linux)
	LIBEXT = so
else
	LIBEXT = dylib
endif

LIBFT		= libft
LIBFT_LIB	:= $(LIBFT)/out/libft.$(LIBEXT)
LIBPF_LIB	:= $(LIBFT)/out/libftprintf.$(LIBEXT)
LIBMLX		= libmlx
LIBMLX_LIB	:= $(LIBMLX)/libmlx.dylib

NAME	= cub3D
VPATH	:= $(SRC_DIR)

CFLAGS	:= -Wall -Wextra -Werror -I $(INC_DIR) -I $(LIBFT)/out -I $(LIBMLX)

LDFLAGS	:= -L $(LIBFT)/out -L $(LIBMLX) -lft -lmlx -lm \
			-framework OpenGL -framework AppKit
CFLAGS	:= $(CFLAGS) -I /usr/X11/include

S_CUB3D		= cub3d.c config.c hooks.c loop.c ftlog.c cub3d_error.c \
			  reconf.c
S_MAP		= map_reader.c map_reader_seq.c map_texloader.c map_color.c \
			  map_verify.c map_fd.c map_flip.c map_buffer.c \
			  map_lookup.c map_reader_tex.c
S_GFX		= window.c renderer.c render_calc.c frame.c camera.c background.c \
			  movement.c util.c
S_SPRITE	= engine.c spr_sort.c spr_cast.c
S_BMP		= bmp_hdr.c frame_to_bitmap.c save_bmp.c
S_BONUS		=

B_PLUGINS	= $(addprefix plugins/, minimap.so)

ifeq ($(BONUS),1)
	S_BONUS = plugin.c plugin_hooks.c
	CFLAGS	:= $(CFLAGS) -D BONUS=1
	LDFLAGS	:= $(LDFLAGS) -ldl -Wl,-rpath,./plugins
endif

SRCS	:= $(S_CUB3D) $(S_MAP) $(S_GFX) $(S_SPRITE) $(S_BMP) $(S_BONUS)
HDRS	:= cub3d.h texture.h map.h gfx.h config.h spr_cast.h \
	renderer.h ftlog.h cub3d_error.h bitmap.h
OBJS	:= $(SRCS:.c=.o)

$(OBJ_DIR)/%.o : %.c $(addprefix $(INC_DIR)/, $(HDRS)) | $(OBJ_DIR)
	@echo CC $<
	@$(CC) $(CFLAGS) -c -o $@ $<

plugins/%.so : plugins/%
	@$(MAKE) -C $<

all: $(LIBMLX_LIB) $(LIBFT_LIB) $(NAME)

plugins: $(B_PLUGINS)

bonus:
	$(MAKE) BONUS=1
	$(MAKE) plugins

$(LIBFT_LIB) : $(LIBFT)
	$(MAKE) -C $<
	@cp $@ .
	@cp $(LIBPF_LIB) .

$(LIBMLX_LIB) : $(LIBMLX)
	$(MAKE) -C $<
	@cp $@ .

$(NAME): $(addprefix $(OBJ_DIR)/, $(OBJS))
	@echo Linking $(NAME)
	@$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	@echo ---DONE---

clean:
	@$(RM) -r $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

nuke: fclean
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) -C $(LIBMLX) clean

nuke_re: nuke
	@$(MAKE) re

$(OBJ_DIR):
	@echo Compiling $(NAME)...
	@echo Host: $$(uname -rms)
	@echo CFLAGS: $(CFLAGS)
	@echo LDFLAGS: $(LDFLAGS)
	@echo ---Start---
	@mkdir -p $(OBJ_DIR)

.PHONY: dirs re fclean clean all nuke
