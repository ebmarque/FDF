/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 14:05:30 by ebmarque          #+#    #+#             */
/*   Updated: 2023/06/25 14:06:31 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

//Estas funcoes servem para manipular em tempo real 
//a projecao, quer seja variando shifts, angulos ou cores

void	handle_shift(int keysym, t_dot *fdf)
{
	if (keysym == 65363)
		fdf->shift_x += 50;
	else if (keysym == 65361)
		fdf->shift_x -= 50;
	else if (keysym == 65364)
		fdf->shift_y += 50;
	else if (keysym == 65362)
		fdf->shift_y -= 50;
}

void	handle_angles(int keysym, t_dot *fdf)
{
	if (keysym == 'w')
		fdf->angle_y += 0.03;
	else if (keysym == 's')
		fdf->angle_y -= 0.03;
	else if (keysym == '7')
		fdf->angle_x += 0.03;
	else if (keysym == '8')
		fdf->angle_x -= 0.03;
	else if (keysym == 'b')
		fdf->angle_p += 0.3;
	else if (keysym == 'v')
		fdf->angle_p -= 0.3;
}

void	handle_color(int keysym, t_dot *fdf)
{
	if (keysym == 49 && fdf->flag < 9)
		fdf->flag++;
	else if (keysym == 50 && fdf->flag > 0)
		fdf->flag--;
	else if (keysym == '0')
		fdf->map_option = 0;
	else if (keysym == '9')
		fdf->map_option = 1;
}

//x->theta; y->phi; z->qsi;
void	handle_rotation(int keysym, t_dot *fdf)
{
	if (keysym == 'i')
		fdf->theta += 0.03;
	else if (keysym == 'k')
		fdf->theta -= 0.03;
	else if (keysym == 'j')
		fdf->phi += 0.03;
	else if (keysym == 'l')
		fdf->phi -= 0.03;
	else if (keysym == 'a')
		fdf->qsi += 0.03;
	else if (keysym == 'd')
		fdf->qsi -= 0.03;
}
