/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerdogan <aerdogan@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 22:36:26 by aerdogan          #+#    #+#             */
/*   Updated: 2023/10/26 22:49:52 by aerdogan         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "so_long.h"
#include "library/printf/ft_printf.h"
#include "library/libft/libft.h"

void	ber_control(char *mapname)
{
	int	len;

	len = ft_strlen(mapname);
	if (mapname[len - 1] != 'r' || mapname[len - 2] != 'e'
		|| mapname[len - 3] != 'b' || mapname[len - 4] != '.')
		error_message("False .ber extension..!!");
}

void	txt_control(char *mapname)
{
	int	fd;

	fd = open(mapname, O_RDONLY);
	if (fd < 0)
		error_message("Map not found!");
	close(fd);
}

void	map_control(char *mapname, t_game *data)
{
	ber_control(mapname);
	data->maplocation = ft_strjoin("map/", mapname);
	txt_control(data->maplocation);
}
