/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gramiro- <gramiro-@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 20:49:41 by gramiro-          #+#    #+#             */
/*   Updated: 2022/05/26 20:56:55 by gramiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int first_check(char c, char *str, int x)
{
	while (--x >= 0)
	{
		if (c == str[x])
			return (0);
	}
	return (1);
}

void ft_union(char *s1, char *s2)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (s1[++x] != '\0')
	{
		if (first_check(s1[x], s1, x))
			write (1, &s1[x], 1);
	}
	while (s2[++y] != '\0')
	{
		if (first_check(s2[y], s2, y) && first_check(s2[y], s1, x))
			write(1, &s2[y], 1);
	}
}

int main (int argc, char **argv)
{
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	write (1, "\n", 1);
}