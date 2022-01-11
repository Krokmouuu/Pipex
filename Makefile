# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/06 10:37:35 by bleroy            #+#    #+#              #
#    Updated: 2022/01/11 17:19:33 by bleroy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = pipex.c \
	   Utils/ft_split.c \
	   Utils/ft_strjoin.c \
	   Utils/ft_strnstr.c \

OBJS = ${SRCS:.c=.o}

NAME = pipex

CC = cc

CFLAGS = -Wall -Werror -Wextra -fsanitize=address

RM = rm -f

all: ${NAME}

${NAME}: ${OBJS}
		$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

clean :
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re :    fclean all

.PHONY: all clean fclean re