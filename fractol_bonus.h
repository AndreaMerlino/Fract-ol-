/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamerlino <andreamerlino@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:16:14 by andreamerli       #+#    #+#             */
/*   Updated: 2024/02/18 18:33:35 by andreamerli      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx_opengl_20191021/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <X11/keysym.h>
# include <unistd.h>

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define NEON_PINK 0xFF6EC7
# define BRIGHT_GREEN 0x4DE94C
# define ELECTRIC_BLUE 0x4D4DFE
# define VIVID_PURPLE 0x9400D3
# define LIME_SHOCK 0xC0FB2D
# define SUNSET_ORANGE 0xFF5F1F
# define ELECTRIC_LIME 0xCCFF00
# define PSYCHEDELIC_PURPLE 0xDF00FF
# define HOT_MAGENTA 0xFF1DCE
# define TURQUOISE_DREAM 0x30D5C8
# define RADIANT_YELLOW 0xFFD400
# define CRIMSON_RED 0xFF0038
# define AZURE_RADIANCE 0x007FFF
# define NEON_CYAN 0x00FFFF
# define ALTEZZA 1500
# define LARGHEZZA 1500
# define ERROR_MESSAGE "Wrong input try: ./fractal and just Mandelbrot,or"

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	int		*x;
	int		xy;
	void	*mlx_ptr;
	void	*win_ptr;
	double	zoom;
	double	julia_x;
	double	julia_y;
	int		iteration;
	int		y;
	double	shift;
	double	updown;
	int		argc_copia;
	int		color[16];
	int		burning_ship;
	t_img	img;
}	t_data;

typedef struct s_fract
{
	int		x_;
	int		y_;
	double	x;
	double	y;
	double	x_square;
	double	y_square;
	double	xy;
	double	c_double[2];
	double	c[2];
	int		color;
	int		i;
}	t_fract;

typedef struct s_atod
{
	int		x;
	double	i;
	double	numero;
	char	*p;
}	t_atod;

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

int		madlebrot_calculation(t_fract *fract, t_data *data);
int		mouse_handler(int button, int x, int y, t_data *data);
int		handle_input(int keysym, t_data *data);
double	atod( char *str);
double	linear_interpolation(double unscaled_num, double new_min,
			double new_max, double old_max);
void	img_pix_put(t_img *img, int x, int y, int color);
void	render_mandelbrot(t_data *data);
void	set_colors(t_data *data);
void	color_iteration(t_data *data);
void	erorr(void);
void	burning_ship(t_fract *fract);

#endif
