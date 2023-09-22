/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:21:50 by azgaoua           #+#    #+#             */
/*   Updated: 2023/09/22 03:29:08 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    ft_rotation_z(float *x, float *y)
{
    float old_x;
    float old_y;

    old_x = *x;
    old_y = *y;
    *x = old_x * cos(TITA) - old_y * sin(TITA);
    *y = old_x * sin(TITA) + old_y * cos(TITA); 
}

void    ft_rotation_x(float *y, int *z)
{
    float old_y;
    int old_z;

    old_y = *y;
    old_z = *z;
    *y = old_y * cos(TITA) + old_z * sin(TITA);
    *z = -old_y * sin(TITA) + old_z * cos(TITA);
}

void    ft_rotation_y(float *x, int *z)
{
    float old_x;
    int old_z;

    old_x = *x;
    old_z = *z;
    *x = old_x * cos(TITA) + old_z * sin(TITA);
    *z = -old_x * sin(TITA) + old_z * cos(TITA);
}

int ft_exit_cross(void *g)
{
    g = NULL;
    printf("use the keyboard to start !!");
    exit(0);
}

int ft_deal_key_1(int k, fdf *info)
{
    int	i_guide = 1590;
	int	j_guide = 0;
    
    printf("Key : %d\n", k);
    if (k == 53)
    {
        printf("use the keyboard to start !!");
        exit(0);
    }
    if (k == 48 && info->tita > -1 * M_PI_2)
        info->tita -= 0.1;
    if (k == 257 && info->tita < M_PI_2)
        info->tita += 0.1;
    if (k == 256)
        info->tita = M_PI / 6;
    if (k == 126)
        info->sh_y -= 10;
    if (k == 125)
        info->sh_y += 10;
    if (k == 123)
        info->sh_x -= 10;
    if (k == 124)
        info->sh_x += 10;
    if ((k == 69 || k == 24))
        info->zoom += 1;
    if ((k == 78 || k == 27))
        info->zoom /= 1.1;
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
    mlx_string_put(info->mlx_ptr, info->win_ptr, 1650, 100, 0XFFFFFF, "-->\"+\" TO ZOOM IN");
    mlx_string_put(info->mlx_ptr, info->win_ptr, 1650, 150, 0XFFFFFF, "-->\"-\" TO ZOOM OUT"); // ↑ ↓ → ←
    mlx_string_put(info->mlx_ptr, info->win_ptr, 1650, 200, 0XFFFFFF, "-->\" v \" TO MOUVE DOWN");
    mlx_string_put(info->mlx_ptr, info->win_ptr, 1650, 250, 0XFFFFFF, "-->\" ^ \" TO MOUVE UP");
    mlx_string_put(info->mlx_ptr, info->win_ptr, 1650, 300, 0XFFFFFF, "-->\" > \" TO MOUVE RIGHT");
    mlx_string_put(info->mlx_ptr, info->win_ptr, 1650, 350, 0XFFFFFF, "-->\" < \" TO MOUVE LEFT");
    mlx_string_put(info->mlx_ptr, info->win_ptr, 0, 1058, 0XFFFFFF, "@aygaoua copyright©. !!");
    return (0);
}

int ft_deal_key(int k, fdf *info)
{
    int	i_guide = 1590;
	int	j_guide = 0;
    
    if (k == 8)
    {
        if (info->ch_color == 2)
            info->ch_color = 0;
        else if (info->ch_color == 0)
            info->ch_color = 1;
        else if (info->ch_color == 1)
            info->ch_color = 2;
    }
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
    mlx_string_put(info->mlx_ptr, info->win_ptr, 1650, 100, 0XFFFFFF, "-->\"+\" TO ZOOM IN");
    mlx_string_put(info->mlx_ptr, info->win_ptr, 1650, 150, 0XFFFFFF, "-->\"-\" TO ZOOM OUT"); // ↑ ↓ → ←
    mlx_string_put(info->mlx_ptr, info->win_ptr, 1650, 200, 0XFFFFFF, "-->\" v \" TO MOUVE DOWN");
    mlx_string_put(info->mlx_ptr, info->win_ptr, 1650, 250, 0XFFFFFF, "-->\" ^ \" TO MOUVE UP");
    mlx_string_put(info->mlx_ptr, info->win_ptr, 1650, 300, 0XFFFFFF, "-->\" > \" TO MOUVE RIGHT");
    mlx_string_put(info->mlx_ptr, info->win_ptr, 1650, 350, 0XFFFFFF, "-->\" < \" TO MOUVE LEFT");
    mlx_string_put(info->mlx_ptr, info->win_ptr, 0, 1058, 0XFFFFFF, "@aygaoua copyright©. !!");
    return (0);
}

int main(int ac, char **av)
{
    fdf *info;
    void *walo = NULL;
    
    if (ac != 2 || ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".fdf", 4) || open(av[1], O_RDONLY, 0) == -1) // check if file is .fdf or not
    {
        printf("Do this : ./fdf <filename>\n");
        return (0);
    }
    info = (fdf*)malloc(sizeof(fdf));
    ft_read_file(av[1], info);
	info->mlx_ptr = mlx_init();
	info->win_ptr = mlx_new_window(info->mlx_ptr, 1920, 1080, "fdf");
    info->mlx.img = mlx_new_image(info->mlx_ptr, 1920, 1080);
	info->mlx.addr = mlx_get_data_addr(info->mlx.img, &info->mlx.bits_per_pixel, &info->mlx.line_length,
								&info->mlx.endian);
    info->zoom = (info->width + 1) / info->height;
    ft_draw(info);
    info->tita = TITA;
    info->ch_color = 0;
	mlx_key_hook(info->win_ptr, ft_deal_key_1, info);
    mlx_hook(info->win_ptr, 2, 0, ft_deal_key, info);
    mlx_hook(info->win_ptr, 17, 0, ft_exit_cross, walo);
    mlx_loop(info->mlx_ptr);
    return (0);
}
