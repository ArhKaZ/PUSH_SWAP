#============================= FILES PART =====================================
SRCS			=	push_swap_action.c \
					stack_utils.c \
					give_chunk.c	\
					sort_five_nb.c \
					sort_four.c \
					sort_middle.c \
					sort_three_nb.c \
					sort_chunk.c		\
					print.c 			\
					free_all.c 		\
					opt_actions.c		\
					action.c			\
					get_little.c		\
					place_on_chunk.c	\
					check_entry.c		\
					get_arg.c			\
					push_swap_utils.c	\
					sort_middle_utils.c	\
					place_in_the_middle.c	\
					next_push_to_b.c	\
					push_swap.c

OBJS			=	${SRCS:%.c=$(OBJS_DIR)%.o}

OBJS_DIR		=	obj/

HEAD			=	push_swap.h

NAME			=	push_swap

LIBFT			=	Libft_w_a

LIBA			=	Libft_w_a/libft.a
#==============================================================================

#============================= BASH COMMAND ===================================
CC				=	cc

FLAG			=	-Wall -Werror -Wextra

FSA				=	-fsanitize=address -g3

RM				=	rm -f -r

MAKE			=	make

MAKEALL			=	make all

MAKEFC			=	make fclean
#==============================================================================

#============================= MK COMMAND =====================================

$(OBJS_DIR)%.o	:	%.c $(HEAD)
				$(CC) $(FLAG) -c $< -o $@

$(NAME)			:	libft $(OBJS_DIR) $(HEAD) $(OBJS)
				$(CC) $(OBJS) $(LIBA) -o $(NAME)

$(OBJS_DIR)		:
				mkdir -p $(OBJS_DIR)

fsanitize		:	libft $(OBJS_DIR) $(HEAD) $(OBJS)
				$(CC) $(FSA) $(OBJS) $(LIBA) -o $(NAME)

all				: $(HEAD) $(NAME)

libft			:
				make -C $(LIBFT)
				make bonus -C $(LIBFT)

clean			:
				$(RM) $(OBJS) $(OBJS_DIR)

cleanlib		:
				make fclean -C $(LIBFT)

fclean			:	clean cleanlib
				$(RM) $(NAME)

re				:	fclean $(NAME)

.PHONY			:	all clean fclean re
#==============================================================================