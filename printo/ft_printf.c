/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 09:16:06 by azgaoua           #+#    #+#             */
/*   Updated: 2022/12/08 17:23:52 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ifs(va_list args, const char *conver, int *j, int *i)
{
	if (conver[*i] == '%')
		ft_putchar(conver[*i], j);
	else if (conver[*i] == 'c')
		ft_putchar(va_arg(args, int), j);
	else if (conver[*i] == 's')
		ft_putstr(va_arg(args, char *), j);
	else if (conver[*i] == 'd' || conver[*i] == 'i')
		ft_putnbr(va_arg(args, int), j);
	else if (conver[*i] == 'u')
		ft_unbr(va_arg(args, unsigned int), j);
	else if (conver[*i] == 'x')
		ft_hexa(va_arg(args, unsigned int), j);
	else if (conver[*i] == 'X')
		ft_uphexa(va_arg(args, unsigned int), j);
	else if (conver[*i] == 'p')
		ft_pointer(va_arg(args, void *), j);
	else
		ft_putchar(conver[*i], j);
	*i += 1;
}

int	ft_printf(const char *conver, ...)
{
	va_list		args;
	int			i;
	int			j;
	int			n;
	int			r;

	va_start(args, conver);
	i = 0;
	j = 0;
	n = ft_strlen(conver);
	r = write(1, "", 0);
	if (r < 0)
		return (-1);
	while (conver[i])
	{
		if (conver[i] == '%')
		{
			i++;
			ifs(args, conver, &j, &i);
		}
		else if (conver[i] != '%')
			ft_putchar(conver[i++], &j);
	}
	va_end (args);
	return (j);
}
