/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btaveira <btaveira@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:03:11 by btaveira          #+#    #+#             */
/*   Updated: 2023/11/23 19:00:23 by btaveira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int	bytes_read;
	static char	*line;
	
	line = ft_calloc(BUFFER_SIZE + 1,sizeof(char));
	if(!line)
		return (NULL);
	bytes_read = read(fd, line, BUFFER_SIZE);
	while(bytes_read != 0)
	{
		
	}
	line[bytes_read] = '\0';
	if(bytes_read <= 0)
		return (NULL);
	return (line);
}

int	main(void)
{
	int    fd;
	char  *next_line;
	int  count;

	count = 0;
	fd = open("example.txt", O_RDONLY);
	next_line = get_next_line(fd);
	count++;
	printf("[%d]:%s\n", count, next_line); //count is to show you the line numbers
 	next_line = NULL;

	close(fd);
	return (0);
}
