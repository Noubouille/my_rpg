NAME	= my_rpg

CC	= gcc

RM	= rm -f

SRCS	= ./src/main.c	\
		  ./src/game.c \
		  ./src/cave.c \
		  ./src/nb_tochar.c	\
		  ./src/my_putstr.c	\
		  ./src/my_putchar.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -l csfml-audio -l csfml-graphics -l csfml-network -l csfml-system -l csfml-window -o $(NAME)
	 $(RM) $(OBJS)
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
