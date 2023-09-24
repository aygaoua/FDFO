/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:02:53 by azgaoua           #+#    #+#             */
/*   Updated: 2023/09/23 21:31:31 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_isometric(float *x, float *y, int z, t_fdf *info)
{
	float	old_x;

	old_x = *x;
	*x = (*x - *y) * cos(info->tita);
	*y = (old_x + *y) * sin(info->tita) - z;
}

void	ft_zoom(float *x, float *y, t_fdf *info)
{
	*x *= info->zoom;
	*y *= info->zoom;
}

void	ft_shift(float *x, float *y, t_fdf *info)
{
	*x += info->sh_x + 200;
	*y += info->sh_y + 200;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + \
	x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	bresenham(t_cordnt cordnt, t_fdf *info)
{
	float	e_x;
	float	e_y;
	int		maxi;
	int		z;
	int		z0;

	ft_inits(&cordnt, &z, &z0, info);
	e_x = cordnt.x0 - cordnt.x;
	e_y = cordnt.y0 - cordnt.y;
	maxi = max(ft_mod(e_x), ft_mod(e_y));
	e_x /= maxi;
	e_y /= maxi;
	while (((int )(cordnt.x - cordnt.x0) || (int )(cordnt.y - cordnt.y0)) \
	&& cordnt.x <= 1920 && cordnt.y <= 1080 && cordnt.x >= 0 && cordnt.y >= 0)
	{
		if ((cordnt.x > 230 || cordnt.y < 1058) && \
		(cordnt.x < 1590 || cordnt.y > 400))
			my_mlx_pixel_put(&info->mlx, (int )cordnt.x, (int )cordnt.y, \
		info->color);
		else
			break ;
		cordnt.x += e_x;
		cordnt.y += e_y;
	}
}
