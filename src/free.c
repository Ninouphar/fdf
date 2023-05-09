/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:45:26 by rraffi-k          #+#    #+#             */
/*   Updated: 2023/05/08 17:16:27 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**free_str(char *str)
{
	free(str);
	return (NULL);
}

t_pos	**free_map(t_pos **map_display, int height)
{
	while (height)
	{
		free(map_display[height]);
		height--;
	}
	free(map_display[0]);
	free(map_display);
	return (NULL);
}

void	beurre(char **line_coord, int width)
{
	ft_free(line_coord, width);
	line_coord = NULL;
}
