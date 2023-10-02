/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:03:06 by azgaoua           #+#    #+#             */
/*   Updated: 2023/10/02 15:18:22 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
# include <math.h>
# include "./libft/libft.h"
# include "./printo/ft_printf.h"
# include <mlx.h>
# define TITA 0.52359877559

typedef struct s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_cordnt
{
	float	x;
	float	x0;
	float	y;
	float	y0;
}			t_cordnt;

typedef struct s_fdf
{
	int			view;
	double		tita;
	int			rot_z;
	int			width;
	int			height;
	int			zoom;
	int			z_atitude;
	int			**z_mtx;
	int			color;
	int			ch_color;
	int			sh_x;
	int			sh_y;
	void		*mlx_ptr;
	void		*win_ptr;
	t_data		mlx;
	t_cordnt	cordnt;
}				t_fdf;

//-----------------------------MANDATORY--------------------------------------//
int			ft_get_height(char *n_file);
int			ft_deal_key(int k);
int			ft_get_width(char *n_file);
void		ft_fill_mtx(int **line_z, char *line, t_fdf *info);
void		ft_read_file(char *n_file, t_fdf *info);
void		ft_bresenham(t_cordnt cordnt, t_fdf *info);
float		ft_mod(float a);
void		ft_draw(t_fdf *info);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		ft_isometric(float *x, float *y, int z, t_fdf *info);
void		ft_zoom(float *x, float *y, t_fdf *info);
void		ft_shift(float *x, float *y, t_fdf *info);
int			ft_max(int a, int b);
int			ft_exit_cross(void *g);
void		ft_init_struct(t_fdf *info);
void		ft_inits(t_cordnt *cordnt, int *z, int *z0, t_fdf *info);

//-------------------------BONUS------------------------------------------//
int			ft_get_height_bonus(char *n_file);
int			ft_deal_key_bonus(int k, t_fdf *info);
int			ft_get_width_bonus(char *n_file);
void		ft_fill_mtx_bonus(int **line_z, char *line, t_fdf *info);
void		ft_read_file_bonus(char *n_file, t_fdf *info);
void		ft_bresenham_bonus(t_cordnt cordnt, t_fdf *info);
float		ft_mod_bonus(float a);
void		ft_draw_bonus(t_fdf *info);
void		my_mlx_pixel_put_bonus(t_data *data, int x, int y, int color);
void		ft_isometric_bonus(float *x, float *y, int z, t_fdf *info);
void		ft_zoom_bonus(float *x, float *y, t_fdf *info);
void		ft_shift_bonus(float *x, float *y, t_fdf *info);
int			ft_max_bonus(int a, int b);
void		ft_rotation_z_bonus(float *x, float *y);
void		ft_renew_bonus(int i_guide, int j_guide, t_fdf *info);
void		ft_other_keys_bonus(int k, t_fdf *info);
int			ft_exit_cross_bonus(void *g);
void		ft_init_struct_bonus(t_fdf *info);
void		ft_inits_bonus(t_cordnt *cordnt, int *z, int *z0, t_fdf *info);
void		ft_check_rot_bonus(t_cordnt *cordnt, t_fdf *info);
void		ft_key_bonus(int k, t_fdf *info);

#endif