# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rodmorei <rodmorei@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/19 16:50:29 by rodmorei          #+#    #+#              #
#    Updated: 2025/09/19 16:51:02 by rodmorei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo 
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
SRCS		= main.c check.c meal.c post_init.c pre_init.c routine.c utils.c 
OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
