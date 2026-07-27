# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lordamas <lordamas@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/09 13:28:14 by lordamas          #+#    #+#              #
#    Updated: 2026/07/09 13:29:31 by lordamas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = libftprintf.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -f
AR          = ar rcs

# Fontes obrigatórias
SRC         = ft_printf.c ft_putnbr_count.c ft_putstr_count.c

# Objetos
OBJ         = $(SRC:.c=.o)

# Regra padrão
all: $(NAME)

# Compilação da biblioteca
$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

# Regra para compilar os .o com as flags corretas
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza de objetos
clean:
	$(RM) $(OBJ)

# Limpeza completa
fclean: clean
	$(RM) $(NAME)

# Recompilação total
re: fclean all

.PHONY: all clean fclean re
