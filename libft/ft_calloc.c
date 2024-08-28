/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshcheho <oshcheho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:20:42 by oshcheho          #+#    #+#             */
/*   Updated: 2024/04/18 13:38:36 by oshcheho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	full_size;
	size_t	i;
	void	*ptr;

	full_size = nmemb * size;
	ptr = malloc(full_size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < full_size)
	{
		((char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}
