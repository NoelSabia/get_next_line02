/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:21:40 by nsabia            #+#    #+#             */
/*   Updated: 2023/10/05 12:25:48 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include<stdio.h>

char *ft_strchr(const char *s, int c)
{
    int i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			return (char *)(s + i);
		}
		i++;
	}
    return NULL;	
}

#include <stdio.h>
int main()
{
    const char *a = "Hello there";
    int c = 'o';
	printf("%s", ft_strchr(a, c));
}