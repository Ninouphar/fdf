/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 11:49:58 by rraffi-k          #+#    #+#             */
/*   Updated: 2023/05/09 13:37:00 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <bsd/string.h>
# include <math.h>
# include <stdint.h>

size_t	ft_strlen(const char *s);
int		ft_strnchr(const char *s);
char	*ft_strdup(const char *s);
void	ft_new_buffer(char *str);
char	*ft_strjoin_n(char *s1, char *s2);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s);
char	*ft_strdup_gnl(const char *s);
char	**ft_free(char	**str, size_t	l);
int		ft_atoi(const char *nptr);
float	ft_atof(const char *nptr);
void	ft_bzero(void *s, size_t n);

#endif
