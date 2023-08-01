/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 15:13:39 by vinograd          #+#    #+#             */
/*   Updated: 2023/07/31 21:24:17 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <math.h>
# include "../mlx_linux/mlx.h"
# include "X11/X.h"
# include "X11/keysym.h"

# define BUFFER_SIZE 10
# include "../libft/libft.h"

# define RESET_COLOR "\033[0m"
# define BLACK_COLOR "\033[0;30m"
# define RED_COLOR "\033[0;31m"
# define GREEN_COLOR "\033[0;32m"
# define YELLOW_COLOR "\033[0;33m"
# define BLUE_COLOR "\033[0;34m"
# define MAGENTA_COLOR "\033[0;35m"
# define CYAN_COLOR "\033[0;36m"
# define WHITE_COLOR "\033[0;37m"
# define WIN_WIDTH 1200
# define WIN_HEIGHT 700

typedef struct s_data{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_coordinate
{
	float		x;
	float		y;
	float		z;
}				t_coordinate;

typedef struct s_screen {
	int		min_x;
	int		min_y;
	int		max_y;
	int		max_x;
}				t_screen;

typedef struct s_fdf
{
	void			*conect;
	void			*win;
	int				**matrix;
	char			*file;
	int				nb_columns;
	int				nb_lines;
	float			rgb_p;
	float			range_z;
	float			grid_size;
	float			angle_x;
	float			angle_y;
	float			angle;
	float			angle_p;
	float			theta;
	float			phi;
	float			qsi;
	float			z_modify;
	float			slope;
	int				max_z;
	int				min_z;
	int				new_max;
	int				z_scale;
	int				color;
	int				scale;
	int				shift_x;
	int				shift_y;
	int				is_isometric;
	int				direction;
	int				tranform_number;
	int				flag;
	t_coordinate	**point;
	t_screen		screen;
	t_data			img;
}					t_dot;

//ERROR AND CHECK

void			check_map(int argc, char *file, t_dot *fdf);
void			file_type(char *file, t_dot *fdf);
void			check_empty(char *file, t_dot *fdf);
void			invalid_chars(char *file, t_dot *fdf);
int				map_shape(char *file, t_dot *fdf);
int				get_nb_columns(char *file);
int				check_columns(char **line, int comlumn_ref);
int				check_line(char *line);
void			panic(t_dot *fdf);
void			free_point(t_dot *fdf);

// LOADING MAP

void			get_martix(t_dot *fdf, char *file);
void			fill_matrix_line(t_dot *fdf, char **split, int index);
void			fill_matrix(t_dot *fdf, char *file, int fd);

//SET PARAMETERS
void			set_param(t_dot *fdf);

//MATRIX TO POINT;

void			matrix_to_point(t_dot *fdf);
void			create_point(t_dot *fdf, int j, int i, int value);
void			set_img(t_dot *fdf);

// PROJECTIONS

t_coordinate	isometric_projection(t_coordinate a, t_dot *fdf);
t_coordinate	parallel_projection(t_coordinate a, t_dot *fdf);
t_coordinate	front_view(t_coordinate a, t_dot *fdf);
t_coordinate	right_view(t_coordinate a, t_dot *fdf);
t_coordinate	top_view(t_coordinate a, t_dot *fdf);

// SCREEN

void			screen_dimensions(t_coordinate a, t_dot *fdf);
void			screen_size(t_dot *fdf);
void			bigger_case(t_dot *fdf);
void			smaller_case(t_dot *fdf);

// HANDLE_KEYPRESS 

void			handle_parte_one(int keysym, t_dot *fdf);
int				handle_keypress(int keysym, t_dot *fdf);
void			handle_offset(int keysym, t_dot *fdf);
void			handle_shift(int keysym, t_dot *fdf);
void			handle_angles(int keysym, t_dot *fdf);
void			handle_color(int keysym, t_dot *fdf);
void			handle_rotation(int keysym, t_dot *fdf);
void			handle_projection(int keysym, t_dot *fdf);
void			handle_z(int keysym, t_dot *fdf);

// MOUSE

void			free_mlx(t_dot *fdf);
int				ft_close(void *o);
void			clean_img(t_dot *fdf);
int				mouse_hook(int button, int x, int y, t_dot *fdf);
void			free_map(t_dot *fdf);

// DRAW GRID

t_coordinate	transformations(t_dot *fdf, t_coordinate a);
void			edge_case(t_dot *fdf, t_coordinate a, t_coordinate b, float x);
void			inicializer(t_dot *fdf, t_coordinate a,
					t_coordinate b, float x);
void			two_points(t_dot *fdf, t_coordinate a, t_coordinate b);
void			draw_img_grid(t_dot *fdf);

// ROTATIONS

t_coordinate	init_coordinate(int x, int y, int z);
t_coordinate	rotation_x(t_coordinate a, t_dot *fdf);
t_coordinate	rotation_y(t_coordinate a, t_dot *fdf);
t_coordinate	rotation_z(t_coordinate a, t_dot *fdf);

// MAP AUX

void			ft_max_and_min(int nb, t_dot *fdf);

// COLOR

void			my_mlx_pixel_put(t_dot *fdf, int x, int y, int color);
int				create_trgb(int t, int r, int g, int b);
int				make_color(float percent, int flag, int r, int g);
int				percent_to_color(float percent, int flag);

// MENU

void			projection_type(t_dot *fdf);
void			ft_part_one(t_dot *fdf);
void			ft_menu(t_dot *fdf);

#endif
