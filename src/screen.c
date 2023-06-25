/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 13:42:10 by ebmarque          #+#    #+#             */
/*   Updated: 2023/06/25 13:46:54 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	screen_size(t_dot *fdf)
{
	int	diff_x;
	int	diff_y;

	diff_x = WINDOW_WIDTH - fdf->screen.max_x;
	diff_y = WINDOW_HEIGHT - fdf->screen.max_x;
	fdf->screen.max_x = fdf->screen.max_x - fdf->screen.min_x;
	fdf->screen.max_y = fdf->screen.max_y - fdf->screen.min_y;
	fdf->shift_x = -fdf->screen.min_x;
	fdf->shift_y = -fdf->screen.min_y;
	if (diff_x < 0 || diff_y < 0)
		bigger_case(fdf);
	else
		smaller_case(fdf);
	if (fdf->map_option == 1)
	{
		fdf->shift_x = WINDOW_WIDTH / 2 \
			- fdf->screen.max_x / 2 + fdf->shift_x;
		fdf->shift_y = WINDOW_HEIGHT / 2 \
			- fdf->screen.max_y / 2 + fdf->shift_y;
		fdf->screen.max_x = WINDOW_WIDTH;
		fdf->screen.max_y = WINDOW_HEIGHT;
	}
}
