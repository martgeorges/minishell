# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/24 14:12:26 by laichoun          #+#    #+#              #
#    Updated: 2024/10/24 09:47:20 by mgeorges         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I./includes
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
OBJ_DIR = ./objs

SRCS =	srcs/main_token.c srcs/creation_list.c srcs/free.c srcs/parsing.c\
	srcs/redirection_pipes.c srcs/error.c srcs/path.c\
	srcs/exec1_cmd.c srcs/tab_cmd.c srcs/builtins.c srcs/redirection.c\
	srcs/exec_pipelines_true.c srcs/process_pipe.c srcs/utils.c\
	srcs/parse_redir_only.c srcs/creation_env.c srcs/creation_tab_env.c\
	srcs/free_2.c srcs/exit.c srcs/pwd.c srcs/substitution_2.c srcs/substitution.c\
	srcs/path_2.c srcs/signals.c srcs/remove_quotes.c\
	srcs/cd_2.c srcs/echo.c srcs/export.c srcs/unset.c srcs/creation_export_list.c\
	srcs/parsing_utils.c srcs/utils2_main.c\
#SRCS = 

OBJS = $(patsubst srcs/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Colors
YELLOW = \033[1;33m
GREEN = \033[1;32m
RESET = \033[0m

LFLAGS = -L$(LIBFT_DIR) -lft -lreadline

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@echo "\n$(YELLOW)Compiling $(NAME)...$(RESET)\n"
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LFLAGS) -o $(NAME)
	@echo "\n$(GREEN)$(NAME) compiled successfully!$(RESET)\n"

$(OBJ_DIR)/%.o: srcs/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@echo "\n$(YELLOW)Compiling libft...$(RESET)\n"
	@if ! make -C $(LIBFT_DIR) ; then echo "$(YELLOW)Error compiling libft$(RESET)"; exit 1; fi

clean:
	@echo "\n$(YELLOW)Cleaning libft and objs directory...$(RESET)\n"
	@make -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "\n$(YELLOW)Removing executables and libraries...$(RESET)\n"
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
