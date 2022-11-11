# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/31 16:46:58 by chenlee           #+#    #+#              #
#    Updated: 2022/11/11 14:45:18 by chenlee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libpushswap.a

MAIN			=	main.c

SRC				=	check_argv.c			\
					check_stack.c			\
					edge_case.c				\
					end_location.c			\
					error_msg.c				\
					ft_oddeven.c			\
					parse_cmd_arg.c			\
					power.c					\
					print_numb.c			\
					solve_stack.c			\
					solve_two.c				\
					solve_three.c			\
					solve_five.c			\
					merge.c					\
					merge_utils.c			\
					selection.c				\
					selection_utils_1.c		\
					selection_utils_2.c		\
					selection_to_a.c		\
					selection_to_b.c		\
					move_stack.c			\
					push.c					\
					rotate.c				\
					reverse_rotate.c		\
					swap.c					\
					checker.c				\
					b_push.c				\
					b_rotate.c				\
					b_rrotate.c				\
					b_swap.c				\
					get_next_line.c			\

LIBFT			=	libft
LIBFT_OBJS_DIR	=	libft/objects
LIBFT_OBJS		=	libft/objects/*.o

OBJS			=	$(addprefix $(OBJS_DIR), $(notdir $(SRC:.c=.o)))

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
OBJS_DIR		=	objects/
MAIN_DIR		=	./

SRCE_DIR		=	libft					\
					general_utils			\
					instructions			\
					solution				\
					solution/hard_coded		\
					solution/merge_sort		\
					solution/selection_sort	\
					bonus					\

vpath %.c $(SRCE_DIR)

all:				$(NAME) push_swap

tb:					checker
					ARG="33  56677 7 3 2 21 54"; ./push_swap $$ARG | ./checker $$ARG

t:					all
					./push_swap  29   5  58   2   3  40  62  27  19  55  42  64  50  10   1  35  31  24  71  7  70  32  21  53  48  68  41  34  17  61  39  12  26  66  13  67  45  57  52  49  69  38  60  59  43  33  54  37  63   6  28  47  22  51  44  65  18  11  36  15   9  30   4  56  20  25  23  14  46   8  16

$(OBJS_DIR)%.o:		%.c
					@mkdir -p $(OBJS_DIR)
					@echo "Compiling: $<"
					@$(CC) $(CFLAGS) -I. -c $< -o $@

push_swap:			main.c
					@$(CC) $(CFLAGS) -I. main.c -L. -lpushswap -Llibft -lft -o push_swap
					@echo "  ---------------------"
					@echo " |   Push Swap Done!   |"
					@echo "  ---------------------"

checker:			$(NAME) push_swap bonus.c
					@$(CC) $(CFLAGS) -I. bonus.c -L. -lpushswap -Llibft -lft -o checker
					@echo "  ---------------------"
					@echo " |     Bonus Done!     |"
					@echo "  ---------------------"

$(NAME):			$(OBJS)
					@make -C $(LIBFT)
					@ar rc $(NAME) $(OBJS)

clean:
					@rm -rf $(OBJS_DIR)
					@rm -rf $(LIBFT_OBJS_DIR) push_swap checker main.o push_swap.dSYM checker.dSYM
					@echo "Remove: $(OBJS_DIR)"
					@echo "Remove: $(LIBFT_OBJS_DIR)"

fclean:				clean
					@rm -rf $(NAME)
					@rm -rf libft/libft.a
					@echo "Remove: $(NAME)"
					@echo "Remove: libft/libft.a"

re:					fclean all
