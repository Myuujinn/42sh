##
## Makefile for libtech in /home/swann/Projets/libtech
##
## Made by Swann JAUNASSE
## Login   <swann.jaunasse@epitech.eu>
##
## Started on  Wed Dec 28 17:59:37 2016 Swann JAUNASSE
## Last update Wed Apr 19 22:48:50 2017 Swann JAUNASSE
##

############# COLORS ############

RESET		=       "\033[00m"
BLACK           =       "\033[0;30m"
RED             =       "\033[0;31m"
GREEN           =       "\033[0;32m"
BROWN           =       "\033[0;33m"
BLUE            =       "\033[0;34m"
MAGENTA         =       "\033[0;35m"
CYAN            =       "\033[1;36m"
LIGHT_BLACK     =       "\033[1;30m"
LIGHT_RED       =       "\033[1;31m"
LIGHT_GREEN     =       "\033[1;32m"
LIGHT_BROWN     =       "\033[1;33m"
LIGHT_BLUE      =       "\033[1;34m"
LIGHT_MAGENTA   =       "\033[1;35m"
LIGHT_CYAN      =       "\033[1;36m"

############# VARS ##############

NAME		=	LibTech

LIB		=	../libtech.a

INC		=	-I. -I./inc/

SRC		=	./src/char1.c		\
			./src/char2.c		\
			./src/list.c		\
			./src/string1.c		\
			./src/string2.c		\
			./src/string3.c		\
			./src/string4.c		\
			./src/strlist1.c	\
			./src/strlist2.c	\
			./src/parse.c		\
			./src/print.c		\
			./src/error.c		\
			./src/crash.c		\
			./src/contracts1.c	\
			./src/contracts2.c

OBJ		=	$(SRC:.c=.o)

CFLAGS		+=	-Wall -Wextra -Werror -pedantic
CFLAGS		+=	$(INC)
MAKEFLAGS       +=      --no-print-directory

ECHO		=	echo -e
BUILD		=	ar rc
REMOVE		=	rm -f

############# RULES #############

all:		$(LIB)

debug:		CFLAGS += -g
debug:		$(LIB)

fast:		CFLAGS += -Ofast -fno-tree-loop-distribute-patterns
fast:		$(LIB)

$(LIB):
		@ $(ECHO) $(GREEN)"-=> "$(BLUE)"Compiling "$(NAME)" ..."$(RESET)
		@ $(MAKE) $(OBJ)
		@ $(ECHO) $(GREEN)"-=> "$(BLUE)"Building "$(NAME)" ..."$(RESET)
		$(BUILD) $(LIB) $(OBJ)
.c.o:
		@ $(CC) $(CFLAGS) -c $< -o $@ &&			\
		$(ECHO) $(GREEN)"-=> "$(GREEN)"[OK] "$(RESET)$< ||	\
		$(ECHO) $(GREEN)"-=> "$(RED)"[KO] "$(RESET)$<

clean:
		@ $(ECHO) $(GREEN)"-=> "$(BLUE)"Cleaning "$(NAME)"..."$(RESET)
		$(REMOVE) $(OBJ)

fclean:		clean
		@ $(ECHO) $(GREEN)"-=> "$(BLUE)"Removing "$(NAME)" ..."$(RESET)
		$(REMOVE) $(LIB)

re:		fclean all
