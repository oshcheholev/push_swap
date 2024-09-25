# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oshcheho <oshcheho@student.42vienna.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 13:24:31 by oshcheho          #+#    #+#              #
#    Updated: 2024/09/24 12:14:26 by oshcheho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

NAME = push_swap

AR		= ar rsc

SRC = ./push_swap.c ./push_swap_check.c ./push_swap_commands.c ./push_swap_sort.c ./push_swap_sort2.c

HEAD	= ./

OBJS	= ${SRC:.c=.o}

RM		= rm -f

LIB		= ranlib

LIBFT = libft

# PRINTF = printf

LIBFT_A	= ./libft/libft.a

# PRINTF_A = ./printf/libftprintf.a


${NAME}:	${OBJS}
	make -C $(LIBFT)
	# make -C $(PRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(PRINTF_A) $(LIBFT_A) -lmlx -lXext -lX11

${OBJS}:	%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

.c.o:
	${CC} ${CFLAGS} -c -I ${HEAD} $< -o ${<:.c-.o}

all:	$(NAME)

clean:
	make clean -C $(LIBFT)
	# make clean -C $(PRINTF)
	@$(RM) ${OBJS}

fclean:	clean
		make fclean -C $(LIBFT)
		# make fclean -C $(PRINTF)
		@$(RM) -f ${OBJS} $(NAME)

re:		fclean all

.PHONY: all clean fclean re