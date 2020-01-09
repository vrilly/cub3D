# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tjans <tjans@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/09 16:21:06 by tjans         #+#    #+#                  #
#    Updated: 2020/01/09 16:36:10 by tjans         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRC_DIR	= src
INC_DIR	= inc
OBJ_DIR = obj

LIBFT		= libft
LIBFT_LIB	:= $(LIBFT)/out/libft.a

NAME	= cub3D
VPATH	:= $(SRC_DIR)

CFLAGS	:= -Wall -Wextra -I $(INC_DIR) -I $(LIBFT)/inc
LDFLAGS	:= -L $(LIBFT)/out -lft -lm

S_CUB3D	= cub3d.c

SRCS	:= $(S_CUB3D)
HDRS	:=
OBJS	:= $(SRCS:.c=.o)

$(OBJ_DIR)/%.o : %.c $(addprefix $(INC_DIR)/, $(HDRS)) | dirs
	@echo CC $<
	@$(CC) $(CFLAGS) -c -o $@ $<

all: $(NAME)

$(LIBFT_LIB) : $(LIBFT)
	@$(MAKE) -C $(LIBFT)

$(NAME): $(addprefix $(OBJ_DIR)/, $(OBJS)) | $(LIBFT_LIB)
	@echo Linking $(NAME)
	@$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
	@echo ---DONE---

clean:
	@$(MAKE) -C $(LIBFT) clean
	@$(RM) -r $(OBJ_DIR)

fclean: clean
	@$(MAKE) -C $(LIBFT) fclean
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
