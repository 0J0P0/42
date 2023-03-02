// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   ft_point.c                                         :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: jzaldiva <jzaldiva@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/02/16 20:06:16 by jzaldiva          #+#    #+#             */
// /*   Updated: 2023/02/16 20:06:16 by jzaldiva         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// # include "../inc/fdf.h"

// // Function to set an isometric projection.
// void	ft_iso(t_mlx *mlx, t_point *start, t_point *end)
// {
// 	int	x;
// 	int	y;

// 	// Set an isometric projection.
// 	x = start->x;
// 	y = start->y;
// 	start->x = (x - y) * cos(mlx->angle);
// 	start->y = (x + y) * sin(mlx->angle) - start->z;
// 	x = end->x;
// 	y = end->y;
// 	end->x = (x - y) * cos(mlx->angle);
// 	end->y = (x + y) * sin(mlx->angle) - end->z;
// }