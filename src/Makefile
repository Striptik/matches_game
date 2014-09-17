NAME 		= allum1

SRC 		= allum1.c \
		init_game.c \
		init_game2.c \
		display.c \
		ia2.c \
		ia.c

OBJ 		= $(SRC:.c=.o)

CC		= cc

CP		= cp

RM		= rm -f

HFILE		= allum1.h

LIB		= -lmy -L../ -lncurses

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIB)
	$(CP) $(NAME) ../
	$(CP) $(HFILE) ../include

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(OBJ)
	$(RM) $(NAME)
	$(RM) ../$(NAME)

re: fclean all

.PHONY: all clean fclean re
