/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:03:06 by azgaoua           #+#    #+#             */
/*   Updated: 2023/06/22 19:25:38 by azgaoua          ###   ########.fr       */
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
# include "./printo/ft_printf.h"
# include "./minilibx_macos/mlx.h"

typedef struct
{
    int     width;
    int     height;
    int     **z_mtx;
    
    void    *mlx_ptr;
    void    *win_ptr;
}       fdf;

int    ft_get_height(char *n_file);
int     deal_key(int k, void *inf);
int     ft_get_width(char *n_file);
void    ft_fill_matrix(int *line_z, char *line);
void    ft_read_file(char *n_file, fdf *info);





#endif