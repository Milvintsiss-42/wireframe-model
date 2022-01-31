# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/02 02:43:30 by ple-stra          #+#    #+#              #
#    Updated: 2022/01/31 07:55:50 by ple-stra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fdf

SRCS_DIR	= srcs
SRCS		= main.c parse_map.c errors.c
BUILD_DIR	= build
OBJ_DIR		= $(BUILD_DIR)/objs
OBJ			= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
INC			= -I./includes -I./$(LIBFT_DIR)/includes -I./$(MLX_DIR) -I./

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/build/libft.a
LIBFT_FLAGS	= -L$(LIBFT_DIR)/build -lft

ifeq ($(shell uname), Linux)
MLX_DIR		= minilibx-linux
MLX_LIB		= $(MLX_DIR)/libmlx_Linux.a
MLXFLAGS	= -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm
else
MLX_DIR		= mlx
MLX_LIB		= $(MLX_DIR)/libmlx.a
MLXFLAGS	= -framework OpenGL -framework AppKit
endif

CC			= cc
CFLAGS		= -Wall -Wextra
LFLAGS		= $(LIBFT_FLAGS) $(MLXFLAGS)
ifneq (nWerror, $(filter nWerror,$(MAKECMDGOALS)))
	CFLAGS	+= -Werror
endif
ifeq (sanitize, $(filter sanitize,$(MAKECMDGOALS)))
	CFLAGS	+= -fsanitize=address
endif

GIT_SUBM	= $(shell \
 sed -nE 's/path = +(.+)/\1\/.git/ p' .gitmodules | paste -s -)
RM			= rm -rf

all			: $(NAME)

bonus		: all

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(GIT_SUBM): %/.git: .gitmodules
	@git submodule init
	@git submodule update --remote $*

$(LIBFT)	:
ifeq (,$(wildcard $(LIBFT)))
			@echo "building libft..."
			@$(MAKE) -sC $(LIBFT_DIR) all
endif

rmlibft		:
			@echo "deleting libft build..."
			@$(MAKE) -sC $(LIBFT_DIR) fclean

$(MLX_LIB)	:
ifeq (,$(wildcard $(MLX_LIB)))
			@echo "building mlx..."
			@$(MAKE) -sC $(MLX_DIR) all
endif

rmmlx		:
			@echo "deleting mlx build..."
			@$(MAKE) -sC $(MLX_DIR) clean

$(NAME)		: $(GIT_SUBM) $(LIBFT) $(MLX_LIB) $(OBJ)
			$(CC) $(CFLAGS) $(INC) -o $(NAME) $(OBJ) $(LFLAGS)
			
clean		:
			$(RM) $(OBJ_DIR)

fclean		:
			$(RM) $(BUILD_DIR)
			$(RM) $(NAME)

fcleanall	: rmlibft rmmlx
			$(RM) $(BUILD_DIR)
			$(RM) $(NAME)

re			: fclean all

reall		: fcleanall all

nWerror: 
			@echo "WARN: Werror is disabled"
sanitize:
			@echo "WARN: fsanitize is enabled"
.PHONY: all clean fclean fcleanall re reall rmlibft rmmlx nWerror sanitize
