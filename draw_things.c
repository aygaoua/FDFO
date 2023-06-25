/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_things.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 22:05:32 by azgaoua           #+#    #+#             */
/*   Updated: 2023/06/24 15:18:03 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

float	ft_mod(float a)
{
	if (a < 0)
		return (-a);
	return (a);
}

void	ft_draw(fdf *info)
{
	int	i;
	int	j;

	j = 0;
	while (j < info->height)
	{
		i = 0;
		while (i < info->width)
		{
			if (i < info->width - 1)
				bresenham(i, j, i + 1, j, info);
			if (j < info->height - 1)
				bresenham(i, j, i, j + 1, info);
			i++;
		}
		j++;
	}
}