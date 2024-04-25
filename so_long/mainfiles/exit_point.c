/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerdogan <aerdogan@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 22:35:57 by aerdogan          #+#    #+#             */
/*   Updated: 2023/10/26 22:56:17 by aerdogan         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "library/minilibx/mlx.h"
#include <stdlib.h>

void	mlx_images_free(t_game *data)
{
	if (data->playerup)
		mlx_destroy_image(data->mlxpointer, data->playerup);
	if (data->playerdown)
		mlx_destroy_image(data->mlxpointer, data->playerdown);
	if (data->playerleft)
		mlx_destroy_image(data->mlxpointer, data->playerleft);
	if (data->playerright)
		mlx_destroy_image(data->mlxpointer, data->playerright);
	if (data->collectable)
		mlx_destroy_image(data->mlxpointer, data->collectable);
	if (data->exit)
		mlx_destroy_image(data->mlxpointer, data->exit);
	if (data->wall)
		mlx_destroy_image(data->mlxpointer, data->wall);
	data->player = NULL;
}

int	exit_point(t_game *data)
{
	int	line;

	line = 0;
	if (data->winpointer)
		mlx_destroy_window(data->mlxpointer, data->winpointer);
	while (line < data->map_height)
		free(data->map[line++]);
	free(data->map);
	free(data->maplocation);
	mlx_images_free(data);
	exit(0);
}
