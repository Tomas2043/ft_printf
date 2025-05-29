# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: toandrad <toandrad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/13 12:23:27 by toandrad          #+#    #+#              #
#    Updated: 2025/05/29 13:56:30 by toandrad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

SRCS =	ft_printf.c \
		Utils/ft_putchar.c \
		Utils/ft_puthex.c \
		Utils/ft_putnbr.c \
		Utils/ft_putptr.c \
		Utils/ft_putstr.c \
		Utils/ft_putunsigned.c

OBJSDIR = Objects
SRC_NAMES = $(notdir $(SRCS))
OBJS = $(addprefix $(OBJSDIR)/, $(SRC_NAMES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(OBJSDIR)/%.o: %.c ft_printf.h | $(OBJSDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJSDIR)/%.o: Utils/%.c ft_printf.h | $(OBJSDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJSDIR):
	mkdir -p $(OBJSDIR)

clean:
	rm -rf $(OBJSDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
