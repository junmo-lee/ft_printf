.DEFAULT_GOAL := all

NAME	= libftprintf.a

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
CDEF	= -MMD -MP

AR		= ar
ARFLAGS	= -rcs

LIBFT = ./libft/libft.a
LIBFT_DIR = libft/

INC		= ft_printf.h

SRCS	= ft_printf.c print_chars.c print_dec.c print_hex.c \
		itoa_base.c print_pointer.c uitoa.c 
SRCS_B	= 

OBJS	= $(SRCS:.c=.o)
OBJS_B	= $(SRCS_B:.c=.o)

DEF		= $(SRCS:.c=.d) $(SRCS_B:.c=.d)
-include $(DEP)

all: LAST_ALL
bonus: LAST_BONUS

clean :
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS) $(OBJS_B) $(DEF)

fclean :
	make -C $(LIBFT_DIR) fclean
	rm -f $(OBJS) $(OBJS_B) $(DEF) $(NAME)

re :
	make fclean
	make all

$(LIBFT) :
	make -C $(LIBFT_DIR) all

$(NAME) :
	make all

%.o : %.c
	$(CC) $(CFLAGS) $(CDEF) -c $< -o $@ -I $(INC)

.PHONY : all bonus clean fclean re

LAST_ALL: $(LIBFT) $(OBJS)
	rm -f LAST_BONUS
	cp $(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $^
	touch $@

LAST_BONUS: $(LIBFT) $(OBJS) $(OBJS_B)
	rm -f LAST_ALL
	cp $(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $^
	touch $@