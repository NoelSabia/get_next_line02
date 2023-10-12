/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noel <noel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:41:10 by nsabia            #+#    #+#             */
/*   Updated: 2023/10/12 09:36:55 by noel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putstr_fd(char *s, int fd)
{
	int i;

	i = 0;
	while (s[i] != 0)
	{
		write (fd, &s[i], sizeof(char));
		i++;
	}
}