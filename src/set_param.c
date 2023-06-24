/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 14:54:34 by ebmarque          #+#    #+#             */
/*   Updated: 2023/06/24 15:48:38 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	set_connection(t_dot *fdf)
{
	fdf->conect = mlx_init();
	fdf->win = mlx_new_window(fdf->conect, WIN_WIDTH, WIN_HEIGHT, "FDF");
	fdf->win_x = WIN_WIDTH;
	fdf->win_y = WIN_HEIGHT;
	fdf->point = NULL;
	fdf->matrix = NULL;
}

void	set_param(t_dot *fdf)
{
	set_connection(fdf);
	fdf->grid_size = 11;
	fdf->nb_columns = 0;
	fdf->nb_lines = 0;
	fdf->shift_x = 0;
	fdf->shift_x = 0;
	fdf->qsi = 0;
	fdf->phi = 0;
	fdf->theta = 0;
	fdf->angle_y = 0.523599;;
	fdf->angle_x = 0.523599;
	fdf->angle_p = 0.7854;
	fdf->z_modify = 1;
	fdf->max_z = 0;
	fdf->min_z = 0;
	fdf->screen.max_x = 0;
	fdf->screen.max_y = 0;
	fdf->screen.min_x = 0;
	fdf->screen.min_y = 0;
	
}
