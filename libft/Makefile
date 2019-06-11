# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/10 22:37:30 by rmahjoub          #+#    #+#              #
#    Updated: 2018/10/13 10:00:57 by rmahjoub         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = prog

all:$(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror *.c
	ar rc libft.a *.o

clean:
	rm -f *o
	rm -f *.h.gch

fclean: clean
	rm -f libft.a

re: fclean all
