# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/31 16:46:58 by chenlee           #+#    #+#              #
#    Updated: 2022/11/02 19:40:13 by chenlee          ###   ########.fr        #
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
CFLAGS			=	-Wall -Wextra -Werror
OBJS_DIR		=	objects/
MAIN_DIR		=	./

SRCE_DIR		=	libft					\
					general_utils			\
					instructions			\
					solution				\
					solution/hard_coded		\
					solution/merge_sort		\
					solution/selection_sort

vpath %.c $(SRCE_DIR)

all:				$(NAME) push_swap 

t:					all
					./push_swap 100   22   64   88   29   74   35   77   61   37   73   50   25   69   16   70   60   53   52   93    2   20   82    6   23   84   76   90   89   71    5   18   86   45   67   92   14   10   48    9   55   33   83   46   39   27   40   65   87   19   28    4   91    3    1   41    7   47   17   49   68   30    8   96   94   99   97   34   81   72   36   85   43   31   56   75   42   62   79   58   80   32   11   15   24   12   51   95   98   66   38   44   78   54   21   26   63   57   59   13
# ./push_swap 4  12  40  55  43   9  66  69  16  42  11  15  68  14  18  70  30  48  13  34  39  58  64   2   1  67  19  50  27  23  44  37  47  22  59  21  32  52  10  57  35  28  46  36  60  65  31  63  33  29  38   3  41  17  54  62  26  56  24   5  20   6  25   7  53  61  49   8  45  51  

$(OBJS_DIR)%.o:		%.c
					@mkdir -p $(OBJS_DIR)
					@echo "Compiling: $<"
					@$(CC) $(CFLAGS) -I. -c $< -o $@

push_swap:			main.c
					@$(CC) $(CFLAGS) -I. main.c -L. -lpushswap -Llibft -lft -o push_swap
					@echo "  ---------------------"
					@echo " |   Push Swap Done!   |"
					@echo "  ---------------------"

$(NAME):			$(OBJS)
					@make -C $(LIBFT)
					@ar rc $(NAME) $(OBJS)

bonus:				$(NAME)

clean:
					@rm -rf $(OBJS_DIR)
					@rm -rf $(LIBFT_OBJS_DIR) push_swap main.o push_swap.dSYM
					@echo "Remove: $(OBJS_DIR)"
					@echo "Remove: $(LIBFT_OBJS_DIR)"

fclean:				clean
					@rm -rf $(NAME)
					@rm -rf libft/libft.a
					@echo "Remove: $(NAME)"
					@echo "Remove: libft/libft.a"

re:					fclean all