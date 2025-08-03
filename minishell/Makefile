# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abashir <abashir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/10 15:18:50 by abashir           #+#    #+#              #
#    Updated: 2025/08/03 00:00:00 by abashir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ================================= VARIABLES ================================ #

NAME		= minishell

# ================================ DIRECTORIES =============================== #

SRC_DIR		= src
OBJ_DIR		= obj
INCLUDE_DIR	= $(SRC_DIR)/include
LIBFT_DIR	= $(SRC_DIR)/libs/libft
GNL_DIR		= $(SRC_DIR)/libs/gnl

# =================================== PATHS ================================== #

SRCS		= $(SRC_DIR)/main.c \
			  $(SRC_DIR)/utils/free.c \
			  $(SRC_DIR)/utils/constructors.c \
			  $(SRC_DIR)/utils/signals.c \
			  $(SRC_DIR)/utils/free_tree.c \
			  $(SRC_DIR)/utils/utils.c \
			  $(SRC_DIR)/utils/path.c \
			  $(SRC_DIR)/utils/helper.c \
			  $(SRC_DIR)/utils/error.c \
			  $(SRC_DIR)/utils/nulterminate.c \
			  $(SRC_DIR)/utils/main_utils.c \
			  $(SRC_DIR)/syntax/check_input.c \
			  $(SRC_DIR)/syntax/check_syntax.c \
			  $(SRC_DIR)/syntax/syntax_utils.c \
			  $(SRC_DIR)/builtins/check_builtins.c \
			  $(SRC_DIR)/builtins/ft_pwd.c \
			  $(SRC_DIR)/builtins/ft_cd.c \
			  $(SRC_DIR)/builtins/ft_echo.c \
			  $(SRC_DIR)/builtins/ft_exit.c \
			  $(SRC_DIR)/builtins/ft_export.c \
			  $(SRC_DIR)/builtins/ft_export_utils.c \
			  $(SRC_DIR)/builtins/ft_unset.c \
			  $(SRC_DIR)/execution/execution.c \
			  $(SRC_DIR)/execution/handle_pipe.c \
			  $(SRC_DIR)/execution/handle_heredoc.c \
			  $(SRC_DIR)/execution/handle_redir.c \
			  $(SRC_DIR)/execution/handle_exec.c \
			  $(SRC_DIR)/execution/split_expand.c \
			  $(SRC_DIR)/execution/exe_utils.c \
			  $(SRC_DIR)/tokenization/gettoken.c \
			  $(SRC_DIR)/tokenization/token_utils.c \
			  $(SRC_DIR)/parsing/parsecmd.c \
			  $(SRC_DIR)/parsing/parse_heredoc.c \
			  $(SRC_DIR)/parsing/parse_redirs.c \
			  $(SRC_DIR)/parsing/parse_quotes.c \
			  $(SRC_DIR)/parsing/parse_expand.c \
			  $(SRC_DIR)/parsing/count_expand.c \
			  $(SRC_DIR)/parsing/parsing_utils.c \
			  $(SRC_DIR)/handling_env/init_env.c \
			  $(SRC_DIR)/handling_env/env_utils.c \
			  $(SRC_DIR)/handling_env/print_env.c \
			  $(SRC_DIR)/handling_env/reset_env.c \
			  $(GNL_DIR)/get_next_line.c \
			  $(GNL_DIR)/get_next_line_utils.c

OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# ================================= LIBRARIES ================================ #

LIBFT		= $(LIBFT_DIR)/libft.a

# ================================= COMPILER ================================= #

CC			= cc
CFLAGS		= -Wall -Werror -Wextra -g
INCLUDES	= -I$(INCLUDE_DIR) -I$(GNL_DIR) -I$(LIBFT_DIR)

# =============================== READLINE =================================== #

READLINE_FLAGS = -lreadline -lcurses

# Check for different readline locations (macOS compatibility)
ifeq ($(shell uname), Darwin)
	ifneq ($(shell brew --prefix readline 2>/dev/null),)
		READLINE_DIR = $(shell brew --prefix readline)
		READLINE_FLAGS += -L$(READLINE_DIR)/lib -I$(READLINE_DIR)/include
	endif
endif

# ================================== RULES =================================== #

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@echo "Linking $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(READLINE_FLAGS) -o $(NAME)
	@echo "✅ $(NAME) compiled successfully!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@echo "Building libft..."
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

clean:
	@echo "Cleaning object files..."
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	@echo "✅ Clean completed!"

fclean: clean
	@echo "Removing $(NAME)..."
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory
	@echo "✅ Full clean completed!"

re: fclean all

norm:
	@echo "Checking norminette..."
	@norminette $(SRCS) $(INCLUDE_DIR)
	@$(MAKE) -C $(LIBFT_DIR) norm --no-print-directory

# ================================== DEBUG =================================== #

debug: CFLAGS += -DDEBUG -fsanitize=address
debug: $(NAME)

valgrind: $(NAME)
	@echo "🔍 Running Valgrind with readline suppressions..."
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
		--suppressions=config/minishell.supp --log-file=valgrind.log ./$(NAME)
	@echo "📄 Valgrind output saved to valgrind.log"

# ================================= UTILITIES ================================ #

help:
	@echo "Available targets:"
	@echo "  all      - Build the project"
	@echo "  clean    - Remove object files"
	@echo "  fclean   - Remove object files and executable"
	@echo "  re       - Rebuild the project"
	@echo "  norm     - Check code with norminette"
	@echo "  debug    - Build with debug flags and AddressSanitizer"
	@echo "  valgrind - Run with valgrind (using suppressions)"
	@echo "  docs     - Open project documentation"
	@echo "  help     - Show this help message"

docs:
	@echo "📚 Opening project documentation..."
	@echo "Available documentation:"
	@echo "  • README.md           - Project overview and usage"
	@echo "  • docs/ARCHITECTURE.md - System design and components"
	@echo "  • docs/PARSING.md      - Parsing algorithm details"
	@echo "  • docs/TESTING.md      - Testing procedures and guidelines"
	@echo "  • CHANGELOG.md         - Version history and changes"
	@echo "  • CONTRIBUTING.md      - Contributing guidelines"
	@if command -v code >/dev/null 2>&1; then \
		code README.md docs/; \
	elif command -v vim >/dev/null 2>&1; then \
		vim README.md; \
	else \
		echo "📖 Use your preferred editor to view the documentation files."; \
	fi

.PHONY: all clean fclean re norm debug valgrind docs help
