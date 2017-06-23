##
## Makefile for 42sh in /home/victor/PSU/PSU_2016_42sh
## 
## Made by Victor LE DANTEC
## Login   <victor.le-dantec@epitech.eu>
## 
## Started on  Thu Apr 27 00:40:24 2017 Victor LE DANTEC
## Last update Sun May 21 21:17:20 2017 Victor LE DANTEC
##

ECHO		=	/bin/echo -e

NAME		=	42sh

## Compile flags

CFLAGS		+=	-Wall -Wextra -I./inc/ -pedantic

MAKEFLAGS	+=	--no-print-directory

LDFLAGS		+=	-L ./lib -ltech -lncurses

## Source files

SRC_FOLDER	=	src/

EVAL_SRC	=	$(SRC_FOLDER)evaluator/

EXEC_SRC	=	$(SRC_FOLDER)executor/

BUILT_SRC	=	$(SRC_FOLDER)builtins/

SHELL_SRC	=	$(SRC_FOLDER)shell/

PARSER_SRC	=	$(SRC_FOLDER)parser/

SRC		=	$(BUILT_SRC)alias.c			\
			$(BUILT_SRC)builtins_index.c		\
			$(BUILT_SRC)cmd_alias.c			\
			$(BUILT_SRC)cmd_builtins.c		\
			$(BUILT_SRC)cmd_cd.c			\
			$(BUILT_SRC)cmd_echo.c			\
			$(BUILT_SRC)cmd_env.c			\
			$(BUILT_SRC)cmd_exit.c			\
			$(BUILT_SRC)cmd_getenv.c		\
			$(BUILT_SRC)cmd_path.c			\
			$(BUILT_SRC)cmd_pwd.c			\
			$(BUILT_SRC)cmd_repeat.c		\
			$(BUILT_SRC)cmd_setenv.c		\
			$(BUILT_SRC)cmd_unsetenv.c		\
			$(BUILT_SRC)cmd_which.c			\
			$(EVAL_SRC)check_commands.c		\
			$(EVAL_SRC)delimiter.c			\
			$(EVAL_SRC)evaluator.c			\
			$(EVAL_SRC)evaluator_word.c		\
			$(EVAL_SRC)redirect.c			\
			$(EVAL_SRC)separator.c			\
			$(EXEC_SRC)binary.c			\
			$(EXEC_SRC)builtins.c			\
			$(EXEC_SRC)change_tgrp.c		\
			$(EXEC_SRC)execute.c			\
			$(EXEC_SRC)executor.c			\
			$(EXEC_SRC)file_redirect.c		\
			$(EXEC_SRC)fork.c			\
			$(EXEC_SRC)messages.c			\
			$(EXEC_SRC)pipe.c			\
			$(EXEC_SRC)redirect.c			\
			$(PARSER_SRC)delimiter.c		\
			$(PARSER_SRC)delimiter_dot_comma.c	\
			$(PARSER_SRC)delimiter_double_and.c	\
			$(PARSER_SRC)delimiter_double_greater.c	\
			$(PARSER_SRC)delimiter_double_less.c	\
			$(PARSER_SRC)delimiter_double_pipe.c	\
			$(PARSER_SRC)delimiter_double_quotes.c	\
			$(PARSER_SRC)delimiter_greater.c	\
			$(PARSER_SRC)delimiter_less.c		\
			$(PARSER_SRC)delimiter_pipe.c		\
			$(PARSER_SRC)delimiter_single_quote.c	\
			$(PARSER_SRC)magic_quotes.c		\
			$(PARSER_SRC)parser.c			\
			$(PARSER_SRC)parser_utils.c		\
			$(PARSER_SRC)parse_word.c		\
			$(SHELL_SRC)42sh.c			\
			$(SHELL_SRC)42shrc.c			\
			$(SHELL_SRC)debug_mode.c		\
			$(SHELL_SRC)default_env.c		\
			$(SHELL_SRC)pre_eval.c			\
			$(SHELL_SRC)prompt.c			\
			$(SHELL_SRC)shell_info.c		\
			$(SHELL_SRC)shell_input.c		\
			$(SHELL_SRC)signal_init.c

RM		=	rm -f

OBJ		=	$(SRC:%.c=%.o)

all:			libtech banner $(NAME)

## Fast compile times!

tcc:			CC = tcc
tcc:			libtech banner $(NAME)

## When you segfault!

debug:			CFLAGS += -g
debug:			libtech banner $(NAME)

## Such fast Very optimization Much wow

opti:			CFLAGS += -Ofast
opti:			libtech banner $(NAME)

## It looks good

banner:
			@ $(ECHO) "\033[0;32m-=> \033[1;34mCompiling 42sh ... \033[0m"

## Primary rule to compile binaries

$(NAME):		$(OBJ)
			@ $(ECHO) "\033[0;32m-=> \033[1;34mLinking 42sh ... \033[0m"
			$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)
			@ $(ECHO) "\033[0;32m-=> \033[1;34m42sh correctly finished building!\033[0m"

## Our useful library

libtech:
			@ $(MAKE) -C ./lib/libtech/

## Cleans binaries

clean:
			@ $(ECHO) "\033[0;32m-=> \033[1;34mCleaning 42sh source files ... \033[0m"
			$(RM) $(OBJ)
			@ $(MAKE) -C ./lib/libtech/ clean

## Cleans binaries and 42sh

fclean:			clean
			@ $(ECHO) "\033[0;32m-=> \033[1;34mCleaning 42sh binary... \033[0m"
			$(RM) $(NAME)
			@ $(MAKE) -C ./lib/libtech/ fclean

## To clean and recompile cleanly

re:			fclean all

.c.o:
			@ $(CC) $(CFLAGS) -c $< -o $@ &&		\
			$(ECHO) "\033[0;32m" "[OK]" "\033[00m" $< ||	\
			$(ECHO) "\033[0;31m" "[KO]" "\033[00m" $<

.PHONY:			all clean fclean re libtech compile opti tcc debug .c.o banner
