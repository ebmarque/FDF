/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:38:27 by ebmarque          #+#    #+#             */
/*   Updated: 2023/07/31 14:08:14 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	free_matrix(t_dot *fdf)
{
	int	i;

	i = 0;
	while (fdf->matrix[i])
	{
		free(fdf->matrix[i]);
		i++;
	}
	free(fdf->matrix[i]);
	free(fdf->matrix);
}

void	free_point(t_dot *fdf)
{
	int	i;

	i = 0;
	while (fdf->point[i])
	{
		free(fdf->point[i]);
		i++;
	}
	free(fdf->point[i]);
	free(fdf->point);
}

void	panic(t_dot *fdf)
{
	free(fdf->conect);
	free(fdf->win);
	free_matrix(fdf);
	free_point(fdf);
	free(fdf);
}

void	init_game(t_dot *fdf, char *file)
{
	get_martix(fdf, file);
	matrix_to_point(fdf);
	screen_size(fdf);
	fdf->img.img = \
		mlx_new_image(fdf->conect, fdf->screen.max_x, fdf->screen.max_y);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img, \
		&fdf->img.bits_per_pixel, &fdf->img.line_length, &fdf->img.endian);
	fdf->win = mlx_new_window(fdf->conect, \
		fdf->screen.max_x, fdf->screen.max_y, "FDF - EBMARQUE");
	mlx_hook(fdf->win, 2, 1L << 0, handle_keypress, fdf);
	mlx_hook(fdf->win, 17, 0, ft_close, fdf);
	mlx_hook(fdf->win, 4, 1L << 2, mouse_hook, fdf);
	draw_img_grid(fdf);
}

int	main(int argc, char *argv[])
{
	t_dot	*fdf;

	fdf = malloc(sizeof(t_dot));
	if (!fdf)
		return (1);
	set_param(fdf);
	check_map(argc, argv[1], fdf);
	fdf->conect = mlx_init();
	init_game(fdf, argv[1]);
	mlx_loop(fdf->conect);
	return (0);
}
