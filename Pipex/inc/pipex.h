/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaldiva <jzaldiva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:49:03 by jzaldiva          #+#    #+#             */
/*   Updated: 2023/02/07 14:49:03 by jzaldiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PIPEX_H
# define PIPEX_H

/* ******************************* INCLUDES ********************************* */
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>

# include "../lib/Libft/libft.h"
# include "../lib/Printf/inc/ft_printf.h"
/* ************************************************************************** */
/* ********************************* STRUCTS ******************************** */
// Structure for the pipex program. It contains the two commands, the two files, the file descriptors
// and the process IDs.
typedef struct s_pipex
{
	char	*infile;
	char	*outfile;
	char	*cmd1;
	char	*cmd2;
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;
}	t_pipex;

// // Structure for the process ID. It contains the PID of the first command and the second command.
// typedef struct s_pid
// {
// 	pid_t	pid1;
// 	pid_t	pid2;
// }	t_pid;
/* ************************************************************************** */
# endif