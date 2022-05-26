/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gramiro- <gramiro-@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 21:23:12 by gramiro-          #+#    #+#             */
/*   Updated: 2022/05/26 21:47:34 by gramiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char line[999999];
	char buff[1];
	char *lett;
	int	x;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line[0] = '\0';
	while(read(fd, buff, 1) == 1)
	{
		line[x] = buff[0];
		line[x + 1] = '\0';
		if ( line[x] == '\n')
			break;
		x++;
	}
	if (line[0] == '\0')
		return (NULL);
	lett = malloc(x + 1);
	if (!lett)
		return (NULL);
	x = 0;
	while (line[x] == '\0')
	{
		lett[x] = line[x];
		x++;
	}
	lett[x] = '\0';
	return (lett);
}

int main(int ac, char **av){
	//Thx to mprigent for the main
	int		fd;
	char	*line;
	(void)ac;

	fd = open(av[1], O_RDONLY);
    while ((line = get_next_line(fd)) != 0)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	// system("leaks a.out");
	return (0);
}