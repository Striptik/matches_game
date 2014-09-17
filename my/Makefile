
CC	= gcc -c

CCLIB	= ar rc

ASSEMB	= ranlib

RM	= rm -f

CP	= cp

NAME	= libmy.a

SRCS	= my_find_prime_sup.c \
	my_putstr.c \
	my_rputchar.c \
	my_rputstr.c \
	my_rput_nbr_base.c \
	my_rput_nbr_rec.c \
	my_rput_nbr.c \
        my_strcmp.c \
	my_strdup.c \
	my_strlen.c \
	my_tablen.c \
	my_nblen.c \
	my_getnbr.c \
	my_revstr.c \
	my_strcpy.c \
	my_strlowcase.c \
	my_isneg.c \
	my_showmem.c \
	my_str_isalpha.c \
	my_strncat.c \
	my_is_prime.c \
	my_showstr.c \
	my_str_islower.c \
	my_strncmp.c \
	my_power_rec.c \
	my_sort_int_tab.c \
	my_str_isnum.c \
	my_strncpy.c \
	my_putchar.c \
	my_square_root.c \
	my_str_isprintable.c \
	my_strstr.c \
	my_put_nbr.c \
	my_put_nbr_base.c \
	my_strcapitalize.c \
	my_str_isupper.c \
	my_strupcase.c \
	my_put_nbr_rec.c \
	my_strcat.c \
	my_strlcat.c \
	my_swap.c \
	my_realloc.c \
	my_printf.c \
	my_rprintf.c \
	my_printf_flags_char.c \
	my_rprintf_flags_char.c \
	my_printf_flags_int.c \
	my_rprintf_flags_int.c \
	my_printf_flags_convers.c \
	my_rprintf_flags_convers.c \
	get_next_line.c

HFILE	= my.h \
	my_printf.h \
	my_rprintf.h \
	get_next_line.h

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CCLIB) $(NAME) $(OBJS)
	$(ASSEMB) $(NAME)
	$(CP) $(NAME) ../
	$(CP) $(HFILE) ../include/

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(OBJS)
	$(RM) $(NAME)
	$(RM) ../$(NAME)

re: fclean all

.PHONY: all clean fclean re
