# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jotto <jotto@student.42berlin.de>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/13 14:00:33 by lordamas          #+#    #+#              #
#    Updated: 2026/07/27 01:27:58 by jotto            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
CC          = cc
RM          = rm -f
LIBFT_DIR	= libft
FTPRINTF_DIR =
LIBFT		= $(LIBFT_DIR)/libft.a
CFLAGS      = -Wall -Wextra -Werror -I. -I$(LIBFT_DIR)

# Mandatory sources
SRC         = main.c check_input.c operations.c sorting_helpers.c sort_simple.c \
			sort_medium.c sort_complex.c sort_adaptive.c parse_to_array.c

# Objects
OBJ         = $(SRC:.c=.o)

# Default rule
all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Executable compilation
$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

# Compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

# Full clean
fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

# Total recompilation
re: fclean all

.PHONY: all clean fclean re
