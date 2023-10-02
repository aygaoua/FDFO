/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:02:57 by azgaoua           #+#    #+#             */
/*   Updated: 2023/10/01 22:31:35 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_fdf		*info;
	int			fd;

	fd = open(av[1], O_RDONLY, 0);
	if (ac != 2 || ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".fdf", 4) || \
		fd < 0)
	{
		ft_printf("Do this : ./fdf <filename.fdf(with read permission)>\n");
		return (0);
	}
	close(fd);
	info = (t_fdf *)malloc(sizeof(t_fdf));
	if (info == NULL)
		exit(1);
	ft_read_file_bonus(av[1], info);
	ft_init_struct_bonus(info);
	ft_draw_bonus(info);
	mlx_hook(info->win_ptr, 2, 0, ft_deal_key_bonus, info);
	mlx_key_hook(info->win_ptr, ft_deal_key_bonus, info);
	mlx_hook(info->win_ptr, 17, 0, ft_exit_cross_bonus, info);
	mlx_loop(info->mlx_ptr);
	return (0);
}

int	ft_exit_cross_bonus(void *g)
{
	g = NULL;
	ft_printf("good bye, have a nice day !!");
	exit(0);
}

int	ft_deal_key_bonus(int k, t_fdf *info)
{
	int	i_guide;
	int	j_guide;

	j_guide = 0;
	i_guide = 1590;
	ft_printf("Key : %d\n", k);
	if (k == 53)
	{
		ft_printf("good bye, have a nice day !!");
		exit(0);
	}
	if (k == 8)
	{
		if (info->ch_color == 2)
			info->ch_color = 0;
		else if (info->ch_color == 0)
			info->ch_color = 1;
		else if (info->ch_color == 1)
			info->ch_color = 2;
	}
	ft_other_keys_bonus(k, info);
	ft_renew_bonus(i_guide, j_guide, info);
	return (0);
}

void	ft_other_keys_bonus(int k, t_fdf *info)
{
	if (k == 48)
		info->tita -= 0.1;
	if (k == 50)
		info->tita += 0.1;
	if (k == 256)
		info->tita = M_PI / 6;
	if (k == 126)
		info->sh_y -= 50;
	ft_key_bonus(k, info);
}

void	ft_init_struct_bonus(t_fdf *info)
{
	float	ratio_w;
	float	ratio_h;

	ratio_w = (float )(1920 / info->width);
	ratio_h = (float )(1080 / info->height);
	info->mlx_ptr = mlx_init();
	info->win_ptr = mlx_new_window(info->mlx_ptr, 1920, 1080, "fdf");
	info->mlx.img = mlx_new_image(info->mlx_ptr, 1920, 1080);
	info->mlx.addr = mlx_get_data_addr(info->mlx.img, \
	&info->mlx.bits_per_pixel, &info->mlx.line_length, &info->mlx.endian);
	info->tita = TITA;
	info->z_atitude = 1;
	info->ch_color = 0;
	info->view = 0;
	if ((float )(info->width / info->height) > (float )(16 / 9))
		info->zoom = (int )(ratio_w) + 1;
	else
		info->zoom = (int )(ratio_h) / 1.5;
	info->rot_z = 0;
}
