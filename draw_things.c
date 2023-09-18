/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_things.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 22:05:32 by azgaoua           #+#    #+#             */
/*   Updated: 2023/09/18 04:10:57 by azgaoua          ###   ########.fr       */
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
	int	i_guide = 1590;
	int	j_guide = 0;

	mlx_string_put(info->mlx_ptr, info->win_ptr, 1700, 30, 0XFFFFFF, "GUIDE :");
    mlx_string_put(info->mlx_ptr, info->win_ptr, 1700, 35, 0XFFFFFF, "_______");
    mlx_string_put(info->mlx_ptr, info->win_ptr, 1650, 100, 0XFFFFFF, "-->\"+\" TO ZOOM IN");
    mlx_string_put(info->mlx_ptr, info->win_ptr, 1650, 150, 0XFFFFFF, "-->\"-\" TO ZOOM OUT"); // ↑ ↓ → ←
    mlx_string_put(info->mlx_ptr, info->win_ptr, 1650, 200, 0XFFFFFF, "-->\" v \" TO MOUVE DOWN");
    mlx_string_put(info->mlx_ptr, info->win_ptr, 1650, 250, 0XFFFFFF, "-->\" ^ \" TO MOUVE UP");
    mlx_string_put(info->mlx_ptr, info->win_ptr, 1650, 300, 0XFFFFFF, "-->\" > \" TO MOUVE RIGHT");
    mlx_string_put(info->mlx_ptr, info->win_ptr, 1650, 350, 0XFFFFFF, "-->\" < \" TO MOUVE LEFT");
    mlx_string_put(info->mlx_ptr, info->win_ptr, 0, 1058, 0XFFFFFF, "@aygaoua coppywright !!");
	while (j_guide < 400)
        mlx_pixel_put(info->mlx_ptr, info->win_ptr, i_guide, j_guide++, 0XFFFFFF);
    while (i_guide < 1920)
        mlx_pixel_put(info->mlx_ptr, info->win_ptr, i_guide++, 400, 0XFFFFFF);
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