# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lordamas <lordamas@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/13 14:00:33 by lordamas          #+#    #+#              #
#    Updated: 2026/07/16 17:18:32 by lordamas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -f

# Mandatory sources
SRC         = main.c check_input.c

# Objects
OBJ         = $(SRC:.c=.o)

# Default rule
all: $(NAME)

# Executable compilation
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

# Compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	$(RM) $(OBJ)

# Full clean
fclean: clean
	$(RM) $(NAME)

# Total recompilation
re: fclean all

.PHONY: all clean fclean re
