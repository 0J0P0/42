/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaldiva <jzaldiva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:14:55 by jzaldiva          #+#    #+#             */
/*   Updated: 2023/01/20 09:37:24 by jzaldiva         ###   ########.fr       */
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

char	*ft_strchr(char *s, int c);

char	*ft_strjoin(char *line, char *buffer);

char	*get_next_line(int fd);

char	*update_line(char *line);

char	*clean_line(char	*line);

char	*read_line(int fd, char *line);

#endif
