# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/03 14:00:04 by ebmarque          #+#    #+#              #
#    Updated: 2023/07/30 19:16:26 by ebmarque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FRAEMWORKS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

CC = cc

FLAGS = -Werror -Wextra -Wall -g

NAME = fdf

LIBFT_A = libft/libft.a

SRCS =	src/check_map_utils.c src/check_map.c src/color.c src/draw_grid.c \
		src/get_matrix.c src/handle_keypress1.c src/handle_keypress2.c src/handle_keypress3.c \
		src/main.c src/map_aux.c src/matrix_to_point.c src/menu.c src/mouse.c src/projections.c \
		src/rotations.c src/screen.c src/set_param.c

INCLUDE = -I ./Includes

OBJS = ${SRCS:.c=.o}

RM = rm -fr

FDFLIB = fdf_lib.a

all: $(NAME)

%.o: %.c
	$(CC) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(FDFLIB)
	make -C libft
	$(CC) ${CFLAGS} ${INCLUDE} $(SRC) -o $(NAME) $(FDFLIB) $(LIBFT_A) $(FRAEMWORKS)

$(FDFLIB): $(OBJS)
	ar rcs $(FDFLIB) $(OBJS)

clean:
	make -C libft/ clean
	$(RM) $(OBJS)

fclean: clean
	make -C libft/ fclean
	$(RM) $(OBJS) $(NAME) $(FDFLIB)

re: fclean all

.PHONY: re all clean fclean