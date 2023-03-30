/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:03:13 by rdragan           #+#    #+#             */
/*   Updated: 2023/03/30 17:41:58 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
Checks the exit code of the child process.
If the child exited, returns it's exit value (>0).
If not returns -1.
*/
int	check_wait(int w)
{
	if (WIFEXITED(w))
		return (WEXITSTATUS(w));
	return (-1);
}

int	compare_strings(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (-1);
		i++;
	}
	return (0);
}

int	get_bin_index(char *env[])
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (compare_strings(ft_substr(env[i], 0, 4), "PATH") == 0)
			return (i);
		i++;
	}
	return (0);
}

char	*get_bin_path(char *env[], char *arg)
{
	char	**bin_paths;
	char	**cmd;
	char	*main_bin_path;
	int		i;

	bin_paths = ft_split(env[get_bin_index(env)], '=');
	bin_paths = ft_split(bin_paths[1], ':');
	if (!bin_paths)
		exit(1);
	cmd = ft_split(arg, ' ');
	if (!cmd)
		exit(1);
	i = -1;
	while (bin_paths[++i])
	{
		main_bin_path = ft_strjoin(bin_paths[i], "/");
		main_bin_path = ft_strjoin(main_bin_path, cmd[0]);
		if (access(main_bin_path, F_OK) == 0)
			break ;
	}
	if (access(main_bin_path, F_OK) == -1)
	{
		perror("bash");
		exit(1);
	}
	free(cmd);
	free(bin_paths);
	return (main_bin_path);
}

/*
Formats the command from the program to work accordingly
with the execve function.
@set_param bin_path: the binary path of the file.
@set_param index: specifies the index of the cmd in the argv list.
*/
char	**format_cmd(char *cmd, char *bin_path)
{
	char	**cmd_formatted;
	int		ls_q_mk;

	if (first_quotation_mark(cmd) >= 0)
	{
		cmd_formatted = malloc(3 * sizeof(char *));
		if (!cmd_formatted)
			return (NULL);
		cmd_formatted[0] = ft_substr(cmd, 0, first_word(cmd) + 1);
		ls_q_mk = first_quotation_mark(cmd);
		cmd_formatted[1] = ft_substr(cmd, ls_q_mk, l_q_mark(cmd) - ls_q_mk + 1);
		cmd_formatted[2] = NULL;
		return (cmd_formatted);
	}
	else
		cmd_formatted = ft_split(cmd, ' ');
	if (!cmd_formatted)
		return (NULL);
	cmd_formatted[0] = bin_path;
	if (!cmd_formatted)
		return (NULL);
	return (cmd_formatted);
}
