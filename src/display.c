/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:58:59 by rraffi-k          #+#    #+#             */
/*   Updated: 2023/05/06 16:06:03 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	correct_display(t_data *data, t_extremes *extremes, float scale)
{
	correct_scale(data, scale);
	fetch_extremes(data, data->map_display, extremes);
	correct_location(data, *extremes);
}

void	correct_location(t_data *data, t_extremes extremes)
{
	int		i;
	int		j;
	float	dist_x;
	float	dist_y;

	dist_x = (WINDOW_WIDTH / 2) - ((extremes.x_max + extremes.x_min) / 2);
	dist_y = (WINDOW_HEIGHT / 2) - ((extremes.y_max + extremes.y_min) / 2);
	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			data->map_display[i][j].x = (data->map_display[i][j].x + dist_x);
			data->map_display[i][j].y = (data->map_display[i][j].y + dist_y);
			j++;
		}
		i++;
	}
}

void	correct_scale(t_data *data, float scale)
{
	int		i;
	int		j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			data->map_display[i][j].x = data->map_display[i][j].x / scale;
			data->map_display[i][j].y = data->map_display[i][j].y / scale;
			j++;
		}
		i++;
	}
}

void	initialize_extr(t_extremes *extr)
{
	extr->x_max = 0;
	extr->x_min = 0;
	extr->y_max = 0;
	extr->y_min = 0;
	extr->z_max = 0;
	extr->z_min = 0;
}

void	fetch_extremes(t_data *data, t_pos **map, t_extremes *extr)
{
	int	i;
	int	j;

	initialize_extr(extr);
	i = -1;
	while (++i < data->height)
	{
		j = -1;
		while (++j < data->width)
		{
			if (extr->x_max < map[i][j].x)
				extr->x_max = map[i][j].x;
			if (extr->x_min > map[i][j].x)
				extr->x_min = map[i][j].x;
			if (extr->y_max < map[i][j].y)
				extr->y_max = map[i][j].y;
			if (extr->y_min > map[i][j].y)
				extr->y_min = map[i][j].y;
			if (extr->z_max < map[i][j].z)
				extr->z_max = map[i][j].z;
			if (extr->z_min > map[i][j].z)
				extr->z_min = map[i][j].z;
		}
	}
}
