# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tima <tima@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/07 06:07:51 by tima              #+#    #+#              #
#    Updated: 2020/06/19 22:27:19 by tima             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PS = push_swap
NAME_CH = checker
NAME_VISU = visualizer

NAME_HEADER = push_swap.h
NAME_HVISU = ps_visu.h
NAME_LIB = libft.a

CC = gcc -g
СFLAGS = -Wall -Wextra -Werror

SRC_PS = push_swap.c \
save_stack.c validate.c \
calculate_cost.c pre_sorting.c \
algorithm.c algorithm_2.c \
operations.c free_func.c

SRC_CH = checker.c \
save_stack.c validate.c \
operations.c free_func.c

SRC_VISU = visual.c \
save_stack.c validate.c \
operations.c free_func.c \
sdl_init.c sdl_loop.c \
sdl_put_text.c sdl_drawing.c \
sdl_free_mem.c

INC_DIR = includes/
LIB_DIR = libft/
SRC_DIR = sources/
OBJ_DIR = objects/

# COLOR
RD = \033[031m
GR = \033[032m
YW = \033[033m
BL = \033[034m
PK = \033[035m
CN = \033[036m
EOC = \033[0m

HEADER = $(addprefix $(INC_DIR), $(NAME_HEADER))
LIBFT = $(addprefix $(LIB_DIR), $(NAME_LIB))
HEAD_VISU = $(addprefix $(INC_DIR), $(NAME_HVISU))

TMP_PS = $(addprefix $(SRC_DIR), $(SRC_PS:.c=.o))
TMP_CH = $(addprefix $(SRC_DIR), $(SRC_CH:.c=.o))
TMP_VISU = $(addprefix $(SRC_DIR), $(SRC_VISU:.c=.o))

INCLUDES = -I $(INC_DIR) -I $(LIB_DIR)includes
SDL2_LIB = -lSDL2 -lSDL2_image -lSDL2_ttf

all: $(LIBFT) $(NAME_PS) $(NAME_CH) $(NAME_VISU)

$(NAME_PS): $(TMP_PS) 
	@$(CC) $(СFLAGS) -o $(NAME_PS) $(TMP_PS) $(INCLUDES) libft/libft.a
	@printf "$(CN)<< Program $(NAME_PS) created >>$(EOC)\n"

$(NAME_CH): $(TMP_CH)
	@$(CC) $(СFLAGS) -o $(NAME_CH) $(TMP_CH) $(INCLUDES) libft/libft.a
	@printf "$(CN)<< Program $(NAME_CH) created >>$(EOC)\n"

$(NAME_VISU): $(TMP_VISU)
	@$(CC) $(СFLAGS) -o $(NAME_VISU) $(TMP_VISU) $(INCLUDES) $(SDL2_LIB) libft/libft.a
	@printf "$(CN)<< Program $(NAME_VISU) created >>$(EOC)\n"

%.o: %.c $(HEADER) $(HEAD_VISU)
	@$(CC) $(СFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C $(LIB_DIR)

clean:
	@make clean -C $(LIB_DIR)
	@rm -f $(TMP_PS) $(TMP_CH) $(TMP_VISU)
	@printf "$(YW)Push_swap: $(RD)Object files deleted!$(EOC)\n"

fclean: clean
	@make fclean -C $(LIB_DIR)
	@rm -f $(NAME_CH) $(NAME_PS) $(NAME_VISU)
	@printf "$(YW)Push_swap: $(RD)Binary and object files deleted!$(EOC)\n"

re: fclean all
