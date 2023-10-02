/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:09:33 by azgaoua           #+#    #+#             */
/*   Updated: 2023/10/01 23:08:14 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_rotation_z_bonus(float *x, float *y)
{
	float	old_x;
	float	old_y;

	old_x = *x;
	old_y = *y;
	*x = (old_x * cos(TITA)) - (old_y * sin(TITA));
	*y = (old_x * sin(TITA)) + (old_y * cos(TITA)); 
}

void	ft_renew_bonus(int i_guide, int j_guide, t_fdf *info)
{
	mlx_clear_window(info->mlx_ptr, info->win_ptr);
	mlx_destroy_image(info->mlx_ptr, info->mlx.img);
	ft_draw_bonus(info);
	while (j_guide < 400)
		my_mlx_pixel_put_bonus(&info->mlx, i_guide, j_guide++, 0XFFFFFF);
	while (i_guide < 1920)
		my_mlx_pixel_put_bonus(&info->mlx, i_guide++, 400, 0XFFFFFF);
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
}

void	ft_check_rot_bonus(t_cordnt *cordnt, t_fdf *info)
{
	int	i;

	i = 0;
	if (info->rot_z == 12)
		info->rot_z = 0;
	while (info->rot_z - i != 0)
	{
		ft_rotation_z_bonus(&cordnt->x, &cordnt->y);
		ft_rotation_z_bonus(&cordnt->x0, &cordnt->y0);
		i++;
	}
}

void	ft_inits_bonus(t_cordnt *cordnt, int *z, int *z0, t_fdf *info)
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
	ft_zoom_bonus(&cordnt->x, &cordnt->y, info);
	ft_zoom_bonus(&cordnt->x0, &cordnt->y0, info);
	if (info->view % 3 == 0)
	{
		ft_isometric_bonus(&cordnt->x, &cordnt->y, *z, info);
		ft_isometric_bonus(&cordnt->x0, &cordnt->y0, *z0, info);
	}
	ft_check_rot_bonus(cordnt, info);
	ft_shift_bonus(&cordnt->x, &cordnt->y, info);
	ft_shift_bonus(&cordnt->x0, &cordnt->y0, info);
}

void	ft_key_bonus(int k, t_fdf *info)
{
	if (k == 125)
		info->sh_y += 50;
	if (k == 123)
		info->sh_x -= 50;
	if (k == 124)
		info->sh_x += 50;
	if (k == 24)
		info->z_atitude++;
	if (k == 27)
		info->z_atitude--;
	if (k == 69)
		info->zoom++;
	if (k == 78)
		info->zoom /= 1.1;
	if (k == 15)
		info->rot_z++;
	if (k == 35)
		info->view += 1;
}
