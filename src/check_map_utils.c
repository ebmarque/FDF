/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:16:42 by ebmarque          #+#    #+#             */
/*   Updated: 2023/06/24 15:04:04 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

int	get_nb_columns(char *file)
{
	char	**line_split;
	int		fd;
	int		nb_columns;
	char	*line;

	fd = open(file, O_RDONLY, 0777);
	line = get_next_line(fd);
	line_split = ft_split(line, " \n");
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	nb_columns = 0;
	while (line_split[nb_columns])
		nb_columns++;
	close (fd);
	free(line);
	ft_free_split(line_split, 0, true);
	return (nb_columns);
}

int	check_columns(char **line, int column_ref)
{
	int		columns_pl;

	columns_pl = 0;
	while (line[columns_pl])
		columns_pl++;
	if (columns_pl != column_ref)
	{
		ft_free_split(line, 0, true);
		return (-1);
	}
	ft_free_split(line, 0, true);
	return (0);
}

int	map_shape(char *file, t_dot *fdf)
{
	char	**line_split;
	int		fd;
	int		nb_columns;
	char	*line;

	nb_columns = get_nb_columns(file);
	fdf->nb_columns = nb_columns;
	fd = open(file, O_RDONLY, 0777);
	line = get_next_line(fd);
	while (line)
	{
		if (line)
			line_split = ft_split(line, " \n");
		if (check_columns(line_split, nb_columns) < 0)
		{
			free(line);
			return (-1);
		}
		free(line);
		fdf->nb_lines++;
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (0);
}
