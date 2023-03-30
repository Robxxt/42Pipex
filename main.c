/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 14:32:43 by rdragan           #+#    #+#             */
/*   Updated: 2023/03/30 17:57:58 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
Processes the first task.
*/
void	child_process(char *argv[], char *env[], int fd[])
{
	char	**cmd;
	int		file;

	dup2(fd[1], STDOUT_FILENO);
	file = open(argv[1], O_RDONLY);
	close(fd[1]);
	close(fd[0]);
	if (file == -1)
	{
		perror("bash");
		exit(1);
	}
	dup2(file, STDIN_FILENO);
	close(file);
	cmd = format_cmd(argv[2], get_bin_path(env, argv[2]));
	close(file);
	if (execve(*cmd, cmd, env) == -1)
		exit(1);
}

void	second_child_process(char *argv[], char *env[], int fd[])
{
	char	**cmd;
	int		file;

	file = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (file == -1)
	{
		perror("bash");
		exit(1);
	}
	dup2(fd[0], STDIN_FILENO);
	dup2(file, STDOUT_FILENO);
	close(fd[0]);
	close(file);
	cmd = format_cmd(argv[3], get_bin_path(env, argv[3]));
	if (execve(*cmd, cmd, env) == -1)
		exit(1);
}

int	main(int argc, char *argv[], char *env[])
{
	int		fd[2];
	int		wstatus;
	int		pid;

	if (argc != 5)
		return (0);
	if (pipe(fd) == -1)
		return (1);
	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
		child_process(argv, env, fd);
	close(fd[1]);
	pid = fork();
	if (pid == 0)
		second_child_process(argv, env, fd);
	waitpid(pid, &wstatus, 0);
	close(fd[0]);
	return (WEXITSTATUS(wstatus));
}
