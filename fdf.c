/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:02:53 by azgaoua           #+#    #+#             */
/*   Updated: 2023/09/22 03:20:45 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_isometric(float *x, float *y, int z, fdf *info)
{
	float old_x = *x;
	
	*x = (*x - *y) * cos(info->tita);
	*y = (old_x + *y) * sin(info->tita) - z;
}

void	ft_zoom(float *x, float *y, fdf *info)
{
	*x *= info->zoom;
	*y *= info->zoom;
}

void	ft_shift(float *x, float *y, fdf *info)
{
	*x += info->sh_x + 200;
	*y += info->sh_y + 200;
}

void	ftget_e_x_and_e_y(float *e_x, float *e_y)
{
	int	maxi;

	maxi = max(ft_mod(*e_x), ft_mod(*e_y));
	*e_x /= maxi;
	*e_y /= maxi;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + \
	x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	bresenham(float x, float y, float x0, float y0, fdf *info)
{
	float	e_x;
	float	e_y;
	int		maxi;
	int		z;
	int		z0;
	
	z = info->z_mtx[(int)y][(int)x];
	z0 = info->z_mtx[(int)y0][(int)x0];
	if ((z0 || z) &&  info->ch_color == 0)
		info->color = 0X00FFFF;
	else if ((z0 || z) &&  info->ch_color == 1)
		info->color = 0XFF0000;
	else if ((z0 || z) &&  info->ch_color == 2)
		info->color = 0XFF00FF;
	else
		info->color = 0XFFFFFF;
	ft_zoom(&x, &y, info);
	ft_zoom(&x0, &y0, info);
	ft_isometric(&x, &y, z, info);
	ft_isometric(&x0, &y0, z0, info);
	ft_shift(&x, &y, info);
	ft_shift(&x0, &y0, info);
	e_x = x0 - x;
	e_y = y0 - y;
	maxi = max(ft_mod(e_x), ft_mod(e_y));
	e_x /= maxi;
	e_y /= maxi;
	while (((int)(x - x0) || (int)(y - y0)) && x <= 1920 && y <= 1080 && x >= 0 && y >= 0)
	{
		if ((x > 230 || y < 1058) && (x < 1590 || y > 400) && (x > 0 || y > 0) && (x < 1920 || y < 1080))
			my_mlx_pixel_put(&info->mlx, (int )x, (int )y, info->color);
		else
			break;
		x += e_x;
		y += e_y;
	}
}
