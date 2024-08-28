# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oshcheho <oshcheho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/04 14:46:25 by oshcheho          #+#    #+#              #
#    Updated: 2024/08/16 13:00:15 by oshcheho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

AR		= ar rsc

SRC		= ./ft_isalpha.c ./ft_isdigit.c ./ft_isalnum.c ./ft_isascii.c ./ft_isprint.c ./ft_strlen.c ./ft_memset.c ./ft_bzero.c ./ft_memcpy.c ./ft_memmove.c ./ft_strlcpy.c ./ft_strlcat.c ./ft_toupper.c ./ft_tolower.c ./ft_strchr.c ./ft_strrchr.c ./ft_strncmp.c ./ft_memchr.c ./ft_memcmp.c ./ft_strnstr.c ./ft_atoi.c ./ft_calloc.c ./ft_strdup.c ./ft_substr.c ./ft_strjoin.c ./ft_strtrim.c ./ft_itoa.c ./ft_strmapi.c ./ft_striteri.c ./ft_putchar_fd.c ./ft_putstr_fd.c ./ft_putendl_fd.c ./ft_putnbr_fd.c  ./ft_split.c

BONUS_SRC		= ./ft_isalpha.c ./ft_isdigit.c ./ft_isalnum.c ./ft_isascii.c ./ft_isprint.c ./ft_strlen.c ./ft_memset.c ./ft_bzero.c ./ft_memcpy.c ./ft_memmove.c ./ft_strlcpy.c ./ft_strlcat.c ./ft_toupper.c ./ft_tolower.c ./ft_strchr.c ./ft_strrchr.c ./ft_strncmp.c ./ft_memchr.c ./ft_memcmp.c ./ft_strnstr.c ./ft_atoi.c ./ft_calloc.c ./ft_strdup.c ./ft_substr.c ./ft_strjoin.c ./ft_strtrim.c ./ft_itoa.c ./ft_strmapi.c ./ft_striteri.c ./ft_putchar_fd.c ./ft_putstr_fd.c ./ft_putendl_fd.c ./ft_putnbr_fd.c  ./ft_split.c ./ft_lstnew_bonus.c ./ft_lstadd_front_bonus.c ./ft_lstsize_bonus.c ./ft_lstlast_bonus.c ./ft_lstadd_back_bonus.c ./ft_lstdelone_bonus.c ./ft_lstiter_bonus.c ./ft_lstclear_bonus.c ./ft_lstmap_bonus.c


HEAD	= ./

OBJS	= ${SRC:.c=.o}

BONUS_OBJS	= ${BONUS_SRC:.c=.o}

RM		= rm -f

LIB		= ranlib

CC		= cc

BONUS	= bonus

CFLAGS		= -Wall -Wextra -Werror

${NAME}:	${OBJS}
	${AR} ${NAME} ${OBJS}
	${LIB} ${NAME}

${BONUS}:	${BONUS_OBJS}
	${AR} ${NAME} ${BONUS_OBJS}
	${LIB} ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

all:	$(NAME)

bonus:	$(BONUS)

clean:			
	@$(RM) ${OBJS} ${BONUS_OBJS}

fclean:	clean
		@$(RM) -f ${NAME} libft.co

re:		fclean all

.PHONY: all clean fclean re