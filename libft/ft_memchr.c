/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshcheho <oshcheho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:39:15 by oshcheho          #+#    #+#             */
/*   Updated: 2024/04/18 13:41:26 by oshcheho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*point;
	size_t				i;

	point = s;
	i = 0;
	while (i < n)
	{
		if (point[i] == (unsigned char)c)
		{
			return ((void *)(point + i));
		}
		i++;
	}
	return (NULL);
}
