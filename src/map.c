/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:12:28 by rraffi-k          #+#    #+#             */
/*   Updated: 2023/05/08 17:05:38 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pos	**copy_map(t_pos **first_map, int height, int width)
{
	t_pos		**new_map;
	int			i;
	int			j;

	i = -1;
	new_map = malloc(sizeof(*new_map) * (height + 1));
	if (!new_map)
		return (free_map(new_map, 0));
	while (first_map[++i])
	{
		new_map[i] = malloc(sizeof(**new_map) * (width + 1));
		if (!new_map[i])
			return (free_map(new_map, i));
		j = -1;
		while (++j < width)
		{
			new_map[i][j].x = j;
			new_map[i][j].y = i;
			new_map[i][j].z = first_map[i][j].z;
		}
	}
	new_map[i] = NULL;
	return (new_map);
}

char	**get_map(int fd, int *height)
{
	int		i;
	char	*buffer;
	char	*tmp_buffer;
	char	*line;
	char	**map_lines;

	buffer = ft_strdup("");
	tmp_buffer = buffer;
	line = get_next_line(fd);
	if (!ft_strlen(line))
		return (free_str(buffer));
	i = 0 ;
	while (line)
	{
		buffer = ft_strjoin(buffer, line);
		free(line);
		free(tmp_buffer);
		tmp_buffer = buffer;
		line = get_next_line(fd);
		i++;
	}
	*height = i;
	map_lines = ft_split(buffer, '\n');
	free(buffer);
	return (map_lines);
}

t_pos	**set_map(t_data *data, int fd)
{
	char	**map_0;
	t_pos	**map_display;

	map_0 = get_map(fd, &data->height);
	if (!map_0)
		return (NULL);
	data->map_origin = first_map(map_0, data->height, &data->width);
	if (!(*(data->map_origin)))
	{
		ft_free(map_0, data->height);
		return (NULL);
	}
	map_display = copy_map(data->map_origin, data->height, data->width);
	if (!map_display)
	{
		ft_free(map_0, data->height);
		free_map(data->map_origin, data->height);
		return (NULL);
	}
	ft_free(map_0, data->height);
	return (map_display);
}

void	fill_first_map(t_pos **first_map, char **line_coord, int i, int j)
{
	first_map[i][j].x = i;
	first_map[i][j].y = j;
	first_map[i][j].z = ft_atof(line_coord[j]);
}

t_pos	**first_map(char **map_lines, int height, int *width)
{
	char		**line_coord;
	t_pos		**first_map;
	int			i;
	int			j;

	i = -1;
	first_map = malloc(sizeof(*first_map) * (height + 1));
	if (!first_map)
		return (free_map(first_map, 0));
	while (map_lines[++i])
	{
		line_coord = ft_split(map_lines[i], ' ');
		if (!line_coord)
			return (free_map(first_map, i));
		*width = calculate_width(line_coord);
		first_map[i] = malloc(sizeof(**first_map) * (*width + 1));
		if (!first_map[i])
			return (free_map(first_map, i));
		j = -1;
		while (++j < *width)
			fill_first_map(first_map, line_coord, i, j);
		beurre(line_coord, *width);
	}
	first_map[i] = NULL;
	return (first_map);
}
