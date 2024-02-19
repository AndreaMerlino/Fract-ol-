/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamerlino <andreamerlino@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:54:46 by andreamerli       #+#    #+#             */
/*   Updated: 2024/02/18 18:35:54 by andreamerli      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((i < n - 1) && s1[i] && (s1[i] == s2[i]))
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

void	render_mandelbrot(t_data *data)
{
	t_fract	fract;
	int		i;

	fract.c[1] = 0;
	while (fract.c[1] <= 1500)
	{
		fract.c[0] = 0;
		while (fract.c[0] <= 1500)
		{
			fract.x = 0;
			fract.y = 0;
			i = 0;
			while (i <= data->iteration)
			{
				i = madlebrot_calculation (&fract, data);
				if (i == data->iteration)
					img_pix_put(&data->img, fract.c[0], fract.c[1],
						data->color[data->y]);
				i++;
			}
			fract.c[0] += 1;
		}
		fract.c[1] += 1;
	}
}

void	main_init(t_data *data)
{
	set_colors(data);
	data->zoom = 1;
	data->iteration = 42;
	data->shift = 0;
	data->updown = 0;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1500, 1500, "fract'ol");
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, 1500, 1500);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	render_mandelbrot(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.mlx_img, 0, 0);
	mlx_key_hook(data->win_ptr, &handle_input, data);
	mlx_mouse_hook (data->win_ptr, mouse_handler, data);
		mlx_mouse_get_pos(data->win_ptr, &data->x, &data->xy);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if ((argc == 2 && ft_strncmp(argv[1], "Mandelbrot", 10) == 0)
		|| (argc == 2 && ft_strncmp(argv[1], "BurningShip", 11) == 0)
		|| (argc == 4 && ft_strncmp(argv[1], "Julia", 5) == 0))
	{
		if (argc == 4)
		{
			data.julia_x = atod(argv[2]);
			data.julia_y = atod(argv[3]);
			if (data.julia_x >= 2 || data.julia_x <= -2
				|| data.julia_y >= 2 || data.julia_y <= -2)
				erorr();
		}
		else if (argc == 2 && ft_strncmp(argv[1], "BurningShip", 11) == 0)
			data.burning_ship = 2;
		data.argc_copia = argc;
		main_init(&data);
		mlx_loop(data.mlx_ptr);
	}
	else
		perror(ERROR_MESSAGE "./fractal Julia followed by the"
			" real and immaginary component");
	exit(EXIT_FAILURE);
}
