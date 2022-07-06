/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:11:06 by tjalo             #+#    #+#             */
/*   Updated: 2022/07/06 05:21:37 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	find_cmd(char **arg, t_pipex *pipex)
{
	if (!pipex->heredoc)
	{
		pipex->cmd_c = ft_split(arg[2], ' ');
		pipex->cmd_p = ft_split(arg[3], ' ');
		pipex->cmd_arg_c = ft_split(arg[2], ' ');
		pipex->cmd_arg_p = ft_split(arg[3], ' ');
	}
	else
	{
		pipex->cmd_c = ft_split(arg[3], ' ');
		pipex->cmd_p = ft_split(arg[4], ' ');
		pipex->cmd_arg_c = ft_split(arg[3], ' ');
		pipex->cmd_arg_p = ft_split(arg[4], ' ');
	}
	pipex->cmd_c[0] = ft_strjoin("/", pipex->cmd_c[0]);
	pipex->cmd_p[0] = ft_strjoin("/", pipex->cmd_p[0]);
}

void	find_path(char **envp, t_pipex *pipex)
{
	while (*envp)
	{
		if (ft_strncmp("PATH=", *envp, 5) == 0)
		{
			pipex->env = ft_split(*envp, ':');
			break ;
		}
		envp++;
	}
}

void	find_env_c(t_pipex *pipex)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (pipex->env[i])
	{
		tmp = ft_strjoin(pipex->env[i], pipex->cmd_c[0]);
		if (access(tmp, 0) == 0)
		{
			pipex->cmd_c[0] = ft_strdup(tmp);
			free(tmp);
			tmp = NULL;
			break ;
		}
		i++;
		free(tmp);
		tmp = NULL;
	}
}

void	find_env_p(t_pipex *pipex)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (pipex->env[i])
	{
		tmp = ft_strjoin(pipex->env[i], pipex->cmd_p[0]);
		if (access(tmp, 0) == 0)
		{
			pipex->cmd_p[0] = ft_strdup(tmp);
			free(tmp);
			break ;
		}
		i++;
		free(tmp);
	}
}

void	init_pipex(t_pipex *pipex, char **ag, char **env)
{
	list_arg(ag[1], pipex);
	find_cmd(ag, pipex);
	find_path(env, pipex);
	find_env_c(pipex);
	find_env_p(pipex);
}
