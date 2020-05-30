# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tjans <tjans@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2020/05/05 12:00:00 by tjans         #+#    #+#                  #
#    Updated: 2020/05/05 12:00:00 by tjans         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CUB3D_BASE_PATH = ../../
INCLUDES		:=  -I $(CUB3D_BASE_PATH)/inc -I $(CUB3D_BASE_PATH)/libft/out \
					-I $(CUB3D_BASE_PATH)/libmlx

SRCS	= util_bonus.c texloader_bonus.c
OBJS	:= $(SRCS:.c=.o)

TARGET	:= $(shell uname -s)

ifeq ($(TARGET),Linux)
	NAME = ../libplugin.so
	LDFLAGS = -L ../../ -lmlx
else
	NAME = ../libplugin.dylib
	LDFLAGS = -L ../../ -lmlx -lft -undefined dynamic_lookup
endif

CFLAGS	:= -Wall -Wextra -fPIC $(INCLUDES)

%.o : %.c
	@echo CC $<
	@$(CC) $(CFLAGS) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(LDFLAGS) -shared -o $@ $^

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
