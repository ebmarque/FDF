# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebmarque < ebmarque@student.42porto.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/03 14:00:04 by ebmarque          #+#    #+#              #
#    Updated: 2023/06/20 15:43:31 by ebmarque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FRAEMWORKS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

CC = cc

FLAGS = -Werror -Wextra -Wall -g

NAME = fdf

SRC = src/*.c

INCLUDE = -I ./Includes

OBJ = ${SRCS:.c=.o}

RM = rm -fr

FDFLIB = fdf_lib.a

all: $(NAME)

%.o: %.c
	@$(CC) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ) $(FDFLIB)
	@$(CC) ${CFLAGS} ${INCLUDE} $(SRC) -o $(NAME) $(FDFLIB) $(FRAEMWORKS)

$(FDFLIB): $(OBJ)
	@mkdir temp
	@make -C libft
	@cd temp/ && ar x ../libft/libft.a && cd ..
	@ar rcs $(FDFLIB) temp/*.o
	@$(RM) temp

clean:
	@make -C libft/ clean
	@$(RM) $(OBJ) *.o

fclean: clean
	@make -C libft/ fclean
	@$(RM) $(OBJ) $(NAME) $(FDFLIB)

re:
	make fclean
	make all
	make clean
	clear
.PHONY: re all clean fclean