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
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
#include <stdio.h>

# include "../lib/Libft/libft.h"
# include "../lib/Printf/inc/ft_printf.h"
/* ************************************************************************** */
/* ******************************** DEFINES ********************************* */
# define ERR_ARG	(int)1
# define ERR_MC		(int)2
# define ERR_CNF	(int)3
# define ERR_PERM	(int)4
# define ERR_NFD	(int)5
# define ERR_FD		(int)6
# define ERR_PERR	(int)7
/* ************************************************************************** */
/* ********************************* STRUCTS ******************************** */

// Structure for the pipex program. It contains the two commands, the two files,
// the file descriptors and the process IDs.
typedef struct s_pipex
{
	int		fd[2];
	int		in_fd;
	int		out_fd;
	char	*infile;
	char	*outfile;
	char	*cmd1;
	char	*cmd2;
	char	*cmd1_arg;
	char	*cmd2_arg;
	int		status1;
	int		status2;
	pid_t	pid1;
	pid_t	pid2;
}	t_pipex;
/* ************************************************************************** */
# endif