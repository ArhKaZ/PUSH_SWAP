#============================= FILES PART =====================================
SRCS			=	push_swap.c \
					sort_five_nb.c \
					sort_four.c \
					sort_middle.c \
					sort_three_nb.c \
					stack_utils.c \
					push_swap_action.c \
					sort_chunk.c \

OBJS			=	${SRCS:%.c=$(OBJS_DIR)%.o}

OBJS_DIR		=	obj/

HEAD			=	push_swap.h

NAME			=	push_swap.a
#==============================================================================

#============================= BASH COMMAND ===================================
CC				=	cc

FLAG			=	-Wall -Werror -Wextra

ARC				=	ar rc

RM				=	rm -f -r
#==============================================================================

#============================= MK COMMAND =====================================
$(OBJS_DIR)%.o	:	%.c $(HEAD)
				$(CC) $(FLAG) -c $< -o $@

$(NAME)			:	$(OBJS_DIR) $(HEAD) $(OBJS)
				$(ARC) $(NAME) $(OBJS)

$(OBJS_DIR)		:
				mkdir -p $(OBJS_DIR)

all				:	$(HEAD) $(MK) $(NAME)

clean			:
				$(RM) $(OBJS) $(OBJS_DIR)

fclean			:	clean
				$(RM) $(NAME)

re				:	fclean $(NAME)

.PHONY			:	all clean fclean re
#==============================================================================