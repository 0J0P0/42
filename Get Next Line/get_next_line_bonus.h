/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaldiva <jzaldiva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:44:53 by jzaldiva          #+#    #+#             */
/*   Updated: 2023/01/20 09:50:21 by jzaldiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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
