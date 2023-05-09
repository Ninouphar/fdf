/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:46:16 by rraffi-k          #+#    #+#             */
/*   Updated: 2023/04/21 09:35:26 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

int	ft_strnchr(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if ((unsigned char)s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strdup_gnl(const char *s)
{
	size_t		i;
	char		*str;
	char		*s_bis;

	i = 0;
	s_bis = (char *)s;
	while (s_bis[i] && s_bis[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) - i) + 1);
	if (!str || !s)
		return (NULL);
	while (s_bis[i])
	{
		str[i] = s_bis[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin_n(char *s1, char *s2)
{
	char	*string;
	int		i;
	int		size;

	size = 0;
	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	string = malloc(sizeof(char) * (size + 1));
	if (!string)
		return (NULL);
	size = -1;
	while (s1[++size])
		string[size] = s1[size];
	i = 0;
	while (s2[i] && s2[i] != '\n')
		string[size++] = s2[i++];
	if (s2[i] == '\n')
	{
		string[size] = '\n';
		size++;
	}
	string[size] = '\0';
	free(s1);
	return (string);
}
