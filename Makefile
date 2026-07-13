# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lordamas <lordamas@student.42berlin.d>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/13 14:00:33 by lordamas          #+#    #+#              #
#    Updated: 2026/07/13 14:03:42 by lordamas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -f
AR          = ar rcs

# Mandatory sources
SRC         = 

# Objects
OBJ         = $(SRC:.c=.o)

# Default rule
all: $(NAME)

# Library compilation
$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

# Rule to compile .o files with the correct flags
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