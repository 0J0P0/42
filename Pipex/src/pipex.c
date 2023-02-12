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

// Error function that prints the error message and exits the program with the
// corresponding error code.
void	ft_error(int err_code, int ex_code)
{
	if (err_code == ERR_ARG)
		ft_printf("Error: Wrong number of arguments.\n");
	else if (err_code == ERR_MC)
		ft_printf("Error: Memory allocation failed.\n");
	else if (err_code == ERR_CNF)
		ft_printf("Error: Command not found.\n");
	else if (err_code == ERR_PERM)
		ft_printf("Error: Permission denied.\n");
	else if (err_code == ERR_NFD)
		ft_printf("Error: No such file or directory.\n");
	else if (err_code == ERR_FD)
		ft_printf("Error: File descriptor error.\n");
	else if (err_code == ERR_PERR)
		perror("Error: ");
	exit(ex_code);
}

// Function that creates the struct and initializes it with the data from the arguments.
t_pipex	*init_pipex(char **argv)
{
	t_pipex	*data;

	data = (t_pipex *)malloc(sizeof(t_pipex));
	if (!data)
		return (NULL);
	data->infile = argv[1];
	data->outfile = argv[4];
	data->cmd1 = ft_strjoin("/usr/bin/", ft_split(argv[2], ' ')[0]);
	data->cmd2 = ft_strjoin("/usr/bin/", ft_split(argv[3], ' ')[0]);
	data->cmd1_arg = argv[2];
	data->cmd2_arg = argv[3];

	// pid variables
	data->pid1 = 0;
	data->pid2 = 0;
	// Open files
	data->in_fd = open(data->infile, O_RDONLY);
	if (data->in_fd == -1)
		ft_error(ERR_NFD, 1);
	data->out_fd = open(data->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->out_fd == -1)
		ft_error(ERR_NFD, 1);
	
	return (data);
}

// Function that executes the commands. It has to follow the following command structure:
// ./pipex < input_file command1 | command2 > output_file.
int	pipex(t_pipex *data, char **envp)
{
	int		fd[2];
	int		status;

	// Create the pipe
	if (pipe(fd) == -1)
		ft_error(ERR_FD, 1);
	// Fork the first child
	data->pid1 = fork();
	if (data->pid1 == -1)
		ft_error(ERR_PERR, 1);
	else if (data->pid1 == 0)
	{
		// Close the read end of the pipe
		close(fd[0]);
		// Redirect the output to the write end of the pipe
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			ft_error(ERR_FD, 1);
		// Close the write end of the pipe
		close(fd[1]);
		// Execute the first command
		if (execve(data->cmd1, ft_split(data->cmd1_arg, ' '), envp) == -1)
			ft_error(ERR_CNF, 1);
	}
	// Fork the second child
	data->pid2 = fork();
	if (data->pid2 == -1)
		ft_error(ERR_PERR, 1);
	else if (data->pid2 == 0)
	{
		// Close the write end of the pipe
		close(fd[1]);
		// Redirect the input to the read end of the pipe
		if (dup2(fd[0], STDIN_FILENO) == -1)
			ft_error(ERR_FD, 1);
		// Close the read end of the pipe
		close(fd[0]);
		// Execute the second command
		if (execve(data->cmd2, ft_split(data->cmd2_arg, ' '), envp) == -1)
			ft_error(ERR_CNF, 1);
	}
	// Close the read and write ends of the pipe
	close(fd[0]);
	close(fd[1]);
	// Wait for the first child to finish
	waitpid(data->pid1, &status, 0);
	// Wait for the second child to finish
	waitpid(data->pid2, &status, 0);
	return (1);
}

// Programm that simulates the pipe command in linux. It takes 4 arguments:
// 1. The input file
// 2. The first command
// 3. The output file
// 4. The second command
// Following the example of the subject, the command would be:
// ./pipex < input_file command1 | command2 > output_file
int	main(int argc, char **argv, char **envp)
{
	int		ERR;
	t_pipex	*data;

	if (argc != 5)
		ft_error(ERR_ARG, 1);
	// Create a struct to store the data
	data = init_pipex(argv);
	if (!data)
		ft_error(ERR_MC, 1);
	// Execute the commands
	ERR = pipex(data, envp);
	// Free the memory
	// ft_free(data);  ///////////////////////////////////////
	if (!ERR)
		ft_error(ERR, 1);
	return (0);
}