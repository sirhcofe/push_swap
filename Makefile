# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 14:06:13 by chenlee           #+#    #+#              #
#    Updated: 2022/08/21 21:25:52 by chenlee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libpushswap.a

MAIN			=	main.c

SRC				=	check_argv.c		\
					error_msg.c			\
					if_sorted.c			\
					print_numb.c		\
					solve_stack.c		\
					solve_three.c		\
					selection.c			\
					move_stack.c		\
					push.c				\
					rotate.c			\
					reverse_rotate.c	\
					swap.c
#					merge.c


LIBFT			=	libft
LIBFT_OBJS_DIR	=	libft/objects
LIBFT_OBJS		=	libft/objects/*.o

OBJS			=	$(addprefix $(OBJS_DIR), $(notdir $(SRC:.c=.o)))

CC				=	gcc
CFLAGS			=	-Wall -Wextra
OBJS_DIR		=	objects/

SRCE_DIR		=	libft			\
					general_utils	\
					instructions	\
					solution

vpath %.c $(SRCE_DIR)

all:				$(NAME) main.c
					$(CC) $(CFLAGS) main.c -L. -lpushswap -Llibft -lft -o push_swap

t:					all
					./push_swap 1 2 3
					./push_swap 3 1 2
					./push_swap 2 3 1
					./push_swap 1 3 2
					./push_swap 2 1 3
					./push_swap 3 2 1
					
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