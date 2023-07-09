/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_aux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:32:31 by ebmarque          #+#    #+#             */
/*   Updated: 2023/07/04 13:22:28 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	ft_max_and_min(int nb, t_dot *fdf)
{
	if (!fdf->max_z || nb > fdf->max_z)
	{
		fdf->max_z = nb;
	}
	if (!fdf->min_z || nb < fdf->min_z)
		fdf->min_z = nb;
}
