/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_things.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 22:05:32 by azgaoua           #+#    #+#             */
/*   Updated: 2023/09/26 16:35:54 by azgaoua          ###   ########.fr       */
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

void	ft_set_one(t_cordnt *cordnt)
{
	cordnt->x0 = cordnt->x + 1;
	cordnt->y0 = cordnt->y;
}

void	ft_set_tow(t_cordnt *cordnt)
{
	cordnt->y0 = cordnt->y + 1;
	cordnt->x0 = cordnt->x;
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
				ft_set_one(&info->cordnt);
				bresenham(info->cordnt, info);
			}
			if (info->cordnt.y < info->height - 1)
			{
				ft_set_tow(&info->cordnt);
				bresenham(info->cordnt, info);
			}
			info->cordnt.x++;
		}
		info->cordnt.y++;
	}
	mlx_string_put(info->mlx_ptr, info->win_ptr, 1920 / 2 - 100, \
	1058 / 2, 0XFFF000, "click any button to start !!");
}
