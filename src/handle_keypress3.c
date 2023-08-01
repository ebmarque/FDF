/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 14:07:20 by ebmarque          #+#    #+#             */
/*   Updated: 2023/07/31 13:30:54 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	handle_projection(int keysym, t_dot *fdf)
{
	if (keysym == 121 && fdf->tranform_number < 5)
		fdf->tranform_number++;
	else if (keysym == 117 && fdf->tranform_number > 1)
		fdf->tranform_number--;
}

void	handle_z(int keysym, t_dot *fdf)
{
	if (keysym == 122 && fdf->z_modify < 20)
		fdf->z_modify += 0.1;
	else if (keysym == 120 && fdf->z_modify > 0.2)
		fdf->z_modify -= 0.1;
	else if (keysym == 65289)
		fdf->z_modify = 100;
	else if (keysym == 65507)
		fdf->z_modify = 10;
	else if (keysym == 65505)
		fdf->z_modify = 1;
}
