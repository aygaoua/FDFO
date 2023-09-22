/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_things.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 22:05:32 by azgaoua           #+#    #+#             */
/*   Updated: 2023/09/22 02:56:27 by azgaoua          ###   ########.fr       */
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
	info->mlx.img = mlx_new_image(info->mlx_ptr, 1920, 1080);
	info->mlx.addr = mlx_get_data_addr(info->mlx.img, &info->mlx.bits_per_pixel, &info->mlx.line_length,
								&info->mlx.endian);
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
	mlx_string_put(info->mlx_ptr, info->win_ptr, 790, 520, 0XFFFF00, "WA 3LA 9WADA !!");
}
