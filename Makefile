# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abahmani <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/16 14:49:32 by abahmani          #+#    #+#              #
#    Updated: 2021/12/14 16:01:55 by brhajji-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_strlen.c ft_isalpha.c\
		  ft_atoi.c ft_calloc.c ft_strdup.c\
		  ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c\
		  ft_itoa.c	ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c\
		  ft_putendl_fd.c ft_putnbr_fd.c push_swap.c init.c input_check.c\
		  ft_lstnew.c ft_lstadd_front.c

OBJS			=	${SRCS:.c=.o}

OBJSBONUS		= 	${BONUS:.c=.o}

NAME			=	push_swap

CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror -I.

RM				=	rm -f

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
		ar -rcs ${NAME} ${OBJS}

bonus:	${OBJS} ${OBJSBONUS}
		ar -rcs ${NAME} ${OBJS} ${OBJSBONUS}

all:		${NAME}

clean:			
	${RM} ${OBJS} ${OBJSBONUS}

fclean:		clean			
		${RM} ${NAME}

re:			fclean all

.PHONY: 	all clean fclean re
