/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:21:25 by rraffi-k          #+#    #+#             */
/*   Updated: 2023/05/06 16:26:53 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	deal_right(t_data *data)
{
	rotate_right(data, data->map_origin);
	transf(data);
	correct_display(data, &data->extremes, data->scale);
}

void	deal_left(t_data *data)
{
	rotate_left(data, data->map_origin);
	transf(data);
	correct_display(data, &data->extremes, data->scale);
}

void	deal_z_up(t_data *data)
{
	if (data->img.addr)
		ft_bzero(data->img.addr, (data->img.bpp / 8) * WINDOW_WIDTH
			+ (data->img.line_len) * WINDOW_HEIGHT - 1);
	data->z_factor += 0.2;
	transf(data);
	correct_display(data, &data->extremes, data->scale);
}

void	deal_z_down(t_data *data)
{
	if (data->img.addr)
		ft_bzero(data->img.addr, (data->img.bpp / 8) * WINDOW_WIDTH
			+ (data->img.line_len) * WINDOW_HEIGHT - 1);
	data->z_factor -= 0.2;
	transf(data);
	correct_display(data, &data->extremes, data->scale);
}

int	deal_key(int keysym, t_data *data)
{
	if (keysym == XK_Right)
		deal_right(data);
	if (keysym == XK_Left)
		deal_left(data);
	if (keysym == XK_z)
		deal_z_up(data);
	if (keysym == XK_x)
		deal_z_down(data);
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
	}
	return (0);
}
