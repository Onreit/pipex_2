/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 03:05:40 by tjalo             #+#    #+#             */
/*   Updated: 2022/07/06 05:22:05 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	msg_error(char *err)
{
	perror(err);
	exit(1);
}

void	child_free(t_pipex *pipex)
{
	free_split(pipex->cmd_arg);
	free(pipex->cmd);
}

void	parent_free(t_pipex *pipex)
{
	close(pipex->infile);
	close(pipex->outfile);
	if (pipex->heredoc)
		unlink(".heredoc");
	free_split(pipex->env);
	free(pipex->pipe);
}

void	pipe_free(t_pipex *pipex)
{
	close(pipex->infile);
	close(pipex->outfile);
	if (pipex->heredoc)
		unlink(".heredoc");
	free(pipex->pipe);
	exit(1);
}
