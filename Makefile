# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 09:44:02 by axcallet          #+#    #+#              #
#    Updated: 2023/02/27 13:44:39 by axcallet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

########### ARGUMENTS ##########

NAME	= pipex
CC		= clang
CFLAGS	= -Wall -Wextra -Werror -g

########## SOURCES ##########

SRC		= src/main.c	\
		src/process.c	\
		src/utils.c

OBJ		= $(SRC:.c=.o)
LIBFT	= libft

########## RULES ##########

RM		= rm -f

all: $(NAME)

%.o: %.c
		@$(CC) $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJ)
		@$(MAKE) -s -C $(LIBFT) bonus
		@$(CC) $(CFLAGS) -L $(LIBFT) -o $(NAME) $(OBJ) -l:libft.a

clean:
		@$(RM) $(OBJ)
		@$(MAKE) -s -C $(LIBFT) clean

fclean: clean
		@$(RM) $(NAME)
		@$(MAKE) -s -C $(LIBFT) fclean

re: fclean $(NAME)

.PHONY: all lib clean fclean re
