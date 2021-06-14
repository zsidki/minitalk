# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/30 18:01:21 by zsidki            #+#    #+#              #
#    Updated: 2021/06/03 21:52:16 by zsidki           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all fclean clean re
CC = gcc
flags = -Wall -Wextra -Werror
SRCSC = client.c
SRCSS = server.c src/ft_putnbr.c
SRCSC_B = bonus/client.c src/*.c
NAME  = minitalk
NAME_B = minitalk_b

all : $(NAME)

$(NAME):
	@$(CC) $(flags) $(SRCSC) -o client
	@$(CC) $(flags) $(SRCSS) -o server

bonus : $(NAME_B)

$(NAME_B):
	@$(CC) $(flags) $(SRCSC_B) -o client_b
	@$(CC) $(flags) $(SRCSS) -o server
	
clean:
	@rm -rf client server

fclean: clean

re: fclean all
