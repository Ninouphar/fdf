/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 15:11:03 by rraffi-k          #+#    #+#             */
/*   Updated: 2023/05/06 16:46:05 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initiate_data(t_data *data, int fd)
{
	float	dist_x_extremes;
	float	dist_y_extremes;

	data->map_display = set_map(data, fd);
	if (!data->map_display)
		exit(0);
	data->z_factor = 1;
	transf(data);
	fetch_extremes(data, data->map_display, &data->extremes);
	dist_x_extremes = fabs(data->extremes.x_max - data->extremes.x_min);
	dist_y_extremes = fabs(data->extremes.y_max - data->extremes.y_min);
	data->scale = fmax(dist_x_extremes / WINDOW_WIDTH,
			dist_y_extremes / WINDOW_HEIGHT);
	correct_display(data, &data->extremes, data->scale);
}

void	open_window(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		exit (0);
	data->win = mlx_new_window(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "hello");
	if (!data->win)
	{
		free(data->win);
		exit (0);
	}
	data->img.mlx = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.mlx, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		fd;
	char	*file;

	(void) argc;
	file = argv[1];
	fd = open(file, 2);
	initiate_data(&data, fd);
	open_window(&data);
	mlx_loop_hook(data.mlx, &render, &data);
	mlx_hook(data.win, ButtonPress, ButtonPressMask, &deal_mouse, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, &deal_key, &data);
	mlx_hook(data.win, 17, 0L, &close_win, &data);
	mlx_loop(data.mlx);
	mlx_destroy_image(data.mlx, data.img.mlx);
	mlx_destroy_display(data.mlx);
	free_map(data.map_origin, data.height);
	free_map(data.map_display, data.height);
	free(data.mlx);
	return (0);
}
