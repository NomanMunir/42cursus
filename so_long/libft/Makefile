# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abashir <abashir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/03 12:33:13 by nmunir            #+#    #+#              #
#    Updated: 2023/09/04 16:11:04 by abashir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = 	ft_isalpha.c ft_memset.c ft_bzero.c ft_isascii.c ft_isdigit.c ft_memcpy.c ft_strlen.c \
		ft_toupper.c ft_tolower.c ft_isprint.c ft_isalnum.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
		ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_atoi.c ft_memmove.c ft_memchr.c ft_memcmp.c \
		ft_calloc.c  ft_strdup.c ft_substr.c ft_strjoin.c ft_itoa.c ft_strtrim.c ft_strmapi.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c ft_split.c \

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra

all:$(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ) $(BOBJ)
	
fclean: clean
	rm -f $(NAME)

re: fclean all
	
.PHONY: all clean fclaen re