/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:01:41 by azgaoua           #+#    #+#             */
/*   Updated: 2023/10/02 15:15:00 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_isometric_bonus(float *x, float *y, int z, t_fdf *info)
{
	float	old_x;

	old_x = *x;
	*x = (*x - *y) * cos(info->tita);
	*y = (old_x + *y) * sin(info->tita) - z;
}

void	ft_zoom_bonus(float *x, float *y, t_fdf *info)
{
	*x *= info->zoom;
	*y *= info->zoom;
}

void	ft_shift_bonus(float *x, float *y, t_fdf *info)
{
	*x += info->sh_x + (1920 / 2) - 250;
	*y += info->sh_y + (1080 / 2) - 400;
}

void	my_mlx_pixel_put_bonus(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + \
	x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_bresenham_bonus(t_cordnt cordnt, t_fdf *info)
{
	float	e_x;
	float	e_y;
	int		maxi;
	int		z;
	int		z0;

	ft_inits_bonus(&cordnt, &z, &z0, info);
	e_x = cordnt.x0 - cordnt.x;
	e_y = cordnt.y0 - cordnt.y;
	maxi = ft_max_bonus(ft_mod_bonus(e_x), ft_mod_bonus(e_y));
	e_x /= maxi;
	e_y /= maxi;
	while (((int )(cordnt.x - cordnt.x0) || (int )(cordnt.y - cordnt.y0)) \
	&& cordnt.x <= 1920 && cordnt.y <= 1080 && cordnt.x >= 0 && cordnt.y >= 0)
	{
		if (cordnt.x < 1590 || cordnt.y > 400)
			my_mlx_pixel_put_bonus(&info->mlx, (int )cordnt.x, (int )cordnt.y, \
		info->color);
		else
			break ;
		cordnt.x += e_x;
		cordnt.y += e_y;
	}
}
