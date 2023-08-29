# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/31 19:54:01 by mrizakov          #+#    #+#              #
#    Updated: 2023/03/31 19:54:02 by mrizakov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = push_swap

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

CC = cc

SRC = general_utils.c general_utils2.c general_utils3.c PS_LLutils1.c \
PS_LLutils3.c push_swap.c pushswap_operations.c pushswap_operations2.c \
sorting_algos.c sorting_algos2.c sorting_algos3.c PS_LLutils2.c

OBJ=$(SRC:.c=.o)


all:$(NAME)

$(NAME):$(OBJ)
	$(CC) $(CFLAGS) $? -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
