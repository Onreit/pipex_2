/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 17:45:15 by tjalo             #+#    #+#             */
/*   Updated: 2022/06/15 13:51:40 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/*int main(int argc, char **argv, char **env)
{
	pid_t pid;

	char s[100];

	// printf("%s\n", getcwd(s, 100));
	// printf("%s\n", getcwd(s, 100));
	//execve("/bin/ls", argv, env);
	char *arg[2];

	arg[0] = "-la";
	arg[1] = NULL;
	if ((pid = fork()) == 0) 
	{
		chdir("..");
		execve("/bin/ls", arg, env);
		exit(0);
	}
	// printf("%s\n", getcwd(s, 100));
	execve("/bin/ls", argv, env);
	// printf("%s\n", getcwd(s, 100));
	exit(0);
}*/

/*int	main(int ac, char **av, char **env)
{
	int	f1;
	int	f2;

	if (ac > 5)
		return (0);
	f1 = open(av[1], O_RDONLY);
	f2 = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (f1 < 0 || f2 < 0)
		return (-1);
	pipex(f1, f2, av, env);
	return (0);
}
*/

int	main(int ac, char **av, char **env)
{
	if (ac > 6 || ac < 5)
		return (0);
	pipex(av, env, ac);
	return (0);
}
