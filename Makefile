# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osajide <osajide@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/05 15:41:59 by osajide           #+#    #+#              #
#    Updated: 2022/11/06 11:12:51 by osajide          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Werror -Wextra -Wall
NAME = get_next_line.a
SRC = get_next_line.c get_next_line_utils.c 
OBJ = $(SRC:.c=.o)
AR = ar -rcs
RM = rm -rf

%.o : %.c
	cc $(CFLAGS) -c $<

all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) $@ $^

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all