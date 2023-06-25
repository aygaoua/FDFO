/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:02:53 by azgaoua           #+#    #+#             */
/*   Updated: 2023/06/24 22:35:27 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(TITA);
	*y = (*x + *y) * sin(TITA) - z;
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
	int offset;

	offset = (y * data->line_length + x * (data->bits_per_pixel / 8));
	dst = data->addr + offset;
	*(unsigned int*)dst = color;
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
	if (z0 || z)
		info->color = 0X00FFFF;
	else
		info->color = 0XFFFFFF;
	ft_zoom(&x, &y, info);
	ft_zoom(&x0, &y0, info);
	ft_isometric(&x, &y, z);
	ft_isometric(&x0, &y0, z0);
	ft_shift(&x, &y, info);
	ft_shift(&x0, &y0, info);
	e_x = x0 - x;
	e_y = y0 - y;
	maxi = max(ft_mod(e_x), ft_mod(e_y));
	e_x /= maxi;
	e_y /= maxi;
	while ((int)(x - x0) || (int)(y - y0))
	{
		mlx_pixel_put(info->mlx_ptr, info->win_ptr, x, y, info->color);
		x += e_x;
		y += e_y;
	}
}
