/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:25:56 by rraffi-k          #+#    #+#             */
/*   Updated: 2023/05/06 16:21:37 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_mouse(int mousecode, int x, int y, t_data *data)
{
	if (mousecode == 4)
	{
		if (data->img.addr)
			ft_bzero(data->img.addr, (data->img.bpp / 8) * WINDOW_WIDTH
				+ (data->img.line_len) * WINDOW_HEIGHT - 1);
		data->scale /= 1.1;
		transf(data);
		correct_display(data, &data->extremes, data->scale);
	}
	if (mousecode == 5)
	{
		if (data->img.addr)
			ft_bzero(data->img.addr, (data->img.bpp / 8) * WINDOW_WIDTH
				+ (data->img.line_len) * WINDOW_HEIGHT - 1);
		data->scale *= 1.1;
		transf(data);
		correct_display(data, &data->extremes, data->scale);
	}
	(void) x;
	(void) y;
	return (0);
}

int	close_win(t_data *data)
{
	free_map(data->map_origin, data->height);
	free_map(data->map_display, data->height);
	free(data->mlx);
	exit(0);
	return (0);
}

void	rotate_left(t_data *data, t_pos **map)
{
	int		i;
	int		j;
	float	cos_angle;
	float	sin_angle;
	float	tmp;

	if (data->img.addr)
		ft_bzero(data->img.addr, (data->img.bpp / 8) * WINDOW_WIDTH
			+ (data->img.line_len) * WINDOW_HEIGHT - 1);
	cos_angle = cos(ANGLE);
	sin_angle = sin(ANGLE);
	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			tmp = map[i][j].x;
			map[i][j].x = cos_angle * map[i][j].x + sin_angle * map[i][j].y;
			map[i][j].y = -sin_angle * tmp + cos_angle * map[i][j].y;
			j++;
		}
		i++;
	}
}

void	rotate_right(t_data *data, t_pos **map)
{
	int		i;
	int		j;
	float	cos_angle;
	float	sin_angle;
	float	tmp;

	if (data->img.addr)
		ft_bzero(data->img.addr, (data->img.bpp / 8) * WINDOW_WIDTH
			+ (data->img.line_len) * WINDOW_HEIGHT - 1);
	cos_angle = cos(ANGLE);
	sin_angle = sin(ANGLE);
	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			tmp = map[i][j].x;
			map[i][j].x = cos_angle * map[i][j].x - sin_angle * map[i][j].y;
			map[i][j].y = sin_angle * tmp + cos_angle * map[i][j].y;
			j++;
		}
		i++;
	}
}
