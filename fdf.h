/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:03:06 by azgaoua           #+#    #+#             */
/*   Updated: 2023/09/18 03:02:27 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
# include <math.h>
# include "./libft/libft.h"
# include <mlx.h>
# define TITA 0.423599

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct fdfo
{
	int	width;
	int	height;
	int	zoom;
	int z;
	int	**z_mtx;
	int	color;
	int	sh_x;
	int	sh_y;
	t_data	mlx;
	void	*mlx_ptr;
	void	*win_ptr;
}			fdf;

int			ft_get_height(char *n_file);
int			ft_deal_key(int k, fdf *info);
int			ft_get_width(char *n_file);
void		ft_fill_matrix(int *line_z, char *line);
void		ft_read_file(char *n_file, fdf *info);
void		bresenham(float x, float y, float x0, float y0, fdf *info);
float		ft_mod(float a);
void		ft_draw(fdf *info);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		ft_isometric(float *x, float *y, int z);
void		ft_zoom(float *x, float *y, fdf *info);
void		ft_shift(float *x, float *y, fdf *info);
void		ftget_e_x_and_e_y(float *e_x, float *e_y);
int			max(int a, int b);


#endif