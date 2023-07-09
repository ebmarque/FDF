/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 15:59:06 by ebmarque          #+#    #+#             */
/*   Updated: 2023/07/04 12:36:16 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

t_coordinate	isometric_projection(t_coordinate a, t_dot *fdf)
{
	float	temp_x;
	float	temp_y;

	temp_x = a.x;
	temp_y = a.y;
	a.x = ((temp_x - temp_y) * \
		cos(fdf->angle_x)) * fdf->grid_size + fdf->shift_x;
	a.y = ((-(a.z) / fdf->z_modify + (temp_x + temp_y) * \
	sin(fdf->angle_y))) * fdf->grid_size + fdf->shift_y;
	fdf->new_max = fdf->max_z;
	if (fdf->min_z < 0 || (fdf->min_z < 0 && fdf->max_z < 0))
	{
		a.z = a.z - fdf->min_z + 1;
		fdf->new_max = fdf->max_z - fdf->min_z + 1;
	}
	return (a);
}

t_coordinate	parallel_projection(t_coordinate a, t_dot *fdf)
{
	float	temp_z;

	temp_z = a.z;
	a.x = ((a.x - (temp_z / fdf->z_modify)) * cos(fdf->angle_p)) \
		* fdf->grid_size + fdf->shift_x;
	a.y = ((a.y - (temp_z / fdf->z_modify)) * sin(fdf->angle_p)) \
		* fdf->grid_size + fdf->shift_y;
	fdf->new_max = fdf->max_z;
	if (fdf->min_z < 0 || (fdf->min_z < 0 && fdf->max_z < 0))
	{
		a.z = a.z - fdf->min_z + 1;
		fdf->new_max = fdf->max_z - fdf->min_z + 1;
	}
	return (a);
}

//Executa o grid em 2D visto de cima mostrando pelas cores as altitudes em z 
t_coordinate	front_view(t_coordinate a, t_dot *fdf)
{
	float	temp_x;
	float	temp_y;

	temp_x = a.x;
	temp_y = a.y;
	a.x = temp_x * fdf->grid_size + fdf->shift_x;
	a.y = temp_y * fdf->grid_size + fdf->shift_y;
	fdf->new_max = fdf->max_z;
	if (fdf->min_z < 0 || (fdf->min_z < 0 && fdf->max_z < 0))
	{
		a.z = a.z - fdf->min_z + 1;
		fdf->new_max = fdf->max_z - fdf->min_z + 1;
	}
	return (a);
}

//Executa o grid em 2D visto do lado direito
t_coordinate	right_view(t_coordinate a, t_dot *fdf)
{
	float	temp_z;
	float	temp_y;

	temp_z = a.z;
	temp_y = a.y;
	a.x = -temp_y * fdf->grid_size + fdf->shift_x;
	a.y = ((-temp_z) / fdf->z_modify) * fdf->grid_size + fdf->shift_y;
	fdf->new_max = fdf->max_z;
	if (fdf->min_z < 0 || (fdf->min_z < 0 && fdf->max_z < 0))
	{
		a.z = a.z - fdf->min_z + 1;
		fdf->new_max = fdf->max_z - fdf->min_z + 1;
	}
	return (a);
}

//Executa o grid em 2D visto de baixo
t_coordinate	top_view(t_coordinate a, t_dot *fdf)
{
	float	temp_z;
	float	temp_x;

	temp_z = a.z;
	temp_x = a.x;
	a.x = temp_x * fdf->grid_size + fdf->shift_x;
	a.y = ((-temp_z) / fdf->z_modify) * fdf->grid_size + fdf->shift_y;
	fdf->new_max = fdf->max_z;
	if (fdf->min_z < 0 || (fdf->min_z < 0 && fdf->max_z < 0))
	{
		a.z = a.z - fdf->min_z + 1;
		fdf->new_max = fdf->max_z - fdf->min_z + 1;
	}
	return (a);
}
