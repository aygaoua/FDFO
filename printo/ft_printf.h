/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 09:16:26 by azgaoua           #+#    #+#             */
/*   Updated: 2022/12/03 09:16:29 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>

int		ft_printf(const char *conver, ...);
void	ifs(va_list args, const char *conver, int *j, int *i);
size_t	ft_strlen(const char *str);
void	ft_putchar(char c, int *j);
void	ft_putnbr(int n, int *j);
void	ft_putstr(char *s, int *j);
void	ft_pointer(void *p, int *j);
void	ft_uphexa(unsigned int n, int *j);
void	ft_hexa(unsigned long long n, int *j);
void	ft_unbr(unsigned int n, int *j);

#endif
