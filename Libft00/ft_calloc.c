/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:39:38 by noel              #+#    #+#             */
/*   Updated: 2023/10/11 18:14:21 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	sizeofal;

	sizeofal = count * size;
	ptr = (int *)malloc(sizeofal);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, sizeofal);
	return (ptr);
}