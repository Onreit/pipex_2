/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:03:50 by tjalo             #+#    #+#             */
/*   Updated: 2022/05/27 18:01:44 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*ft_strdup(const char *s1)
{
	char		*copy_s;
	size_t		i;
	size_t		len;

	len = ft_strlen(s1);
	copy_s = (char *)malloc(sizeof(char) * (len + 1));
	if (!copy_s)
		return (NULL);
	i = -1;
	while (++i < len)
		*(copy_s + i) = *(s1 + i);
	*(copy_s + i) = '\0';
	return (copy_s);
}
