/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:17:13 by rraffi-k          #+#    #+#             */
/*   Updated: 2023/05/06 17:04:39 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//https://dev.to/ndesmic/linear-color-gradients-from-scratch-1a0e

void	transf(t_data *data)
{
	int		i;
	int		j;
	float	x;
	float	y;
	float	z;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			x = data->map_origin[i][j].x;
			y = data->map_origin[i][j].y;
			z = data->map_origin[i][j].z;
			data->map_display[i][j].x = (x + y) * TILE_SIZE_X;
			data->map_display[i][j].y = (x - y) * TILE_SIZE_Y
				- data->z_factor * z;
			j++;
		}
		i++;
	}
}

void	drawline(t_pos previous_point, t_pos my_point, t_data *data)
{
	t_coord	pt;
	t_coord	dt;
	int		swap;
	int		p;
	int		i;

	pt.x = previous_point.x;
	pt.y = previous_point.y;
	dt.x = abs((int)my_point.x - (int)previous_point.x);
	dt.y = abs((int)my_point.y - (int)previous_point.y);
	swap = swap_delta(&dt.x, &dt.y);
	p = 2 * dt.y - dt.x;
	i = -1;
	while (++i < dt.x)
	{
		if (pt.x > 0 && pt.y > 0 && pt.x < WINDOW_WIDTH && pt.y < WINDOW_HEIGHT)
			my_pixel_put(&data->img, pt.x, pt.y, 0x06B8EF);
		while (p >= 0)
		{
			p = p - 2 * dt.x;
			calculate_pt_1(swap, &pt, my_point, previous_point);
		}
		p = p + 2 * dt.y;
		calculate_pt_2(swap, &pt, my_point, previous_point);
	}
}

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + y * img->line_len + x * (img->bpp / 8);
	*(int *)pixel = color;
}

int	are_on_screen(t_pos previous_point, t_pos my_point)
{
	if ((previous_point.x > 0 && previous_point.y > 0
			&& previous_point.x < WINDOW_WIDTH
			&& previous_point.y < WINDOW_HEIGHT)
		|| (my_point.x > 0 && my_point.y > 0
			&& my_point.x < WINDOW_WIDTH && my_point.y < WINDOW_HEIGHT))
		return (1);
	else
		return (0);
}

int	render(t_data *data)
{
	int		i;
	int		j;

	if (data->win)
	{
		i = -1;
		while (++i < data->height)
		{
			j = -1;
			while (++j < data->width)
			{
				if (i > 0 && are_on_screen(data->map_display[i - 1][j],
					data->map_display[i][j]))
					drawline(data->map_display[i - 1][j],
						data->map_display[i][j], data);
				if (j > 0 && are_on_screen(data->map_display[i][j - 1],
					data->map_display[i][j]))
					drawline(data->map_display[i][j - 1],
						data->map_display[i][j], data);
			}
		}
		mlx_put_image_to_window(data->mlx, data->win, data->img.mlx, 0, 0);
	}
	return (0);
}
