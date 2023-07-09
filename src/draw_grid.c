/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:13:52 by ebmarque          #+#    #+#             */
/*   Updated: 2023/07/09 13:06:23 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

t_coordinate	transformations(t_dot *fdf, t_coordinate a)
{
	a = rotation_x(a, fdf);
	a = rotation_y(a, fdf);
	a = rotation_z(a, fdf);
	ft_max_and_min(a.z, fdf);
	if (fdf->tranform_number == 1)
		a = isometric_projection(a, fdf);
	if (fdf->tranform_number == 2)
		a = parallel_projection(a, fdf);
	if (fdf->tranform_number == 3)
		a = top_view(a, fdf);
	if (fdf->tranform_number == 4)
		a = right_view(a, fdf);
	if (fdf->tranform_number == 5)
		a = front_view(a, fdf);
	return (a);
}

void	edge_case(t_dot *fdf, t_coordinate a, t_coordinate b, float range, float x)
{
	int	y;
	int	flag;

	flag = 0;
	y = a.y;
	while (fabs(b.y - y) > 0.5)
	{
		fdf->rgb_p = fdf->rgb_p + range / ((fdf->grid_size));
		my_mlx_pixel_put(fdf, x, y, percent_to_color(fdf->rgb_p, \
			fdf->flag));
		y += ((b.y - a.y) / (fabs(b.y - a.y)));
		flag++;
	}
	return ;
}

void	inicializer(t_dot *fdf, t_coordinate a, t_coordinate b, float x)
{
	fdf->rgb_p = a.z / fdf->new_max;
	if (b.z - a.z > 0)
		fdf->range_z = (b.z / fdf->new_max - fdf->rgb_p);
	else
		fdf->range_z = -(a.z / fdf->new_max - b.z / fdf->new_max);
	if (fabs(b.x - a.x) <= 0.5 && fabs(b.y - a.y) > 0.5)
		edge_case(fdf, a, b, fdf->range_z, x);
	fdf->slope = (b.y - a.y) / (b.x - a.x);
	fdf->direction = (b.x - a.x) / (fabs(b.x - a.x));
}

void	two_points(t_dot *fdf, t_coordinate a, t_coordinate b)
{
	float	x;
	float	y;

	a = transformations(fdf, a);
	b = transformations(fdf, b);
	x = a.x;
	inicializer(fdf, a, b, x);
	while (fabs(b.x - x) > 0.5)
	{
		y = fdf->slope * (x - a.x) + a.y;
		fdf->rgb_p = fdf->rgb_p + fdf->range_z / ((fdf->grid_size));
		my_mlx_pixel_put(fdf, x, y, percent_to_color(fdf->rgb_p, fdf->flag));
		if ((fabs(y - (fdf->slope * ((x + fdf->direction) - a.x) + a.y))) > 1)
		{
			while ((int)(y - (fdf->slope * \
				((x + fdf->direction) - a.x) + a.y)))
			{
				y += ((b.y - a.y) / (fabs(b.y - a.y)));
				my_mlx_pixel_put(fdf, x, y, \
				percent_to_color(fdf->rgb_p, fdf->flag));
			}
		}
		x += fdf->direction;
	}
}

void	draw_img_grid(t_dot *fdf)
{
	int	x;
	int	y;
	int	y_new;

	y = -1;
	while (++y < fdf->nb_lines - 1)
	{
		x = 0;
		while (x < fdf->nb_columns)
		{
			y_new = fdf->nb_lines - 2 - y;
			if (x < fdf->nb_columns - 1)
				two_points(fdf, (fdf->point)[y_new][x], \
				(fdf->point)[y_new][x + 1]);
			if (y < fdf->nb_lines - 2)
				two_points(fdf, (fdf->point)[y_new][x], \
				(fdf->point)[y_new - 1][x]);
			x++;
		}
	}
	mlx_put_image_to_window(fdf->conect, fdf->win, fdf->img.img, 0, 0);
	ft_menu(fdf);
}
