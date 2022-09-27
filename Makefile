# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/31 16:46:58 by chenlee           #+#    #+#              #
#    Updated: 2022/09/26 16:55:10 by chenlee          ###   ########.fr        #
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
					./push_swap -998 363 620 -76 807 348 450 56 145 648 -268 -848 590 -716 -496 -727 223 -900 -603 -187 -884 496 759 -429 939 659 455 -39 -828 825 -498 345 863 241 -516 -940 912 592 902 -24 -252 -955 386 568 717 -944 -502 -868 865 -972 -32 -986 718 181 342 -797 684 629 566 498 -800 -924 546 842 -723 854 638 542 -545 417 -417 -423 479 607 -613 500 -361 -857 887 543 862 403 -421 -856 264 -2 -515 -759 792 16 95 893 -210 600 -206 480 637 489 -548 -380
					
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