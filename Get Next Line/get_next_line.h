/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaldiva <jzaldiva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:14:55 by jzaldiva          #+#    #+#             */
/*   Updated: 2023/01/20 09:16:03 by jzaldiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

size_t	ft_strlen(char *s);

void	*ft_free(char **str);

char	*get_next_line(int fd);

char	*ft_strchr(char *s, int c);

char	*read_line(char *str_file);

char	*read_left(char	*str_file);

char	*read_file(int fd, char *str_file);

char	*ft_strjoin(char *str_file, char *buffer);

#endif
