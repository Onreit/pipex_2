/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:35:45 by tjalo             #+#    #+#             */
/*   Updated: 2022/05/27 16:12:34 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static int	check(char c, char charset)
{
	if (c == charset)
		return (-1);
	return (1);
}

static int	words(char const *str, char charset)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (check(str[i], charset) == -1)
		i++;
	while (str[i])
	{
		j++;
		while (check(str[i], charset) == -1)
			i++;
		while (str[i] && check(str[i], charset) != -1)
			i++;
	}
	return (j);
}

static char	*ft_strcp(char *s1, char const *s2, char charset)
{
	int	i;

	i = 0;
	while (s2[i] && check(s2[i], charset) != -1)
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

static char	**sp(char **strs, const char *str, int *i, char c)
{
	while (str[i[2]])
	{
		i[1] = 0;
		while (check(str[i[2]], c) == -1)
			i[2]++;
		while (str[i[2]] && check(str[i[2]], c) != -1)
		{
			i[1]++;
			i[2]++;
		}
		if (i[1] != 0)
		{
			strs[i[0]] = malloc(sizeof(char) * (i[1] + 1));
			if (!strs[i[0]])
			{
				while (--i[0] > 0)
					free(strs[i[0]]);
				free(strs);
				return (NULL);
			}
			ft_strcp(strs[i[0]++], &str[i[2] - i[1]], c);
		}
	}
	strs[i[0]] = 0;
	return (strs);
}

char	**ft_split(char const *str, char c)
{
	char	**strs;
	int		i[3];

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	if (!str)
		return (NULL);
	strs = malloc(sizeof(*strs) * (words(str, c) + 1));
	if (!strs)
		return (NULL);
	return (sp(strs, str, i, c));
}
