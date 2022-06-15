/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:59:14 by tjalo             #+#    #+#             */
/*   Updated: 2022/06/15 14:12:34 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int     list_arg(char *arg, t_pipex *pipex)
{
    if (arg && !ft_strncmp(arg, "here_doc", 9))
    {
        pipex->heredoc = 1;
        return (6);
    }
    else
    {
        pipex->heredoc = 0;
        return (5);
    }
}

void    here_doc(char *av, t_pipex *pipex)
{
    int     file;
    char    *buf;

    file = open(".here_doc", O_CREAT | O_WRONLY | O_TRUNC);
    if (file < 0)
        return ;
    while (1)
    {
        write(1, "heredoc> ", 9);
        if (get_next_line(0, &buf) == 0)
            exit(1);
        if (!ft_strncmp(av, buf, ft_strlen(av)))
            break;
        write(file, buf, ft_strlen(buf));
        write(file, "\n", 1);
        free(buf);
    }
    free(buf);
    close(file);
    pipex->infile = open(".here_doc", O_RDONLY);
    if (pipex->infile < 0)
    {
        unlink(".here_doc");
        return ;
    }
}

void    get_infile(char **av, t_pipex *pipex)
{
    if (!ft_strncmp(av[1], "here_doc", 9))
        here_doc(av[2], pipex);
    else
        pipex->infile = open(av[1], O_RDONLY);
    if (pipex->infile < 0)
        return ;
}

void    get_outfile(char *av, t_pipex *pipex)
{
    if (pipex->heredoc)
        pipex->outfile = open(av, O_WRONLY | O_CREAT | O_APPEND);
    else
        pipex->outfile = open(av, O_CREAT | O_RDWR | O_TRUNC);
    if (pipex->outfile < 0)
        return ;
}
