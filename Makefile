# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oshcheho <oshcheho@student.42vienna.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 13:24:31 by oshcheho          #+#    #+#              #
#    Updated: 2024/10/02 16:53:34 by oshcheho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

NAME = push_swap

AR		= ar rsc

SRC = ./push_swap.c ./push_swap_check.c ./push_swap_check_2.c ./push_swap_commands.c ./push_swap_sort.c ./push_swap_sort_new.c ./push_swap_sort_small.c ./push_swap_tools.c

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
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(PRINTF_A) $(LIBFT_A)

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