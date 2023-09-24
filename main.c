/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:21:50 by azgaoua           #+#    #+#             */
/*   Updated: 2023/09/24 22:59:54 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void vv()
{
	system("leaks fdf");
}
int	main(int ac, char **av)
{
	t_fdf		*info;

	atexit(vv);
	if (ac != 2 || ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".fdf", 4) || \
		open(av[1], O_RDONLY, 0) == -1)
	{
		ft_printf("Do this : ./fdf <filename>\n");
		return (0);
	}
	info = (t_fdf *)malloc(sizeof(t_fdf));
	ft_read_file(av[1], info);
	ft_init_struct(info);
	ft_draw(info);
	mlx_hook(info->win_ptr, 2, 0, ft_deal_key, info);
	mlx_key_hook(info->win_ptr, ft_deal_key, info);
	mlx_hook(info->win_ptr, 17, 0, ft_exit_cross, info);
	mlx_loop(info->mlx_ptr);
	return (0);
}

int	ft_exit_cross(void *g)
{
	g = NULL;
	ft_printf("good bye, have a nice day !!");
	exit(0);
}

int	ft_deal_key(int k, t_fdf *info)
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
	ft_other_keys(k, info);
	ft_renew(i_guide, j_guide, info);
	return (0);
}

void	ft_other_keys(int k, t_fdf *info)
{
	if (k == 48)
		info->tita -= 0.1;
	if (k == 50)
		info->tita += 0.1;
	if (k == 256)
		info->tita = M_PI / 6;
	if (k == 126)
		info->sh_y -= 50;
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
		info->zoom += 1;
	if (k == 78)
		info->zoom /= 1.1;
}

void	ft_init_struct(t_fdf *info)
{
	info->mlx_ptr = mlx_init();
	info->win_ptr = mlx_new_window(info->mlx_ptr, 1920, 1080, "fdf");
	info->mlx.img = mlx_new_image(info->mlx_ptr, 1920, 1080);
	info->mlx.addr = mlx_get_data_addr(info->mlx.img, \
	&info->mlx.bits_per_pixel, &info->mlx.line_length, &info->mlx.endian);
	info->tita = TITA;
	info->z_atitude = 1;
	info->ch_color = 0;
	info->zoom = (info->height / info->width);
}
