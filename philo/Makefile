# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/17 21:19:56 by flverge           #+#    #+#              #
#    Updated: 2024/04/02 09:14:39 by flverge          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME = philo

# Compiler
CC = cc

# Compiler options
CFLAGS = -Wall -Wextra -Werror -pthread -g

# Asan flag
# CFLAGS = -Wall -Wextra -Werror -fsanitize=address -static-libsan

# push_swap files
SRC_DIR := src
SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := ${SRC:.c=.o}

# Includes
INC =	-I ./includes/

# Colors
RESET = \033[0m
BOLD = \033[1m
RED = \033[91m
GREEN = \033[92m
YELLOW = \033[33m
ORANGE = \033[93m
BLUE = \033[94m

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# remettre flags
$(NAME): $(OBJ)
	@echo "$(BOLD)$(RED)🛠️            Compiling Philosophers...      🛠️$(RESET)"
	@echo "\n"
	@$(CC) $(CFLAGS) $(OBJ) $(INC) -o $(NAME)
	@echo "🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳"
	@echo "$(BOLD)$(GREEN)🥳    Philosophers fully compiled, ready to use     🥳$(RESET)"
	@echo "🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳"
	@echo "\n"

clean:
	@rm -f $(OBJ)
	@echo "$(BOLD)$(ORANGE)🌀     Cleaned .o philosophers's files   🌀$(RESET)"
	@echo "\n"
	@echo "$(BOLD)$(BLUE)-----------------------$(RESET)"
	@echo "\n"

fclean: clean
	@rm -f $(NAME)
	@echo "$(BOLD)$(ORANGE)🌀        Cleaned philo exec      🌀$(RESET)"
	@echo "\n"
	@echo "$(BOLD)$(BLUE)-----------------------$(RESET)"
	@echo "\n"

re: fclean all

.PHONY: all clean fclean re