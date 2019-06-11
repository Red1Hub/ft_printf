# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/14 01:08:54 by rmahjoub          #+#    #+#              #
#    Updated: 2019/06/11 15:29:27 by rmahjoub         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ME = libftprintf.a
all: $(NAME)
	$(NAME):
	    gcc -c srcs/*.c libft/*.c
		    ar rc libftprintf.a *.o
clean:
	    rm -rf *.o
fclean: clean
	    rm -rf libftprintf.a
re: fclean all 
