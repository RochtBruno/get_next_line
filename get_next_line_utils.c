/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btaveira <btaveira@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:04:20 by btaveira          #+#    #+#             */
/*   Updated: 2023/11/23 15:36:44 by btaveira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	index_s1;
	size_t	index_s2;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = malloc(sizeof (char) * (len_s1 + len_s2) + 1);
	if (!str)
		return (NULL);
	index_s1 = 0;
	index_s2 = 0;
	while (s1[index_s1])
	{
		str[index_s1] = s1[index_s1];
		index_s1++;
	}
	while (s2[index_s2])
	{
		str[index_s1 + index_s2] = s2[index_s2];
		index_s2++;
	}
	str[index_s1 + index_s2] = '\0';
	return (str);
}*/

void	*ft_calloc(size_t nmemb, size_t size)
{
	char			*arr;
	unsigned int	i;
	unsigned int	total;

	total = nmemb * size;
	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	arr = malloc(total);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < (nmemb * size))
	{
		arr[i] = 0;
		i++;
	}
	return ((void *)arr);
}

/*size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}*/
