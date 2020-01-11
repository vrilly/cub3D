# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tjans <tjans@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/09 16:21:06 by tjans         #+#    #+#                  #
#    Updated: 2020/01/11 17:24:09 by tjans         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRC_DIR	= src src/map
INC_DIR	= inc
OBJ_DIR = obj

LIBFT		= libft
LIBFT_LIB	:= $(LIBFT)/out/libft.a
LIBMLX		= libmlx
LIBMLX_LIB	:= $(LIBMLX)/libmlx.dylib

NAME	= cub3D
VPATH	:= $(SRC_DIR)

CFLAGS	:= -g -Wall -Wextra -I $(INC_DIR) -I $(LIBFT)/inc -I $(LIBMLX)
LDFLAGS	:= -L $(LIBFT)/out -L $(LIBMLX) -lft -lmlx -lm \
			-framework OpenGL -framework AppKit

S_CUB3D	= cub3d.c
S_MAP	= map_reader.c map_reader_seq.c map_texloader.c

SRCS	:= $(S_CUB3D) $(S_MAP)
HDRS	:= cub3d.h texture.h map_seq.h
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
	@$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
	@echo ---DONE---

clean:
	@$(MAKE) -C $(LIBFT) clean
	@$(RM) -r $(OBJ_DIR)

fclean: clean
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) -C $(LIBMLX) clean
	@$(RM) $(NAME)

re: fclean all

dirs:
	@echo Compiling $(NAME)...
	@echo Host: $$(uname -rms)
	@echo CFLAGS: $(CFLAGS)
	@echo LDFLAGS: $(LDFLAGS)
	@echo ---Start---
	@mkdir -p $(OBJ_DIR)

.PHONY: dirs re fclean clean all
