# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/10 18:31:01 by nsakanou          #+#    #+#              #
#    Updated: 2024/02/07 20:21:00 by nsakanou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

INCLUDES = -I ./includes -I ./srcs
CC = cc
CFLAGS = -Wall -Wextra -Werror $(INCLUDES)
RM = rm -f

SRCS =	srcs/main.c \
		srcs/philo/init.c \
		srcs/philo/philo_actions.c \
		srcs/philo/philo_atoi.c \
		srcs/philo/philo_utils.c \
		srcs/philo/thread.c \
	#	srcs/philo_bonus/philo_bonus.c

OBJS = $(SRCS:%.c=%.o)


.PHONY: all clean fclean re

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
