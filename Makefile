# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bykim <bykim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/02 19:11:12 by bykim             #+#    #+#              #
#    Updated: 2020/05/08 17:01:11 by bykim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS= -Wall -Wextra -Werror

NAME=libftprintf.a
SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)
SUBSRCS=./utility/*.c
SUBOBJS=$(SUBSRCS:.c=.o)
INCS=includes

all : $(NAME)

%.o : %.c
	$(CC) -c $(CFLAGS) $< -I$(INCS)

$(NAME) : $(OBJS)
	make -C utility
	ar -rc $@ $(OBJS) $(SUBOBJS)

clean :
	rm -f $(OBJS)
	make clean -C utility

fclean : clean
	rm -f $(NAME)

re : fclean all
