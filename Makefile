# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 14:06:13 by chenlee           #+#    #+#              #
#    Updated: 2022/08/10 20:37:43 by chenlee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libpushswap.a

MAIN			=	main.c

SRC				=	error_msg.c		\
					move_stack.c	\
					push.c			\
					rotate.c		\
					swap.c

LIBFT			=	libft
LIBFT_OBJS_DIR	=	libft/objects
LIBFT_OBJS		=	libft/objects/*.o

OBJS			=	$(addprefix $(OBJS_DIR), $(notdir $(SRC:.c=.o)))

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
OBJS_DIR		=	objects/

SRCE_DIR		=	libft			\
					general_utils	\
					instructions

vpath %.c $(SRCE_DIR)

$(OBJS_DIR)%.o:		%.c
					@mkdir -p $(OBJS_DIR)
					@echo "Compiling: $<"
					@$(CC) $(CFLAGS) -I. -c $< -o $@

$(NAME):			$(OBJS)
					@make -C $(LIBFT)
					@ar rc $(NAME) $(OBJS) $(LIBFT_OBJS)
					@echo "  ---------------------"
					@echo " |   Push Swap Done!   |"
					@echo "  ---------------------"

all:				$(NAME) main.c
					@$(CC) $(CFLAGS) -fsanitize=address -g3 -L. -lpushswap main.c -o push_swap

bonus:				$(NAME)

clean:
					@rm -rf $(OBJS_DIR)
					@rm -rf $(LIBFT_OBJS_DIR)
					@echo "Remove: $(OBJS_DIR)"
					@echo "Remove: $(LIBFT_OBJS_DIR)"

fclean:				clean
					@rm -rf $(NAME)
					@echo "Remove: $(NAME)"

re:					fclean all