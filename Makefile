# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/31 16:46:58 by chenlee           #+#    #+#              #
#    Updated: 2022/09/28 22:01:54 by chenlee          ###   ########.fr        #
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
					./push_swap  1 3 5 2 4
					
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