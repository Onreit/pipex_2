/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:28:23 by tjalo             #+#    #+#             */
/*   Updated: 2022/05/27 18:05:56 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

t_pipex	*ft_init(void)
{
	t_pipex	*pipex;

	pipex = (t_pipex *)malloc(sizeof(t_pipex));
	if (!pipex)
		return (NULL);
	ft_bzero(pipex, sizeof(t_pipex));
	return (pipex);
}

void	free_split(char **str)
{
	int	len;

	len = 0;
	while (str[len])
		free(str[len++]);
	free(str);
}

void	free_pipex(t_pipex *pipex)
{
	free(pipex->path);
	free_split(pipex->env);
	free_split(pipex->cmd_c);
	free_split(pipex->cmd_p);
	free_split(pipex->cmd_arg_c);
	free_split(pipex->cmd_arg_p);
	free(pipex);
}
