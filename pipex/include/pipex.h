/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:21:34 by tjalo             #+#    #+#             */
/*   Updated: 2022/07/06 04:47:34 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

typedef struct s_pipex
{
	char	*path;
	char	**env;
	char	*cmd;
	char	**cmd_c;
	char	**cmd_p;
	char	**cmd_arg;
	char	**cmd_arg_c;
	char	**cmd_arg_p;
	int		pid;
	int		cmd_nb;
	int		index;
	int		pipe_nb;
	int		*pipe;
	int		infile;
	int		outfile;
	int		heredoc;
}	t_pipex;

char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_bzero(t_pipex *s, size_t n);
t_pipex	*ft_init(void);
void	free_pipex(t_pipex *pipex);
void	init_pipex(t_pipex *pipex, char **ag, char **env);
void	pipex(char **av, char **env, int ac);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
int		get_next_line(int fd, char **line);
void    get_infile(char **av, t_pipex *pipex);
void    get_outfile(char *av, t_pipex *pipex);
int     list_arg(char *arg, t_pipex *pipex);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
void    msg_error(char *err);
void    child_free(t_pipex *pipex);
void    parent_free(t_pipex *pipex);
void    pipe_free(t_pipex *pipex);
void    pipex_bonus(int ac, char **av, char **env);
void    child_bonus(t_pipex p, char **av, char **env);
void	find_path(char **envp, t_pipex *pipex);
void    close_pipe(t_pipex *pipex);
void	free_split(char **str);

#endif
