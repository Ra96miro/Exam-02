/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gramiro- <gramiro-@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 20:37:06 by gramiro-          #+#    #+#             */
/*   Updated: 2022/05/26 20:48:16 by gramiro-         ###   ########.fr       */
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

int second_check(char c, char *str)
{
	int x;

	x = 0;
	while (str[x] != '\0')
	{
		if (c == str[x])
			return (1);
		x++;
	}
	return (0);
}

void ft_inter(char *s1, char *s2)
{
	int x;

	x = -1;
	while (s1[++x] != '\0')
	{
		if (first_check(s1[x], s1, x) && second_check(s1[x], s2))
			write (1, &s1[x], 1);
	}
}

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		ft_inter(argv[1], argv[2]);
	}
	write(1, "\n", 1);
}