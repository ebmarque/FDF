/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_to_point.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 14:56:15 by ebmarque          #+#    #+#             */
/*   Updated: 2023/07/24 10:29:10 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	create_point(t_dot *fdf, int j, int i, int value)
{
	fdf->point[j][i].x = i;
	fdf->point[j][i].y = j;
	fdf->point[j][i].z = value;
}

void	screen_dimensions(t_coordinate a, t_dot *fdf)
{
	int	x;
	int	y;

	if (fdf->max_z - fdf->min_z > 90)
		fdf->z_modify = 9;
	if (fdf->max_z - fdf->min_z > 900)
		fdf->z_modify = 90;
	a = isometric_projection(a, fdf);
	x = a.x;
	y = a.y;
	if (x < fdf->screen.min_x && x < 0)
		fdf->screen.min_x = x;
	if (y < fdf->screen.min_y && y < 0)
		fdf->screen.min_y = y;
	if (!fdf->screen.max_x || x > fdf->screen.max_x)
		fdf->screen.max_x = x;
	if (!fdf->screen.max_y || y > fdf->screen.max_y)
		fdf->screen.max_y = y;
}

void	matrix_to_point(t_dot *fdf)
{
	int	x;
	int	y;

	fdf->point = malloc(sizeof(t_coordinate *) * fdf->nb_lines);
	y = 0;
	while (y < fdf->nb_lines)
	{
		x = 0;
		fdf->point[y] = malloc(sizeof(t_coordinate) * fdf->nb_columns);
		while (x < fdf->nb_columns)
		{
			create_point(fdf, y, x, fdf->matrix[y][x]);
			screen_dimensions((fdf->point)[y][x], fdf);
			x++;
		}
		y++;
	}
}
