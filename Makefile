# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/10 18:31:01 by nsakanou          #+#    #+#              #
#    Updated: 2023/11/10 20:45:52 by nsakanou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

# Printf+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++#
PRINTFDIR	=	./printf
PRINTF		=	$(PRINTFDIR)/libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(PRINTFDIR)
RM = rm -f

SRCS =	

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)


$(NAME): $(OBJS) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $<

$(PRINTF):
	$(MAKE) -C $(PRINTFDIR) all

clean:
	$(MAKE) fclean -C $(PRINTFDIR)
	$(RM) $(OBJS)

fclean: clean
	@ make -C $(PRINTFDIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
