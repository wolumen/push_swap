# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 13:00:21 by jpreissn          #+#    #+#              #
#    Updated: 2021/12/14 13:00:21 by jpreissn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRC		=	push_swap_main.c \
			push_swap_utils.c \
			push_swap_stack_utils.c \
			push_swap.c \
			mv_push.c \
			mv_rotate.c \
			mv_rev_rotate.c \
			mv_swap.c \
			small_sort.c \
			bucket_sort.c

OBJ		=	$(SRC:%.c=$O%.o)

S		=	src/
O		=	obj/
I		=	inc/

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

VAL        := valgrind
VAL_FLAGS  := --leak-check=full --show-leak-kinds=all --tool=memcheck --log-file=valgrind-out.txt

ARGS =	3 5 7 1 2

.PHONY: clean fclean re 

all: $(NAME)

$(OBJ): $O%.o: $S%.c
	@mkdir -p $O
	$(CC) $(CFLAGS) -I$I -c $< -o $@

$(NAME): $(OBJ) Makefile
	$(CC) $(OBJ) -o $@

clean:
	rm -f $(OBJ)
	rm -rf $O

fclean: clean
	rm -f $(NAME)

re: fclean all

test: re
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)
	./push_swap $(ARGS)

memcheck: re
	clear
	$(VAL) $(VAL_FLAGS) ./$(NAME) $(ARGS)