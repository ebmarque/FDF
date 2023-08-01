/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:55:22 by ebmarque          #+#    #+#             */
/*   Updated: 2023/07/29 12:32:18 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	check_empty(char *file, t_dot *fdf)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY, 0777);
	if (fd < 0)
	{
		ft_putstr_fd((RED_COLOR"FILE DOES NOT EXIST!\n"RESET_COLOR), 2);
		free(fdf);
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	if (line == NULL)
	{
		close(fd);
		ft_putstr_fd((RED_COLOR"FILE IS EMPTY\n"RESET_COLOR), 2);
		free(fdf);
		free(line);
		exit(EXIT_FAILURE);
	}
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	free(line);
}

void	file_type(char *file, t_dot *fdf)
{
	size_t	i;

	i = ft_strlen(file) - 4;
	if (ft_strncmp(&file[i], ".fdf", 5) == 0)
		return ;
	else
	{
		ft_putstr_fd((RED_COLOR "FILE IS NOT A \"FDF\" TYPE \n" RESET_COLOR), 2);
		free(fdf);
		exit(EXIT_SUCCESS);
	}
}

int	check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '-' || line[i] == '+')
			if (!ft_isdigit(line[i + 1]))
				return (-1);
		if (line[i] != '-' && line[i] != '+'
			&& line[i] != 32 && line[i] != 10)
			if (!ft_isdigit(line[i]))
				return (-1);
		i++;
	}
	return (0);
}

void	invalid_chars(char *file, t_dot *fdf)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY, 0777);
	line = get_next_line(fd);
	while (line)
	{
		if (check_line(line) < 0)
		{
			ft_putstr_fd((RED_COLOR "FILE HAS NON DIGITS\n" RESET_COLOR), 2);
			close(fd);
			free(line);
			free(fdf);
			exit(EXIT_FAILURE);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
}

void	check_map(int argc, char *file, t_dot *fdf)
{
	if (argc != 2)
	{
		ft_putstr_fd((RED_COLOR "INVALID NUMBER OF ARGMUNTS\n" RESET_COLOR), 2);
		free(fdf);
		exit(EXIT_FAILURE);
	}
	file_type(file, fdf);
	check_empty(file, fdf);
	invalid_chars(file, fdf);
	if (map_shape(file, fdf) < 0)
	{
		ft_printf(RED_COLOR "FILE IS NOT RETANGULAR\n" RESET_COLOR);
		free(fdf);
		exit(EXIT_FAILURE);
	}
}
