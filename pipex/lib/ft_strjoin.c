/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:32:51 by tjalo             #+#    #+#             */
/*   Updated: 2022/05/27 18:00:53 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	*ft_strcat(char *s1, const char *s2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (*(s1 + i) != '\0')
		i++;
	while (*(s2 + j) != '\0')
	{
		*(s1 + i) = *(s2 + j);
		i++;
		j++;
	}
	*(s1 + i) = '\0';
	return (s1);
}

static char	*ft_strcpy(char *dst, const char *src)
{
	char	*pdst;

	pdst = dst;
	while (*src)
		*pdst++ = *src++;
	*pdst = '\0';
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*joined;
	size_t		len;

	if (!s1 || !s2)
		return (NULL);
	len = (ft_strlen(s1) + ft_strlen(s2)) + 1;
	if (!s1 && !s2)
		return (NULL);
	joined = (char *)malloc(sizeof(char) * len);
	if (joined == NULL)
		return (NULL);
	joined = ft_strcpy(joined, s1);
	return (ft_strcat(joined, s2));
}
