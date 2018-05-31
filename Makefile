# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/29 16:05:39 by vkaznodi          #+#    #+#              #
#    Updated: 2018/05/29 16:05:39 by vkaznodi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

NOC=\033[0m
GRE=\033[32m
RED=\033[31m
YELL=\033[33m

cc = gcc
C_FLAGS = -Wall -Wextra -Werror -g
FRAM = -I minilibx -lmlx -framework OpenGL -framework AppKit -g

OBJ_PATH = ./obj/
LFT_PATH = ./libft/
INC_PATH = ./includes/

OBJ_NAME = $(SRC_NAME:.c=.o)
INC_NAME = fdf.h
SRC_NAME = main.c julia.c mend.c burningship.c put.c move.c

SRC = $(addprefix ,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

all: $(NAME)

$(NAME): $(OBJ)
		@make -C $(LFT_PATH)
		@$(CC) -o $(NAME) $(FRAM) -L $(LFT_PATH) -lft $^ -o $@ 
		@echo "$(GRE)FRACTOL:\t\tFRACTOL READY$(GRE)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
		@mkdir -p $(OBJ_PATH) 2> /dev/null || true
		@$(CC) $(C_FLAGS) $(INC) -o $@ -c $<

clean:
		@make -C $(LFT_PATH) clean
		@rm -rf $(OBJ_PATH)
		@echo "$(RED)FRACTOL:\t\tRemoving OBJ path: ./obj/$(RED)"

fclean: clean
		@make -C $(LFT_PATH) fclean
		@rm -f $(NAME)
		@echo "$(RED)FRACTOL:\t\tRemoving fractol executables$(RED)"

re: fclean all
.PHONY: all, $(NAME), clean, fclean, re
