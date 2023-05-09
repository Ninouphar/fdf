/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:56:31 by rraffi-k          #+#    #+#             */
/*   Updated: 2023/05/08 17:16:29 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include "libft.h"
# include <math.h>

# define WINDOW_WIDTH 1024
# define WINDOW_HEIGHT 1024
# define ANGLE 0.017
# define TILE_SIZE 50
# define TILE_SIZE_X 24
# define TILE_SIZE_Y 12

typedef struct s_coord{
	int	x;
	int	y;
}	t_coord;

typedef struct s_extremes{
	float	x_max;
	float	x_min;
	float	y_max;
	float	y_min;
	float	z_max;
	float	z_min;
}	t_extremes;

typedef struct s_pos{
	float	x;
	float	y;
	float	z;
}	t_pos;

typedef struct s_img{
	void	*mlx;
	int		bpp;
	char	*addr;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data{
	t_extremes	extremes;
	void		*mlx;
	void		*win;
	t_img		img;
	char		**map_0;
	t_pos		**map_origin;
	t_pos		**map_display;
	int			width;
	int			height;
	float		scale;
	float		z_factor;
}	t_data;

int		deal_key(int keysym, t_data *data);
char	**get_map(int fd, int *height);
void	my_pixel_put(t_img *img, int x, int y, int color);
int		render(t_data *data);
t_pos	**first_map(char **map_lines, int height, int *width);
t_pos	**set_map(t_data *data, int fd);
t_pos	**copy_map(t_pos **first_map, int height, int width);
int		calculate_width(char **str);
char	**free_str(char *str);
t_pos	**free_map(t_pos **map_display, int height);
int		render(t_data *data);
int		sign(int x);
int		swap_delta(int *dx, int *dy);
void	drawline(t_pos previous_point, t_pos my_point, t_data *data);
void	correct_display(t_data *data, t_extremes *extremes, float scale);
void	correct_location(t_data *data, t_extremes extremes);
void	correct_scale(t_data *data, float scale);
void	fetch_extremes(t_data *data, t_pos **map, t_extremes *extr);
void	rotate_right(t_data *data, t_pos **map);
void	rotate_left(t_data *data, t_pos **map);
void	transf(t_data *data);
void	initialize_extr(t_extremes *extr);
int		deal_mouse(int mousecode, int x, int y, t_data *data);
int		are_on_screen(t_pos previous_point, t_pos my_point);
int		close_win(t_data *data);
void	fill_first_map(t_pos **first_map, char **line_coord, int i, int j);
void	initiate_data(t_data *data, int fd);
void	open_window(t_data *data);
void	calculate_pt_1(int swap, t_coord *pt,
			t_pos my_point, t_pos prev_point);
void	calculate_pt_2(int swap, t_coord *pt,
			t_pos my_point, t_pos prev_point);
void	beurre(char **line_coord, int width);

#endif
