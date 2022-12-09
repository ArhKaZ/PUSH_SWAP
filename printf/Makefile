#============================= FILES PART =====================================
SRCS			=	ft_putchar.c  \
					ft_putnbr_10.c \
					ft_putnbr_16.c \
					ft_putpointer.c \
					ft_putstr.c		\
					ft_printf.c

OBJS			=	${SRCS:%.c=$(OBJS_DIR)%.o}

OBJS_DIR		=	obj/

HEAD			=	ft_printf.h

NAME			=	libftprintf.a

MK				=	Makefile
#==============================================================================

#============================= BASH COMMAND ===================================
CC				=	cc

FLAG			=	-Wall -Werror -Wextra

ARC				=	ar rc

RM				=	rm -f -r
#==============================================================================

#============================= MK COMMAND =====================================
$(OBJS_DIR)%.o	:	%.c $(HEAD) $(MK)
				$(CC) $(FLAG) -c $< -o $@

$(NAME)			:	$(OBJS_DIR) $(MK) $(HEAD) $(OBJS)
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
