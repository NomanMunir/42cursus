# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abashir <abashir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/10 15:18:50 by abashir           #+#    #+#              #
#    Updated: 2023/12/10 08:15:25 by abashir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = 	main.c \
		utils/free.c \
		utils/constructors.c \
		utils/signals.c \
		utils/free_tree.c \
		utils/utils.c \
		utils/path.c \
		utils/helper.c \
		utils/error.c \
		utils/nulterminate.c \
		utils/main_utils.c \
		syntax/check_input.c \
		syntax/check_syntax.c \
		syntax/syntax_utils.c \
		builtins/check_builtins.c \
		builtins/ft_pwd.c \
		builtins/ft_cd.c \
		builtins/ft_echo.c \
		builtins/ft_exit.c \
		builtins/ft_export.c \
		builtins/ft_export_utils.c \
		builtins/ft_unset.c \
		execution/execution.c \
		execution/handle_pipe.c \
		execution/handle_heredoc.c \
		execution/handle_redir.c \
		execution/handle_exec.c \
		execution/split_expand.c \
		execution/exe_utils.c \
		tokenization/gettoken.c \
		tokenization/token_utils.c \
		parsing/parsecmd.c \
		parsing/parse_heredoc.c \
		parsing/parse_redirs.c \
		parsing/parse_quotes.c \
		parsing/parse_expand.c \
		parsing/count_expand.c \
		parsing/parsing_utils.c \
		handling_env/init_env.c \
		handling_env/env_utils.c \
		handling_env/print_env.c \
		handling_env/reset_env.c \
		libs/gnl/get_next_line.c \
		libs/gnl/get_next_line_utils.c \

OBJ =	$(SRC:.c=.o)

READLINE = -lreadline -L/usr/local/opt/readline/lib -I/usr/local/opt/readline/include

CC = cc

ARC = libs/libft/libft.a

INCLUDE = -I libs/gnl -I include -l readline -l curses

CFLAGS = -Wall -Werror -Wextra 

all: $(NAME)

$(NAME): $(OBJ) $(ARC)
	$(CC) $(CFLAGS) $(OBJ) $(READLINE) $(ARC) -o $(NAME) 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(ARC):
	make -C libs/libft
	
clean:
	rm -f $(OBJ)
	cd libs/libft && make clean

fclean: clean
	rm -f $(NAME)
	cd libs/libft && make fclean

re: fclean all

norm:
	norminette $(SRC)
	cd libs/libft && make norm
	
.PHONY: all clean fclean re norm $(LIBFT)
