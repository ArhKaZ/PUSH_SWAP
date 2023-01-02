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

NAME			=	push_swap

PRINTF			=	-C printf

LIBFT			=	-C libft

LIB				=	libft/libft.a printf/libftprintf.a
#==============================================================================

#============================= BASH COMMAND ===================================
CC				=	cc

FLAG			=	-Wall -Werror -Wextra

RM				=	rm -f -r

MAKE			=	make

MAKEALL			=	make all

MAKEFC			=	make fclean
#==============================================================================

#============================= MK COMMAND =====================================

$(OBJS_DIR)%.o	:	%.c $(HEAD)
				$(CC) $(FLAG) -c $< -o $@

$(NAME)			:	compl compp $(OBJS_DIR) $(HEAD) $(OBJS)
				compl
				$(CC) $(OBJS) $(LIB) -o $(NAME)

$(OBJS_DIR)		:
				mkdir -p $(OBJS_DIR)

all				: $(HEAD) $(NAME)

compp			:	$(MAKE) $(PRINTF)

compl			:	$(MAKE) $(LIBFT)

clean			:
				$(RM) $(OBJS) $(OBJS_DIR)

fclean			:	clean
				$(RM) $(NAME)

re				:	fclean $(NAME)

.PHONY			:	all clean fclean re
#==============================================================================