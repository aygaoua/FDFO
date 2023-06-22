/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 09:16:56 by azgaoua           #+#    #+#             */
/*   Updated: 2022/12/03 09:16:59 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *j)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648", j);
		return ;
	}
	if (n >= 0 && n < 10)
		ft_putchar((char)(n + 48), j);
	else if (n < 0)
	{
		ft_putchar('-', j);
		ft_putnbr((-n), j);
	}
	else if (n > 0)
	{
		ft_putnbr(n / 10, j);
		ft_putnbr(n % 10, j);
	}
}
