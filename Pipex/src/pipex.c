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


// Function that creates the struct and initializes it with the data from the arguments.
t_pipex	*init_pipex(char **argv)
{
	t_pipex	*data;

	data = (t_pipex *)malloc(sizeof(t_pipex));
	if (!data)
		return (NULL);
	data->infile = argv[1];
	data->outfile = argv[4];
	data->cmd1 = argv[2];
	data->cmd2 = argv[3];
	data->pid1 = 0;
	data->pid2 = 0;
	return (data);
}

// Function that executes the commands.
int	pipex(t_pipex *data)
{
	// Create the pipe
	if (pipe(data->fd) == -1)
		return (1);
	// Fork the first command
	data->pid1 = fork();
	if (data->pid1 == -1)
		return (1);
	if (data->pid1 == 0)
	{
		// Close the read end of the pipe
		close(data->fd[0]);
		// Redirect the standard output to the write end of the pipe
		dup2(data->fd[1], STDOUT_FILENO);
		// Close the write end of the pipe
		close(data->fd[1]);
		// Execute the first command
		if (execve(data->cmd1, ft_split(data->cmd1, ' '), NULL) == -1)
			return (1);		
	}
	// Fork the second command
	data->pid2 = fork();
	if (data->pid2 == -1)
		return (1);
	if (data->pid2 == 0)
	{
		// Close the write end of the pipe
		close(data->fd[1]);
		// Redirect the standard input to the read end of the pipe
		dup2(data->fd[0], STDIN_FILENO);
		// Close the read end of the pipe
		close(data->fd[0]);
		// Execute the second command
		if (execve(data->cmd2, ft_split(data->cmd2, ' '), NULL) == -1)
			return (1);
	}
	// Close the read and write ends of the pipe
	close(data->fd[0]);
	close(data->fd[1]);
	// Wait for the first command to finish
	waitpid(data->pid1, NULL, 0);
	// Wait for the second command to finish
	waitpid(data->pid2, NULL, 0);
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