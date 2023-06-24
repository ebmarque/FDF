/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:38:27 by ebmarque          #+#    #+#             */
/*   Updated: 2023/06/24 14:56:01 by ebmarque         ###   ########.fr       */
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

void	panic(t_dot *fdf)
{
	free(fdf->conect);
	free(fdf->win);
	free_matrix(fdf);
	free(fdf);
}

void	init_game(t_dot *fdf)
{
	set_param(fdf);
	matrix_to_pint(fdf);
}

int	main(int argc, char *argv[])
{
	t_dot	*fdf;

	fdf = malloc(sizeof(t_dot));
	if (!fdf)
		return (1);
	check_map(argc, argv[1], fdf);
	// init_game(fdf);
	get_martix(fdf, argv[1]);
	// mlx_loop(fdf->conect);
	panic(fdf);
	return (0);
}
