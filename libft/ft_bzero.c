/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:55:28 by rraffi-k          #+#    #+#             */
/*   Updated: 2023/05/09 16:22:39 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*uchar;
	uint64_t		*uint;
	size_t			m;

	m = n / 8;
	uchar = (unsigned char *)s;
	while (((size_t)uchar) % sizeof(uint64_t) && n)
	{
		*(uchar++) = 0;
		n--;
	}
	uint = (uint64_t *)uchar;
	while (n / sizeof(uint64_t))
	{
		*(uint++) = 0;
		n -= sizeof(uint64_t);
	}
	uchar = (unsigned char *)uint;
	while (n)
	{
		*(uchar++) = 0;
		n--;
	}
}

// void	ft_bzero(void *s, size_t n)
// {
// 	unsigned char	*str;
// 	size_t			i;

// 	i = 0;
// 	str = s;
// 	while (i < n)
// 	{
// 		str[i] = '\0';
// 		i++;
// 	}
// }

// void ft_bzero(void *s, size_t n)
// {
//     unsigned char	*str;
//     size_t	i;

// 	i = 0;
// 	str = s;
// 	while (i < n - 7)
// 	{
//         *(uint64_t*)(str + i) = 0;
// 		i += 8;
// 	}
// 	while (i < n)
// 	{
//         str[i] = 0;
// 		i++;
// 	}
// }
