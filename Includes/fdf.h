/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 15:13:39 by vinograd          #+#    #+#             */
/*   Updated: 2023/06/24 16:07:48 by ebmarque         ###   ########.fr       */
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
# define WIN_WIDTH 1500
# define WIN_HEIGHT 900

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
	int			is_last;
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
	int				nb_columns;
	int				nb_lines;
	int				win_x;
	int				win_y;
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
	int				max_z;
	int				min_z;
	int				new_max;
	int				z_scale;
	int				color;
	int				scale;
	int				shift_x;	
	int				shift_y;
	int				is_isometric;
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
int	 			check_columns(char **line, int comlumn_ref);
int				check_line(char *line);
void			panic(t_dot *fdf);

// LOADING MAP

void			get_martix(t_dot *fdf, char *file);
void			fill_matrix_line(t_dot *fdf, char **split, int index);
void			fill_matrix(t_dot *fdf, char *file, int fd);

//SET PARAMETERS
void			set_connection(t_dot *fdf);
void			set_param(t_dot *fdf);

//MATRIX TO POINT;

void			matrix_to_point(t_dot *fdf);
void			screen_dimensions(t_coordinate a, t_dot *fdf);
void			create_point(t_dot *fdf, int j, int i, int value);

// PROJECTIONS

t_coordinate	ismotric_projection(t_coordinate a, t_dot *fdf);

#endif
