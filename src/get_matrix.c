/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:12:02 by ebmarque          #+#    #+#             */
/*   Updated: 2023/06/22 22:28:34 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	fill_matrix_line(t_dot *fdf, char **split, int index)
{
	int	size;
	int	j;

	j = 0;
	size = 0;
	while (split[size])
		size++;
	fdf->matrix[index] = malloc(sizeof(int) * size);
	while (j < size)
	{
		fdf->matrix[index][j] = ft_atoi(split[j]);
		j++;
	}
}

void	fill_matrix(t_dot *fdf, char *file, int fd)
{
	char	*line;
	char	**line_split;
	int		i;

	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		line_split = ft_split(line, " \n");
		fill_matrix_line(fdf, line_split, i);
		ft_free_split(line_split, 0, true);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close(fd);
	fdf->matrix[i] = NULL;
}

void	get_martix(t_dot *fdf, char *file)
{
	char	*line;
	int		fd;
	int		nb_lines;

	nb_lines = 0;
	fd = open(file, O_RDONLY, 0777);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		nb_lines++;
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	fdf->matrix = malloc(sizeof(int *) * (nb_lines + 1));
	fd = open(file, O_RDONLY, 0777);
	fill_matrix(fdf, file, fd);
}
