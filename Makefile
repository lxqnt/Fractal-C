#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aquint <aquint@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/05 14:04:01 by aquint            #+#    #+#              #
#    Updated: 2017/11/15 16:32:18 by aquint           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROGRAM = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror 
GFLAGS = -I minilibx -L minilibx -lmlx -framework OpenGL -framework AppKit
MEMFLAGS = -fsanitize=address

GREEN = \x1b[32;01m
YELLOW = \x1b[33;01m
RED = \x1b[31;01m
NO_COLOR = \x1b[0m

SRCFIL += setup.c
SRCFIL += draw_fractal.c
SRCFIL += usage_error.c
SRCFIL += key_hooks.c
SRCFIL += mouse_hooks.c
SRCFIL += fractal_types.c
SRCFIL += set_color.c

MAIN = main.c

HEADER = fractal.h

OBJ = $(SRCFIL:.c=.o)

MAX			:= $(words $(OBJ))
increment	= $1 x
n			:= x
COUNTER		= $(words $n)$(eval n := $(call increment, $n))

all: $(PROGRAM)

$(OBJ): %.o: %.c
	@printf "$(YELLOW)\r>>COMPILING: [$(GREEN)%d$(YELLOW)/$(GREEN)%d$(YELLOW)]" $(COUNTER) $(MAX)
	@$(CC) -c $(CFLAGS) $< -o $@

$(PROGRAM): $(OBJ) $(MAIN) $(HEADER)
	@printf "\n"
	@echo "$(YELLOW)>>CREATING LIBRARY...$(NO_COLOR)"
	@$(MAKE) -C ./minilibx
	@$(MAKE) -C ./libft 
	@echo "$(YELLOW)>>CREATING $(PROGRAM)...$(NO_COLOR)"
	$(CC) $(MAIN) $(OBJ) -L libft -lft $(CFLAGS) $(GFLAGS) -o $(PROGRAM)
	@echo "$(GREEN)>>DONE!"

fractolclean:
	@rm -f $(OBJ)

clean:
	@echo "$(RED)>>DELETING OBJECT FILES..."
	$(MAKE) clean -C ./libft
	@rm -f $(OBJ)
	@echo "$(GREEN)>>DONE!"

fclean: clean
	@$(MAKE) fclean -C ./libft
	@echo "$(RED)>>DELETING $(PROGRAM)"
	@rm -f $(PROGRAM)
	@echo "$(GREEN)>>DONE!"

test: fractolclean all

re: fclean all

.PHONY: all clean fclean re
