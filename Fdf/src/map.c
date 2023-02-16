/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaldiva <jzaldiva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:37:41 by jzaldiva          #+#    #+#             */
/*   Updated: 2023/02/16 14:52:47 by jzaldiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

// Function to free the map.
t_map	ft_free_map(t_map map)
{
	int	i;

	i = 0;
	while (i < map.height)
	{
		free(map.points[i]);
		i++;
	}
	free(map.points);
	return (map);
}
