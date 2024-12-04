/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:44:48 by albillie          #+#    #+#             */
/*   Updated: 2024/12/04 23:06:50 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	args_checker(t_global *game, int argc, char *filename)
{
	if (argc < 2)
	{
		free_exit(game, "Please enter map name !", 1);
	}
	else if (argc > 2)
	{
		free_exit(game, "You have too much arguments !", 1);
	}
	if (!check_if_opened(filename))
	{
		free_exit(game, "Invalid map name !", 1);
	}
	if (!check_extension(filename, "ber"))
	{
		free_exit(game, "Map file extension is invalid !", 1);
	}
	game->map.filename = filename;
}
