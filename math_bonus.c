/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamerlino <andreamerlino@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 19:27:56 by andreamerli       #+#    #+#             */
/*   Updated: 2024/02/18 13:50:27 by andreamerli      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	fractal_map_render(t_data *data, t_fract *fract, int i)
{
	fract->color = linear_interpolation(i, BLACK, WHITE,
			data->iteration);
	img_pix_put(&data->img, fract->c[0], fract->c[1], fract->color);
	i = data->iteration +2;
	return (i);
}

static void	mandelbrot_or_julia(t_fract *fract, t_data *data)
{
	if (data->argc_copia == 2)
	{
		fract->c_double[0] = (linear_interpolation (fract->c[0], -2, +2, 1500)
				* data->zoom) + data->shift;
		fract->c_double[1] = linear_interpolation(fract->c[1], 2, -2, 1500)
			* data->zoom + data->updown;
	}
	else
	{
		fract->c_double[0] = data->julia_x;
		fract->c_double[1] = data->julia_y;
		fract->x = (linear_interpolation (fract->c[0], -2, +2, 1500)
				* data->zoom) + data->shift;
		fract->y = linear_interpolation(fract->c[1], 2, -2, 1500)
			* data->zoom + data->updown;
	}
}

int	madlebrot_calculation(t_fract *fract, t_data *data)
{
	int	i;

	i = 0;
	mandelbrot_or_julia(fract, data);
	while (i <= data->iteration)
	{
		if (data->burning_ship == 2)
			burning_ship(fract);
		fract->x_square = fract->x * fract->x;
		fract->xy = fract->x * fract->y * 2;
		fract->y_square = fract->y * fract->y * -1;
		fract->x = fract->x_square + fract->y_square;
		fract->y = fract->xy;
		fract->x = fract->x + fract->c_double[0];
		fract->y = fract->y + fract->c_double[1];
		if (fract->x < -2 || fract->x > 2 || fract->y < -2 || fract->y > 2)
		{
			i = fractal_map_render(data, fract, i);
			break ;
		}
		i++;
	}
	i--;
	return (i);
}

static void	atod_helper(char **str, t_atod *atod)
{
	while ((**str >= 9 && **str <= 13) || **str == 32)
	{
		(*str)++;
		atod->p++;
	}
	if (*str[0] == '-')
	{
		(*str)++;
		atod->p = *str;
		atod->x = -1;
	}
	while (**str == 48)
	{
		if (**str == '.')
			(*str)++;
		atod->i = atod->i * 10;
		(*str)++;
	}
}

double	atod(char *str)
{
	t_atod	atod;

	atod.x = 1;
	atod.p = str;
	atod.i = 0.1;
	atod.numero = 0;
	atod_helper(&str, &atod);
	while (*str)
	{
		if (*str == '.')
			str++;
		atod.numero = (atod.numero * 10) + (*str - 48);
		atod.i = atod.i * 10;
		str ++;
	}
	return ((atod.numero * atod.x) / atod.i);
}
