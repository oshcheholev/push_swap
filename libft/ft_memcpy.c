/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshcheho <oshcheho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 09:47:15 by oshcheho          #+#    #+#             */
/*   Updated: 2024/04/18 13:41:37 by oshcheho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*copy;
	const char	*source;
	size_t		i;

	copy = (char *)dest;
	source = (const char *)src;
	if (!dest && !src)
	{
		return (NULL);
	}
	i = 0;
	while (i < n)
	{
		copy[i] = source[i];
		i++;
	}
	return (dest);
}
