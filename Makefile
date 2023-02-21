#============================= FILES PART =====================================
SRCS			=	action.c			\
					check_entry.c		\
					chunk.c				\
					free_all.c			\
					get_arg.c			\
					get_little.c		\
					next_push_to_b.c	\
					opt_actions.c		\
					opt_actions_utils.c		\
					p_action.c \
					place_in_the_middle.c	\
					place_on_chunk.c	\
					push_swap.c			\
					push_swap_utils.c	\
					r_action.c \
					rr_action.c \
					s_action.c \
					sort_five_nb.c \
					sort_four_nb.c \
					sort_middle.c \
					sort_middle_utils.c	\
					sort_three_nb.c \
					stack_utils.c	\
					nb_move.c

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

$(OBJS_DIR)%.o	:	%.c $(HEAD) ${LIBA}
				$(CC) $(FLAG) -c $< -o $@

$(NAME)			: $(OBJS_DIR) $(HEAD) $(OBJS)
				$(CC) $(OBJS) $(LIBA) -o $(NAME)

$(OBJS_DIR)		:
				mkdir -p $(OBJS_DIR)

fsanitize		: $(OBJS_DIR) $(HEAD) $(OBJS)
				$(CC) $(FSA) $(OBJS) $(LIBA) -o $(NAME)

all				: $(HEAD) $(NAME)

${LIBA}			: FORCE
				make -C $(LIBFT)

FORCE:

clean			:
				$(RM) $(OBJS) $(OBJS_DIR)

cleanlib		:
				make fclean -C $(LIBFT)

fclean			:	clean cleanlib
				$(RM) $(NAME)

re				:	fclean $(NAME)

refs			:	fclean fsanitize

.PHONY			:	all clean fclean re force cleanlib
#==============================================================================