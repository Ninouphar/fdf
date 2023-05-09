/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:38:19 by rraffi-k          #+#    #+#             */
/*   Updated: 2023/05/06 17:07:13 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	res;
	int	i;
	int	sign;

	if (!nptr)
		return (0);
	i = 0;
	sign = 1;
	res = 0;
	while (nptr[i] && (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13)))
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		sign = -sign;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res *= 10;
		res = res + (nptr[i] - '0');
		i++;
	}
	return (sign * res);
}

float	ft_atof(const char *nptr)
{
	float	res;
	int		i;
	int		sign;
	char	**nb;

	i = 0;
	sign = 1;
	while (nptr[i] && (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13)))
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		sign = -sign;
		i++;
	}
	nb = ft_split(nptr, '.');
	res = ft_atoi(nb[0]) + (ft_atoi(nb[1]) / pow(10, ft_strlen(nb[1])));
	ft_free(nb, 1);
	return (sign * res);
}

// int	main(int argc, char **argv)
// {
// 	printf("%f", ft_atof(argv[1]));
// 	return (0);
// }
