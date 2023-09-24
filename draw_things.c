/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_things.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 22:05:32 by azgaoua           #+#    #+#             */
/*   Updated: 2023/09/23 18:44:53 by azgaoua          ###   ########.fr       */
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

void	ft_draw(t_fdf *info)
{
	info->cordnt.y = 0;
	info->mlx.img = mlx_new_image(info->mlx_ptr, 1920, 1080);
	info->mlx.addr = mlx_get_data_addr(info->mlx.img, \
	&info->mlx.bits_per_pixel, &info->mlx.line_length, &info->mlx.endian);
	while (info->cordnt.y < info->height)
	{
		info->cordnt.x = 0;
		while (info->cordnt.x < info->width)
		{
			if (info->cordnt.x < info->width - 1)
			{
				info->cordnt.x0 = info->cordnt.x + 1;
				info->cordnt.y0 = info->cordnt.y;
				bresenham(info->cordnt, info);
			}
			if (info->cordnt.y < info->height - 1)
			{
				info->cordnt.y0 = info->cordnt.y + 1;
				info->cordnt.x0 = info->cordnt.x;
				bresenham(info->cordnt, info);
			}
			info->cordnt.x++;
		}
		info->cordnt.y++;
	}
}
