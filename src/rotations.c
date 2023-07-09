/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:26:02 by ebmarque          #+#    #+#             */
/*   Updated: 2023/07/04 12:26:45 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

t_coordinate	init_coordinate(int x, int y, int z)
{
	t_coordinate	point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}

t_coordinate	rotation_x(t_coordinate a, t_dot *fdf)
{
	float	temp_z;
	float	temp_y;

	temp_z = a.z;
	temp_y = a.y;
	a.y = temp_y * cos(fdf->theta) + temp_z * sin(fdf->theta);
	a.z = -temp_y * sin(fdf->theta) + temp_z * cos(fdf->theta);
	return (a);
}

t_coordinate	rotation_y(t_coordinate a, t_dot *fdf)
{
	float	temp_x;
	float	temp_z;

	temp_x = a.x;
	temp_z = a.z;
	a.x = temp_x * cos(fdf->phi) + temp_z * sin(fdf->phi);
	a.z = -temp_x * sin(fdf->phi) + temp_z * cos(fdf->phi);
	return (a);
}

t_coordinate	rotation_z(t_coordinate a, t_dot *fdf)
{
	float	temp_x;
	float	temp_y;

	temp_x = a.x;
	temp_y = a.y;
	a.x = temp_x * cos(fdf->qsi) - temp_y * sin(fdf->qsi);
	a.y = temp_x * sin(fdf->qsi) + temp_y * cos(fdf->qsi);
	return (a);
}
