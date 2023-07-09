/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 13:42:10 by ebmarque          #+#    #+#             */
/*   Updated: 2023/07/09 18:44:40 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	screen_size(t_dot *fdf)
{
	int	diff_x;
	int	diff_y;

	diff_x = WIN_WIDTH - fdf->screen.max_x;
	diff_y = WIN_HEIGHT - fdf->screen.max_x;
	fdf->screen.max_x = fdf->screen.max_x - fdf->screen.min_x;
	fdf->screen.max_y = fdf->screen.max_y - fdf->screen.min_y;
	fdf->shift_x = -fdf->screen.min_x;
	fdf->shift_y = -fdf->screen.min_y;
	if (diff_x < 0 || diff_y < 0)
	{
		bigger_case(fdf);
	}
	else
	{
		smaller_case(fdf);
	}
	fdf->shift_x = WIN_WIDTH / 2 \
		- fdf->screen.max_x / 2 + fdf->shift_x;
	fdf->shift_y = WIN_HEIGHT / 2 \
		- fdf->screen.max_y / 2 + fdf->shift_y;
	fdf->screen.max_x = WIN_WIDTH;
	fdf->screen.max_y = WIN_HEIGHT;
}

void	bigger_case(t_dot *fdf)
{
	while ((fdf->screen.max_x > WIN_WIDTH || \
		fdf->screen.max_x > WIN_HEIGHT))
	{
		fdf->screen.max_y /= 2;
		fdf->screen.max_x /= 2;
		fdf->shift_x = abs(fdf->shift_x / 2);
		fdf->shift_y = abs(fdf->shift_y / 2);
		fdf->grid_size /= 2;
		if (fdf->grid_size < 1)
		{
			if (fdf->screen.max_y > WIN_HEIGHT)
				fdf->screen.max_y = WIN_HEIGHT;
			if (fdf->screen.max_x > WIN_WIDTH)
				fdf->screen.max_x = WIN_WIDTH;
			break ;
		}
	}
}

void	smaller_case(t_dot *fdf)
{
	while ((fdf->screen.max_x < WIN_WIDTH / 5 \
	|| fdf->screen.max_x < WIN_HEIGHT / 5))
	{
		fdf->screen.max_y *= 3;
		fdf->screen.max_x *= 3;
		fdf->shift_x = abs(fdf->shift_x * 3);
		fdf->shift_y = abs(fdf->shift_y * 3);
		fdf->grid_size *= 3;
	}
}
