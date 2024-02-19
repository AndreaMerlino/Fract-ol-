/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamerlino <andreamerlino@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 19:39:14 by andreamerli       #+#    #+#             */
/*   Updated: 2024/02/17 17:12:56 by andreamerli      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_iteration(t_data *data)
{
	if (data->y > 15)
	{
		data->y = 0;
	}
}

int	handle_input(int keysym, t_data *data)
{
	printf("Key pressed: %d\n", keysym);
	if (keysym == 53)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	else if (keysym == 30 || keysym == 69)
		data->iteration += 10;
	else if (keysym == 44 || keysym == 78)
		data->iteration -= 10;
	else if (keysym == 123)
		data->shift -= (0.5 * data->zoom);
	else if (keysym == 124)
		data->shift += (0.5 * data->zoom);
	else if (keysym == 125)
		data->updown -= (0.5 * data->zoom);
	else if (keysym == 126)
		data->updown += (0.5 * data->zoom);
	else if (keysym == 8)
	{
		data->y += 1;
		color_iteration(data);
	}
	render_mandelbrot(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.mlx_img, 0, 0);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_data *data)
{
	printf("mouse pressed: %d\n", button);
	if (button == 4)
		data->zoom *= 0.5;
	else if (button == 5)
		data->zoom *= 1.5;
	render_mandelbrot(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.mlx_img, 0, 0);
	return (0);
}

int	encode_rgb(unsigned char red, unsigned char green, unsigned char blue)
{
	return (red << 16 | green << 8 | blue);
}

void	set_colors(t_data *data)
{
	data->y = 0;
	data->color[0] = BLACK;
	data->color[1] = WHITE;
	data->color[2] = NEON_PINK;
	data->color[3] = BRIGHT_GREEN;
	data->color[4] = ELECTRIC_BLUE;
	data->color[5] = VIVID_PURPLE;
	data->color[6] = LIME_SHOCK;
	data->color[7] = SUNSET_ORANGE;
	data->color[8] = ELECTRIC_LIME;
	data->color[9] = PSYCHEDELIC_PURPLE;
	data->color[10] = TURQUOISE_DREAM;
	data->color[11] = RADIANT_YELLOW ;
	data->color[12] = CRIMSON_RED ;
	data->color[13] = AZURE_RADIANCE;
	data->color[14] = NEON_CYAN ;
	data->color[15] = HOT_MAGENTA;
}
