# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bykim <bykim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/02 19:11:12 by bykim             #+#    #+#              #
#    Updated: 2020/05/15 16:59:25 by bykim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS= -Wall -Wextra -Werror
INCS=../includes
SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)

all : $(OBJS)

%.o : %.c
	$(CC) -c $(CFLAGS) $< -I$(INCS)

clean :
	rm -f $(OBJS)

re : clean all
