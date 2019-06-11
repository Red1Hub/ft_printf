# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/14 01:08:54 by rmahjoub          #+#    #+#              #
#    Updated: 2019/06/10 17:37:07 by rmahjoub         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ME = libftprintf.a
all: $(NAME)
	$(NAME):
	    gcc -c popo.c libft/*.c ./float/floak.c grep_mem.c e_spec.c
		    ar rc libftprintf.a *.o
clean:
	    rm -rf *.o
fclean: clean
	    rm -rf libftprintf.a
re: fclean all 
