/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 15:59:06 by ebmarque          #+#    #+#             */
/*   Updated: 2023/06/24 16:03:40 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

t_coordinate	ismotric_projection(t_coordinate a, t_dot *fdf)
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