/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btaveira <btaveira@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:03:11 by btaveira          #+#    #+#             */
/*   Updated: 2023/11/29 19:19:08 by btaveira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *str, char *newstr)
{
	char	*temp;

	temp = ft_strjoin(str, newstr);
	free(str);
	return (temp);
}

char	*ft_cut_line(char *str)
{
	size_t	len;
	char	*line;

	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	if (str[len] == '\n')
		len++;
	line = (char *)malloc(sizeof(char) * len + 1);
	if (!line)
		return (NULL);
	line[len] = '\0';
	while (len--)
		line[len] = str[len];
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*ft_delete_line(char *str)
{
	int	len;
	char	*line_to_delete;

	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	if (str[len] == '\n')
		len++;
	if (str[len] == '\0')
	{
		free(str);
		return (NULL);
	}
	line_to_delete = ft_strdup(str + len);
	free(str);
	return (line_to_delete);
}

char	*ft_reader(int fd)
{
	int		bytes_read;
	static char	*str;
	char		*line;
	char		*newstr;

	bytes_read = 1;
	newstr = (char *)malloc((BUFFER_SIZE + 1 ) * sizeof(char));
	if (!newstr)
		return (NULL);
	while (bytes_read > 0 && (!str || !ft_strchr(str,'\n')))
	{
		bytes_read = read(fd, newstr, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(newstr);
			return (NULL);
		}
		newstr[bytes_read] = '\0';
		str = ft_free(str, newstr);
	}
	free(newstr);
	line = ft_cut_line(str);
	str = ft_delete_line(str);
	return (line);
}

char	*get_next_line(int fd)
{
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	return (ft_reader(fd));
}
