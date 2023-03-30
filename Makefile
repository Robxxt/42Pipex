# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/26 15:16:07 by rdragan           #+#    #+#              #
#    Updated: 2023/03/29 18:58:53 by rdragan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := pipex
SRC := 	main.c \
		ft_split.c \
		ft_split_utils.c \
		ft_strjoin.c \
		pipex_utils.c\
		quotation_utils.c
OBJ := $(SRC:%.c=%.o)
CFLAGS := -Wall -Wextra -Werror

.PHONY: all, clean, fclean, re

all: $(NAME) $(OBJ)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -Rf $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all