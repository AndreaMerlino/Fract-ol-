/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamerlino <andreamerlino@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 19:39:14 by andreamerli       #+#    #+#             */
/*   Updated: 2024/02/15 11:44:47 by andreamerli      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_input(int keysym, t_data *data)
{
	printf("Key pressed: %d\n", keysym);
	if (keysym == 53) //it shoul be XK_Escape but on my MAc is not working
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
