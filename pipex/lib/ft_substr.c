/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:35:48 by tjalo             #+#    #+#             */
/*   Updated: 2022/06/10 17:39:13 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*str;
	char	*tmp;

	str = malloc(sizeof(char) * len + 1);
	if (!str || !s)
		return (NULL);
	if (!len || start >= (unsigned int)ft_strlen(s))
	{
		*str = '\0';
		return (str);
	}
	tmp = str;
	while (len > 0 && s[start])
	{
		*str = s[start];
		start++;
		str++;
		len--;
	}
	*str = '\0';
	return (tmp);
}
