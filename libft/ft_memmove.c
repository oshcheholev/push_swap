/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshcheho <oshcheho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:02:03 by oshcheho          #+#    #+#             */
/*   Updated: 2024/04/18 13:41:42 by oshcheho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*copy;
	const char	*source;
	size_t		i;

	if (!dest && !src)
		return (NULL);
	copy = (char *)dest;
	source = (const char *)src;
	if (copy + n <= source + n)
	{
		i = 0;
		while (i < n)
		{
			copy[i] = source[i];
			i++;
		}
		return (dest);
	}
	i = n;
	while (i > 0)
	{
		copy[i - 1] = source[i - 1];
		i--;
	}
	return (dest);
}
