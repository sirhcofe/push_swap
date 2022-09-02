# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/31 16:46:58 by chenlee           #+#    #+#              #
#    Updated: 2022/09/02 16:06:59 by chenlee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libpushswap.a

MAIN			=	main.c

SRC				=	check_argv.c			\
					check_stack.c			\
					error_msg.c				\
					print_numb.c			\
					solve_stack.c			\
					solve_two.c				\
					solve_three.c			\
					merge.c					\
					merge_utils.c			\
					selection.c				\
					selection_to_a.c		\
					selection_to_b.c		\
					move_stack.c			\
					push.c					\
					rotate.c				\
					reverse_rotate.c		\
					swap.c


LIBFT			=	libft
LIBFT_OBJS_DIR	=	libft/objects
LIBFT_OBJS		=	libft/objects/*.o

OBJS			=	$(addprefix $(OBJS_DIR), $(notdir $(SRC:.c=.o)))

CC				=	gcc
CFLAGS			=	-Wall -Wextra
OBJS_DIR		=	objects/

SRCE_DIR		=	libft					\
					general_utils			\
					instructions			\
					solution				\
					solution/hard_coded		\
					solution/merge_sort		\
					solution/selection_sort

vpath %.c $(SRCE_DIR)

all:				$(NAME) main.c
					$(CC) $(CFLAGS) main.c -L. -lpushswap -Llibft -lft -o push_swap

t:					all
					./push_swap 8   3  10  15   5  17   1  13   6  11   7   9   2  16  14  12   4  20  19  18 
# ./push_swap 38 53 18 61 2 17 88 91 14 32 41 81 13 6 80 37 57 48 1 67 58 28 95 56 65 29 59 99 44 50 3 46 89 82 93 23 39 79 16 26 69 92 68 45 85 43 49 11 25 55 54 83 31 21 24 52 90 72 74 36 27 34 100 51 66 78 87 64 12 33 5 20 4 71 15 8 63 70 30 35 7 10 76 97 22 77 47 84 9 86 94 98 40 42 73 62 96 75 60 19
# ./push_swap 1 3 4 2
# ./push_swap 1 4 2 3
# ./push_swap 1 4 3 2
# ./push_swap 2 1 3 4
# ./push_swap 2 1 4 3
# ./push_swap 2 3 1 4
# ./push_swap 2 3 4 1
# ./push_swap 2 4 1 3
# ./push_swap 2 4 3 1
# ./push_swap 3 1 2 4
# ./push_swap 3 1 4 2 
# ./push_swap 3 2 1 4
# ./push_swap 3 2 4 1
# ./push_swap 3 4 1 2
# ./push_swap 3 4 2 1
# ./push_swap 4 1 2 3
# ./push_swap 4 1 3 2
# ./push_swap 4 2 1 3
# ./push_swap 4 2 3 1
# ./push_swap 4 3 2 1
# ./push_swap 4 3 1 2
					
$(OBJS_DIR)%.o:		%.c
					@mkdir -p $(OBJS_DIR)
					@echo "Compiling: $<"
					@$(CC) $(CFLAGS) -I. -c $< -o $@

$(NAME):			$(OBJS)
					@make -C $(LIBFT)
					@ar rc $(NAME) $(OBJS)
					@echo "  ---------------------"
					@echo " |   Push Swap Done!   |"
					@echo "  ---------------------"

bonus:				$(NAME)

clean:
					@rm -rf $(OBJS_DIR)
					@rm -rf $(LIBFT_OBJS_DIR) push_swap push_swap.dSYM
					@echo "Remove: $(OBJS_DIR)"
					@echo "Remove: $(LIBFT_OBJS_DIR)"

fclean:				clean
					@rm -rf $(NAME)
					@rm -rf libft/libft.a
					@echo "Remove: $(NAME)"
					@echo "Remove: libft/libft.a"

re:					fclean all