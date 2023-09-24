/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:54:17 by azgaoua           #+#    #+#             */
/*   Updated: 2023/09/23 21:32:39 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_rotation_z(float *x, float *y)
{
	float	old_x;
	float	old_y;

	old_x = *x;
	old_y = *y;
	*x = old_x * cos(TITA) - old_y * sin(TITA);
	*y = old_x * sin(TITA) + old_y * cos(TITA); 
}

void	ft_rotation_x(float *y, int *z)
{
	float	old_y;
	int		old_z;

	old_y = *y;
	old_z = *z;
	*y = old_y * cos(TITA) + old_z * sin(TITA);
	*z = -old_y * sin(TITA) + old_z * cos(TITA);
}

void	ft_rotation_y(float *x, int *z)
{
	float	old_x;
	int		old_z;

	old_x = *x;
	old_z = *z;
	*x = old_x * cos(TITA) + old_z * sin(TITA);
	*z = -old_x * sin(TITA) + old_z * cos(TITA);
}

void	ft_renew(int i_guide, int j_guide, t_fdf *info)
{
	mlx_clear_window(info->mlx_ptr, info->win_ptr);
	mlx_destroy_image(info->mlx_ptr, info->mlx.img);
	ft_draw(info);
	while (j_guide < 400)
		my_mlx_pixel_put(&info->mlx, i_guide, j_guide++, 0XFFFFFF);
	while (i_guide < 1920)
		my_mlx_pixel_put(&info->mlx, i_guide++, 400, 0XFFFFFF);
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->mlx.img, 0, 0); 
	mlx_string_put(info->mlx_ptr, info->win_ptr, 1700, 30, 0XFF0000, "GUIDE :");
	mlx_string_put(info->mlx_ptr, info->win_ptr, 1700, 35, 0XFFFFFF, "_______");
	mlx_string_put(info->mlx_ptr, info->win_ptr, 1650, 100, 0XFFFFFF, \
					"-->\"+\" TO ZOOM IN");
	mlx_string_put(info->mlx_ptr, info->win_ptr, 1650, 150, 0XFFFFFF, \
					"-->\"-\" TO ZOOM OUT");
	mlx_string_put(info->mlx_ptr, info->win_ptr, 1650, 200, 0XFFFFFF, \
					"-->\" v \" TO MOUVE DOWN");
	mlx_string_put(info->mlx_ptr, info->win_ptr, 1650, 250, 0XFFFFFF, \
					"-->\" ^ \" TO MOUVE UP");
	mlx_string_put(info->mlx_ptr, info->win_ptr, 1650, 300, 0XFFFFFF, \
					"-->\" > \" TO MOUVE RIGHT");
	mlx_string_put(info->mlx_ptr, info->win_ptr, 1650, 350, 0XFFFFFF, \
					"-->\" < \" TO MOUVE LEFT");
	mlx_string_put(info->mlx_ptr, info->win_ptr, 0, 1058, 0XFFFFFF, \
					"@aygaoua copyright©. !!");
}

void	ft_inits(t_cordnt *cordnt, int *z, int *z0, t_fdf *info)
{
	*z = info->z_mtx[(int)cordnt->y][(int)cordnt->x];
	*z0 = info->z_mtx[(int)cordnt->y0][(int)cordnt->x0];
	if (*z)
		*z *= info->z_atitude;
	if (*z0)
		*z0 *= info->z_atitude;
	if ((*z0 || *z) && info->ch_color == 0)
		info->color = 0X00FFFF;
	else if ((*z0 || *z) && info->ch_color == 1)
		info->color = 0XFF0000;
	else if ((*z0 || *z) && info->ch_color == 2)
		info->color = 0XFF00FF;
	else
		info->color = 0XFFFFFF;
	ft_zoom(&cordnt->x, &cordnt->y, info);
	ft_zoom(&cordnt->x0, &cordnt->y0, info);
	ft_isometric(&cordnt->x, &cordnt->y, *z, info);
	ft_isometric(&cordnt->x0, &cordnt->y0, *z0, info);
	ft_shift(&cordnt->x, &cordnt->y, info);
	ft_shift(&cordnt->x0, &cordnt->y0, info);
}
