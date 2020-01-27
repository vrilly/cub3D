# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tjans <tjans@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/09 16:21:06 by tjans         #+#    #+#                  #
#    Updated: 2020/01/27 22:59:22 by tjans         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRC_DIR	= src src/map src/gfx src/sprite
INC_DIR	= inc
OBJ_DIR = obj

LIBFT		= libft
LIBFT_LIB	:= $(LIBFT)/out/libft.a
LIBMLX		= libmlx
LIBMLX_LIB	:= $(LIBMLX)/libmlx.dylib

NAME	= cub3D
VPATH	:= $(SRC_DIR)

CFLAGS	:= -g -Wall -Wextra -I $(INC_DIR) -I $(LIBFT)/inc -I $(LIBMLX)

UNAME_S	:= $(shell uname -s)
ifeq ($(UNAME_S), Darwin)
	LDFLAGS	:= -L $(LIBFT)/out -L $(LIBMLX) -lft -lmlx -lm \
				-framework OpenGL -framework AppKit
	CFLAGS	:= $(CFLAGS) -I /usr/X11/include
else
	LDFLAGS	:= -L $(LIBFT)/out -L $(LIBMLX) -lft -lmlx -lm \
				-lXext -lX11 -lbsd
endif

S_CUB3D		= cub3d.c config.c hooks.c loop.c
S_MAP		= map_reader.c map_reader_seq.c map_texloader.c map_color.c \
			  map_parser.c
S_GFX		= window.c renderer.c render_calc.c frame.c camera.c background.c \
			  movement.c
S_SPRITE	= engine.c spr_sort.c

SRCS	:= $(S_CUB3D) $(S_MAP) $(S_GFX) $(S_SPRITE)
HDRS	:= cub3d.h texture.h map_seq.h gfx.h config.h
OBJS	:= $(SRCS:.c=.o)

$(OBJ_DIR)/%.o : %.c $(addprefix $(INC_DIR)/, $(HDRS)) | dirs
	@echo CC $<
	@$(CC) $(CFLAGS) -c -o $@ $<

all: $(NAME)

$(LIBFT_LIB) : $(LIBFT)
	@DEBUG=1 $(MAKE) -C $<

$(LIBMLX_LIB) : $(LIBMLX)
	$(MAKE) -C $<

$(NAME): $(addprefix $(OBJ_DIR)/, $(OBJS)) | $(LIBFT_LIB) $(LIBMLX_LIB)
	@echo Linking $(NAME)
	@$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	@echo ---DONE---

clean:
	@$(RM) -r $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

nuke:
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) -C $(LIBMLX) clean
	@$(MAKE) re

dirs:
	@echo Compiling $(NAME)...
	@echo Host: $$(uname -rms)
	@echo CFLAGS: $(CFLAGS)
	@echo LDFLAGS: $(LDFLAGS)
	@echo ---Start---
	@mkdir -p $(OBJ_DIR)

.PHONY: dirs re fclean clean all nuke
