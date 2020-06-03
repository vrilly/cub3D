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
	LDFLAGS := -lXext -lX11
else
	LIBEXT = dylib
	LDFLAGS := -framework OpenGL -framework AppKit
endif

LIBFT		= libft
LIBFT_LIB	:= $(LIBFT)/libft.$(LIBEXT)
LIBPF		= libftprintf
LIBPF_LIB	:= $(LIBFT)/out/libftprintf.$(LIBEXT)
LIBMLX		= libmlx
LIBMLX_LIB	:= $(LIBMLX)/libmlx.$(LIBEXT)

NAME	= cub3D
VPATH	:= $(SRC_DIR)

CFLAGS	:= -g -Wall -Wextra -I $(INC_DIR) -I $(LIBFT)/out -I $(LIBMLX)

LDFLAGS	:= $(LDFLAGS) -L . -L $(LIBMLX) -lftprintf -lft -lmlx -lm \
		   -Wl,-rpath,.
CFLAGS	:= $(CFLAGS) -I /usr/X11/include

S_CUB3D		= cub3d.c config.c hooks.c loop.c ftlog.c cub3d_error.c \
			  reconf.c
S_MAP		= map_reader.c map_reader_seq.c map_texloader.c map_color.c \
			  map_verify.c map_fd.c map_flip.c map_buffer.c \
			  map_lookup.c map_reader_tex.c
S_GFX		= window.c renderer.c render_calc.c frame.c camera.c background.c \
			  movement.c
S_SPRITE	= engine.c spr_sort.c spr_cast.c
S_BMP		= bmp_hdr.c frame_to_bitmap.c save_bmp.c
S_BONUS		= plugin.c plugin_hooks_bonus.c

B_PLUGINS	= $(addprefix plugins/, hud.$(LIBEXT) libplugin.$(LIBEXT) \
			  entity.$(LIBEXT) fontrenderer.$(LIBEXT))

ifeq ($(BONUS),1)
	S_BONUS = plugin_bonus.c plugin_hooks_bonus.c
	CFLAGS	:= $(CFLAGS) -D BONUS=1
	LDFLAGS	:= $(LDFLAGS) -ldl -Wl,-rpath,./plugins
endif

ifneq ("$(wildcard .bonus_compiled)", "")
ifneq ($(MAKECMDGOALS), bonus)
ifneq ($(BONUS),1)
	DUMMY := $(shell $(RM) .bonus_compiled)
	DUMMY := $(shell $(RM) $(NAME))
endif
endif
else
ifneq ($(wildcard obj/plugin.o), "")
ifeq ($(BONUS), 1)
	DUMMY := $(shell $(RM) $(NAME))
endif
endif
endif

SRCS	:= $(S_CUB3D) $(S_MAP) $(S_GFX) $(S_SPRITE) $(S_BMP) $(S_BONUS)
HDRS	:= cub3d.h texture.h map.h gfx.h config.h spr_cast.h \
	renderer.h ftlog.h cub3d_error.h bitmap.h plugin_bonus.h
OBJS	:= $(SRCS:.c=.o)

.PHONY: dirs re fclean clean all nuke plugins bonus compile_bonus \
		plugins_clean plugins_fclean

$(OBJ_DIR)/%.o : %.c $(addprefix $(INC_DIR)/, $(HDRS)) | $(OBJ_DIR)
	@echo $(CC) $<
	@$(CC) $(CFLAGS) -c -o $@ $<

plugins/%.$(LIBEXT) : plugins/%
	@$(MAKE) -C $<

all: $(LIBMLX_LIB) $(LIBFT_LIB) $(NAME)

plugins: $(B_PLUGINS)

plugins_clean: $(basename $(B_PLUGINS))
	@for dir in $^; do \
  		$(MAKE) --no-print-directory -C $$dir clean; \
  	done

plugins_fclean: $(basename $(B_PLUGINS))
	@for dir in $^; do \
  		$(MAKE) --no-print-directory -C $$dir fclean; \
  	done

compile_bonus:
	@$(MAKE) --no-print-directory BONUS=1
	@touch .bonus_compiled

bonus: compile_bonus plugins

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

clean: plugins_clean
	@$(RM) -r $(OBJ_DIR)

fclean: clean plugins_fclean
	@$(RM) $(NAME)

re: fclean all

nuke: fclean
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) -C $(LIBMLX) clean
	@$(RM) $(LIBFT).$(LIBEXT) $(LIBMLX).$(LIBEXT) $(LIBPF).$(LIBEXT)

nuke_re: nuke
	@$(MAKE) re

$(OBJ_DIR):
	@echo Compiling $(NAME)...
	@echo Host: $$(uname -rms)
	@echo CFLAGS: $(CFLAGS)
	@echo LDFLAGS: $(LDFLAGS)
	@echo ---Start---
	@mkdir -p $(OBJ_DIR)

