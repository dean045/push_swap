# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brhajji- <brhajji-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/16 14:49:32 by abahmani          #+#    #+#              #
#    Updated: 2022/01/26 16:59:48 by brhajji-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = ./srcs

SRCS	= push_swap.c push.c init.c ft_lstnew.c ft_lstadd_back.c\
			ft_lstadd_front.c rotate.c rrotate.c swap.c ft_lstlast.c\
			ft_lstsize.c ft_atoi.c input_check.c ft_strlen.c tri.c\
			is_sort.c tri2.c ft_split.c ft_strtrim.c ft_substr.c ft_strchr.c ft_free.c

OBJS			=	$(addprefix $(SRC_DIR)/, $(SRCS:%.c=%.o))

OBJSBONUS		= 	${BONUS:.c=.o}

NAME			=	push_swap

CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror

RM				=	rm -f

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

bonus:	${OBJS} ${OBJSBONUS}
		ar -rcs ${NAME} ${OBJS} ${OBJSBONUS}

all:		${NAME}

clean:			
	${RM} ${OBJS} ${OBJSBONUS}

fclean:		clean			
		${RM} ${NAME}

re:			fclean all

.PHONY: 	all clean fclean re
