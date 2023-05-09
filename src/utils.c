/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:14:33 by rraffi-k          #+#    #+#             */
/*   Updated: 2023/05/06 17:04:42 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	calculate_width(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	sign(int x)
{
	if (x > 0)
		return (1);
	else if (x < 0)
		return (-1);
	else
		return (0);
}

int	swap_delta(int *dx, int *dy)
{
	int	tmp;
	int	swap;

	swap = 0;
	if (*dy > *dx)
	{
		tmp = *dx;
		*dx = *dy;
		*dy = tmp;
		swap = 1;
	}
	return (swap);
}

void	calculate_pt_1(int swap, t_coord *pt, t_pos my_point, t_pos prev_point)
{
	if (swap)
		pt->x += sign(my_point.x - prev_point.x);
	else
		pt->y += sign(my_point.y - prev_point.y);
}

void	calculate_pt_2(int swap, t_coord *pt, t_pos my_point, t_pos prev_point)
{
	if (swap)
		pt->y += sign(my_point.y - prev_point.y);
	else
		pt->x += sign(my_point.x - prev_point.x);
}
