# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/02 02:43:30 by ple-stra          #+#    #+#              #
#    Updated: 2022/05/06 05:25:08 by ple-stra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fdf

SRCS_DIR	= srcs
SRCS		= main.c errors.c debug.c free.c\
 parse_map.c parse_map2.c display_map.c\
 keys_events.c keys_events_arrows.c keys_events_plus_minus.c mouse_events.c\
 key_modes.c key_modes_axis.c\
 img_garbage.c rotation.c translation.c\
 3d_world.c\
 mlx_utils.c draw.c draw_utils.c gradients.c
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
ifeq (debug, $(filter debug,$(MAKECMDGOALS)))
	CFLAGS	+= -D KDEBUG=1
endif
ifeq (no_external_colors, $(filter no_external_colors,$(MAKECMDGOALS)))
	CFLAGS	+= -D USE_EXTERNAL_COLORS=0
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
debug:
			@echo "WARN: debug is enabled"
no_external_colors:
			@echo "WARN: external colors are disabled"
.PHONY: all clean fclean fcleanall re reall rmlibft rmmlx nWerror sanitize debug no_external_colors
