/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 00:51:08 by tjalo             #+#    #+#             */
/*   Updated: 2022/07/06 05:19:51 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	**find_path_bonus(char **envp)
{
	char	**tmp;

	while (*envp)
	{
		if (ft_strncmp("PATH=", *envp, 5) == 0)
		{
			tmp = ft_split(*envp, ':');
			return (tmp);
		}
		envp++;
	}
	return (NULL);
}

void	create_pipe(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->cmd_nb - 1)
	{
		if (pipe(pipex->pipe + 2 * i) < 0)
			parent_free(pipex);
		i++;
	}
}

void	close_pipe(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->pipe_nb)
	{
		close(pipex->pipe[i]);
		i++;
	}
}

void	pipex_bonus(int ac, char **av, char **env)
{
	t_pipex	pipex;

	if (ac < list_arg(av[1], &pipex))
		exit(1);
	get_infile(av, &pipex);
	get_outfile(av[ac - 1], &pipex);
	pipex.cmd_nb = ac - 3 - pipex.heredoc;
	pipex.pipe_nb = 2 * (pipex.cmd_nb - 1);
	pipex.pipe = (int *)malloc(sizeof(int) * pipex.pipe_nb);
	if (!pipex.pipe)
		msg_error("ERR_PIPE");
	pipex.env = find_path_bonus(env);
	if (!pipex.env)
		pipe_free(&pipex);
	create_pipe(&pipex);
	pipex.index = -1;
	while (++(pipex.index) < pipex.cmd_nb)
		child_bonus(pipex, av, env);
	close_pipe(&pipex);
	waitpid(-1, NULL, 0);
	parent_free(&pipex);
}
