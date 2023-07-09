/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 14:01:03 by ebmarque          #+#    #+#             */
/*   Updated: 2023/07/04 13:22:39 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	handle_parte_one(int keysym, t_dot *fdf)
{
	if (keysym == XK_Escape)
		ft_close(fdf);
	else if (keysym == 65363 || keysym == 65361 \
	|| keysym == 65364 || keysym == 65362)
		handle_offset(keysym, fdf);
	else if (keysym == 'w' || keysym == 's' || keysym == '7' || keysym == '8' \
	|| keysym == 'b' || keysym == 'v')
		handle_angles(keysym, fdf);
}

int	handle_keypress(int keysym, t_dot *fdf)
{
	clean_img(fdf);
	handle_parte_one(keysym, fdf);
	if (keysym == 49 || keysym == 50 || keysym == '0' || keysym == '9')
		handle_color(keysym, fdf);
	else if (keysym == 122 || keysym == 120 \
	|| keysym == 65507 || keysym == 65505 || keysym == 65289)
		handle_z(keysym, fdf);
	else if (keysym == 'g')
		fdf->grid_size = 1;
	else if (keysym == 121 || keysym == 117 || keysym == '3')
		handle_projection(keysym, fdf);
	else if (keysym == 'i' || keysym == 'k' || keysym == 'j' \
	|| keysym == 'l' || keysym == 'a' || keysym == 'd')
		handle_rotation(keysym, fdf);
	draw_img_grid(fdf);
	return (0);
}
