/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerdogan <aerdogan@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 22:36:14 by aerdogan          #+#    #+#             */
/*   Updated: 2023/10/26 22:56:34 by aerdogan         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "library/printf/ft_printf.h"
#include "library/minilibx/mlx.h"
#include <stdlib.h>

void	error_message(char *msg)
{
	ft_printf("%s", msg);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_game	data;

	if (argc == 2)
	{
		map_control(argv[1], &data);
		map_reading(&data);
		map_processing(&data);
		wall_control(&data);
		data.mlxpointer = mlx_init();
		data.winpointer = mlx_new_window(data.mlxpointer,
				(data.map_width * UNIT), (data.map_height * UNIT), "so_long");
		images_in_game(&data);
		data.player = data.playerright;
		data.collectables = 0;
		map_bug(&data);
		adding_graphics(&data);
		placeholder(&data, data.player_y, data.player_x);
		mlx_hook(data.winpointer, 17, 0, (void *)exit, 0);
		data.counter = 0;
		mlx_hook(data.winpointer, 2, 0, &controls_working, &data);
		mlx_loop(data.mlxpointer);
	}
	else
		error_message("Error..!\nWrong Argument..!");
}
