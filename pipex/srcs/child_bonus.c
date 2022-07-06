/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 01:46:40 by tjalo             #+#    #+#             */
/*   Updated: 2022/07/06 05:21:23 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*find_cmd_bonus(char **path, char *cmd)
{
	char	*tmp;
	char	*command;

	while (*path)
	{
		tmp = ft_strjoin(*path, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		path++;
	}
	return (NULL);
}

void	sub_dup(int zero, int first)
{
	dup2(zero, 0);
	dup2(first, 1);
}

void	child_bonus(t_pipex p, char **av, char **env)
{
	p.pid = fork();
	if (!p.pid)
	{
		if (p.index == 0)
			sub_dup(p.infile, p.pipe[1]);
		else if (p.index == p.cmd_nb - 1)
			sub_dup(p.pipe[2 * p.index - 2], p.outfile);
		else
			sub_dup(p.pipe[2 * p.index - 2], p.pipe[2 * p.index + 1]);
		close_pipe(&p);
		p.cmd_arg = ft_split(av[2 + p.heredoc + p.index], ' ');
		p.cmd = find_cmd_bonus(p.env, p.cmd_arg[0]);
		if (!p.cmd)
		{
			child_free(&p);
			exit(1);
		}
		execve(p.cmd, p.cmd_arg, env);
	}
}
