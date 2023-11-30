/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btaveira <btaveira@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:04:20 by btaveira          #+#    #+#             */
/*   Updated: 2023/11/29 19:37:23 by btaveira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1,char *s2)
{
	char	*str;
	size_t	index;

	if (!s1 && !s2)
		return (NULL);
	str = malloc(sizeof (char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!str)
		return (NULL);
	index = 0;
	while (s1 && *s1)
		str[index++] = *s1++;
	while (s2 && *s2)
		str[index++] = *s2++;
	str[index] = '\0';
	return (str);
}

size_t	ft_strlen(char *str)
{
	size_t	i;
	
	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	char	x;
	size_t	i;

	i = 0;
	x = (char) c;
	while (s[i] != '\0')
	{
		if (s[i] == x)
			return ((char *) s + i);
		i++;
	}
	if (s[i] == x)
		return ((char *) s + i);
	return (NULL);
}

char	*ft_strdup(char *s)
{
	int		i;
	char	*dest;

	if (s == NULL)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
