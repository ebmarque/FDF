/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 14:54:34 by ebmarque          #+#    #+#             */
/*   Updated: 2023/07/27 15:18:14 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	set_img(t_dot *fdf)
{
	fdf->img.img = NULL;
	fdf->img.addr = NULL;
	fdf->img.bits_per_pixel = 0;
	fdf->img.line_length = 0;
	fdf->img.endian = 0;
}

void	set_param(t_dot *fdf)
{
	fdf->nb_columns = 0;
	fdf->nb_lines = 0;
	fdf->grid_size = 10;
	fdf->shift_x = 0;
	fdf->shift_y = 0;
	fdf->qsi = 0;
	fdf->phi = 0;
	fdf->theta = 0;
	fdf->angle_y = 0.523599;
	fdf->angle_x = 0.523599;
	fdf->angle_p = 0.7854;
	fdf->z_modify = 1;
	fdf->max_z = 0;
	fdf->min_z = 0;
	fdf->screen.max_x = 0;
	fdf->screen.max_y = 0;
	fdf->screen.min_x = 0;
	fdf->screen.min_y = 0;
	fdf->tranform_number = 1;
	fdf->flag = 4;
	fdf->point = NULL;
	fdf->matrix = NULL;
	fdf->win = NULL;
	fdf->file = NULL;
	set_img(fdf);
}
