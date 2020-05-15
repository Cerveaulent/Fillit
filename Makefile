# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/02/04 09:11:05 by ccantin      #+#   ##    ##    #+#        #
#    Updated: 2019/03/24 16:24:19 by bnoyer      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all, re, clean, fclean, lib

NAME = fillit

CC = gcc
CC_FLAGS = -Wall -Werror -Wextra

LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a
LIBFT_INC = $(LIBFT_PATH)

FLAG_FT = -Llibft -lft
FLAG_LIB = $(FLAG_FT)

SRC_NAME =	error_handler.c			\
			main.c					\
			parser.c				\
			solver.c				\
			tetri_handler.c			\
			tetri_check.c			\
			find_first.c			\
			solution_rec_heandler.c


SRC_PATH =	src

INC_NAME =	fillit.h				\
			tetri_handler.h

INC_PATH =	.

INCLUDES =	-I$(LIBFT_INC) -I$(INC_PATH)

OBJ_NAME =	$(SRC_NAME:.c=.o)
OBJ_PATH =	.

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
INC = $(addprefix $(INC_PATH)/,$(INC_NAME))

all: makelib message $(NAME)

message:
	@ make -q $(NAME) && echo "\033[1mLe projet est deja a jour\033[0m" || true

$(NAME): $(LIBFT) $(OBJ)
	@ printf "\033[1mCompilation du projet \033[34m$@\033[0m \033[1men \033[31m$@\033[0m ✅\n"
	@ $(CC) $(CC_FLAGS) -o $@ $(OBJ) $(INCLUDES) $(FLAG_LIB)

libft: $(LIBFT)
$(LIBFT):
	@ make -C $(LIBFT_PATH)

%.o: %.c $(INC)
	@ printf "\033[1mCompilation de \033[36m%-20s\033[37m\ten \033[32m%-25s\033[0m ✅\n" $< $@
	@ $(CC) $(CC_FLAGS) $(INCLUDES) -c $< -o $@

clean:
	@ /bin/rm -rf $(OBJ)
	@ make -C $(LIBFT_PATH) clean

fclean: clean
	@ /bin/rm -f $(NAME)
	@ make -C $(LIBFT_PATH) fclean

makelib:
	@ make -C $(LIBFT_PATH)

re: fclean all
