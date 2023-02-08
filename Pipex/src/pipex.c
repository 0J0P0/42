/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaldiva <jzaldiva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:50:24 by jzaldiva          #+#    #+#             */
/*   Updated: 2023/02/07 14:50:24 by jzaldiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

// Initialize the struct with the data from the arguments.
t_pipex	*init_pipex(char **argv)
{
	t_pipex	*data;

	data = malloc(sizeof(t_pipex));
	if (!data)
		return (NULL);
	data->infile = argv[1];
	data->cmd1 = argv[2];
	data->outfile = argv[4];
	data->cmd2 = argv[3];
	return (data);
}

// Function that executes the commands and redirects the output of the first
// command to the input of the second command.
int	pipex(t_pipex *data)
{
	int		fd[2];  // File descriptors for the pipe. fd[0] is the read end and fd[1] is the write end.
	pid_t	pid;  // Process ID.

	if (pipe(fd) == -1)  // Create a pipe
		return (1);
	pid = fork();  // Create a child process
	if (pid == -1)  // If the fork fails, return 1.
		return (1);
	if (pid == 0)  // If the process is the child, execute the first command.
	{
		close(fd[0]);
		dup2(fd[1], 1);
		close(fd[1]);
		execve(data->cmd1, ft_split(data->cmd1, ' '), NULL);
	}
	else  // If the process is the parent, execute the second command.
	{
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
		execve(data->cmd2, ft_split(data->cmd2, ' '), NULL);
	}
	return (0);
}

// Programm that simulates the pipe command in linux. It takes 4 arguments:
// 1. The input file
// 2. The first command
// 3. The output file
// 4. The second command
// Following the example of the subject, the command would be:
// ./pipex < input_file command1 | command2 > output_file
int	main(int argc, char **argv)
{
	t_pipex	*data;

	if (argc != 5)
		return (1);
	// Create a struct to store the data
	data = init_pipex(argv);
	if (!data)
		return (1);
	// Execute the commands
	if (pipex(data) == 1)
		return (1);
	free(data);
	return (0);
}
