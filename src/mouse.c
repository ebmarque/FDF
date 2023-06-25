/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 14:02:57 by ebmarque          #+#    #+#             */
/*   Updated: 2023/06/25 14:03:51 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

/* Destroy window and image */
void	free_mlx(t_dot *fdf)
{
	if (fdf->win)
		mlx_destroy_window(fdf->mlx, fdf->win);
	if (fdf->img.img)
		mlx_destroy_image(fdf->mlx, fdf->img.img);
	mlx_destroy_display(fdf->mlx);
	free(fdf->mlx);
}

/* Termina a janela */
int	ft_close(void *o)
{
	free_map((t_dot *) o);
	free_mlx((t_dot *) o);
	exit(0);
	return (0);
}

/* Coloca todos os pixels a preto para dar refresh 
caso se desenhe de novo */
void	clean_img(t_dot *fdf)
{
	int	i;
	int	j;

	i = -1;
	while (++i < fdf->screen.max_x)
	{
		j = -1;
		while (++j < fdf->screen.max_y)
			my_mlx_pixel_put(fdf, i, j, 0x00000000);
	}
}

/* Esta funcao executa variacoes com base em acoes do rato */
int	mouse_hook(int button, int x, int y, t_dot *fdf)
{
	clean_img(fdf);
	if (button == 4)
	{
		fdf->size_grid += 0.5;
	}
	else if (button == 5)
	{
		if (fdf->size_grid > 0.5)
			fdf->size_grid -= 0.5;
	}
	else if (button == 1)
	{
		fdf->shift_x = x;
		fdf->shift_y = y;
	}
	draw_img_grid(fdf);
	return (0);
}
