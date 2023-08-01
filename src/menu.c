/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:57:05 by ebmarque          #+#    #+#             */
/*   Updated: 2023/07/31 13:24:04 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	projection_type(t_dot *fdf)
{
	int	s;
	int	y;

	s = WIN_WIDTH - 125;
	y = 100;
	mlx_string_put(fdf->conect, fdf->win, s, 80, 0xAFA9A9, "PROJECTION TYPE");
	if (fdf->tranform_number == 1)
	{
		mlx_string_put(fdf->conect, fdf->win, s, y, \
		0xAFA9A9, "Isometric Projection");
	}
	else if (fdf->tranform_number == 2)
	{
		mlx_string_put(fdf->conect, fdf->win, s, \
		100, 0xAFA9A9, "Parallel Projection");
	}
	else if (fdf->tranform_number == 3)
		mlx_string_put(fdf->conect, fdf->win, s, y, 0xAFA9A9, "Top View");
	else if (fdf->tranform_number == 4)
		mlx_string_put(fdf->conect, fdf->win, s, y, 0xAFA9A9, "Right View");
	else if (fdf->tranform_number == 5)
		mlx_string_put(fdf->conect, fdf->win, s, y, 0xAFA9A9, "Bottom View");
	mlx_string_put(fdf->conect, fdf->win, 100, 20, 0xAFA9A9, "COMMANDS");
	mlx_string_put(fdf->conect, fdf->win, 100, 50, 0xAFA9A9, "/\\ - up");
}

void	ft_part_one(t_dot *fdf)
{
	projection_type (fdf);
	mlx_string_put(fdf->conect, fdf->win, 100, 75, 0xAFA9A9, "< - left");
	mlx_string_put(fdf->conect, fdf->win, 100, 100, 0xAFA9A9, "> - right");
	mlx_string_put(fdf->conect, fdf->win, 100, 125, 0xAFA9A9, "\\/ - bottom");
	mlx_string_put(fdf->conect, fdf->win, 100, 150, 0xAFA9A9, \
	"1 - change color forward");
	mlx_string_put(fdf->conect, fdf->win, 100, 175, 0xAFA9A9, \
	"2 - change color backwards");
	mlx_string_put(fdf->conect, fdf->win, 100, 200, 0xAFA9A9, \
	"z and x - decrease/increase z");
	mlx_string_put(fdf->conect, fdf->win, 100, 225, 0xAFA9A9, \
		"SHIFT - z factor = 1:1");
	mlx_string_put(fdf->conect, fdf->win, 100, 250, 0xAFA9A9, \
		"CTRL - z factor = 1:10");
	mlx_string_put(fdf->conect, fdf->win, 100, 275, 0xAFA9A9, \
		"TAB - z factor = 1:100");
	mlx_string_put(fdf->conect, fdf->win, 100, 300, 0xAFA9A9, \
		"w and s - rotation parallel x");
	mlx_string_put(fdf->conect, fdf->win, 100, 325, 0xAFA9A9, \
		"a and d - rotation z");
	mlx_string_put(fdf->conect, fdf->win, 100, 350, 0xAFA9A9, \
		"i and k - rotation x");
	mlx_string_put(fdf->conect, fdf->win, 100, 375, 0xAFA9A9, \
		"j and l - rotation y");
}

void	ft_menu(t_dot *fdf)
{
	ft_part_one(fdf);
	mlx_string_put(fdf->conect, fdf->win, 100, 400, 0xAFA9A9, \
	"7 and 8 - rotation parallel y");
	mlx_string_put(fdf->conect, fdf->win, 100, \
		425, 0xAFA9A9, "mouse click - grid location");
	mlx_string_put(fdf->conect, fdf->win, 100, \
		450, 0xAFA9A9, "y and u - change projection");
	mlx_string_put(fdf->conect, fdf->win, 100, \
		WIN_HEIGHT - 25, 0xAFA9A9, "By: Ebenezer Marquezine");
}
