/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamerlino <andreamerlino@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 13:53:28 by andreamerli       #+#    #+#             */
/*   Updated: 2024/02/18 14:22:28 by andreamerli      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	erorr(void)
{
	perror("\nWrong input for julia try : −0.7269 +0.1889 or try"
		" −0.8 +0.156 or 0.285 +0.01");
	exit(EXIT_FAILURE);
}

void	burning_ship(t_fract *fract)
{
	if (fract->x < 0)
		fract->x *= -1;
	if (fract->y < 0)
		fract->y *= -1;
}

double	linear_interpolation(double unscaled_num, double new_min,
	double new_max, double old_max)
{
	return ((new_max - new_min) * (unscaled_num - 0) / (old_max - 0) + new_min);
}
