/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:10:51 by albillie          #+#    #+#             */
/*   Updated: 2024/11/23 11:53:25 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	args_checker(char *filename, int argc)
{
	if (argc < 2)
	{
		ft_printf("Error\nPlease enter map name !\n");
		exit(EXIT_FAILURE);
	}
	else if (argc > 2)
	{
		ft_printf("Error\nYou have too much arguments !\n");
		exit(EXIT_FAILURE);
	}
	if (!check_if_opened(filename))
	{
		ft_printf("Error\nInvalid map name !\n"), exit(EXIT_FAILURE);
	}
	if (!check_extension(filename, "ber"))
	{
		ft_printf("Error\nMap file extension is invalid !\n");
		exit(EXIT_FAILURE);
	}
	ft_printf("Map (%s) opened!\n", filename);
}

int	count_lines(char *filename)
{
	int		fd;
	int		lines;
	char	*line;

	lines = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	while ((line = get_next_line(fd)) != NULL)
	{
		lines++;
		free(line);
	}
	close(fd);
	return(lines);
}
/* bool	is_map_valid(char *filename)
{
	open(filename, O_RDONLY);
} */



int main(int argc, char **argv)
{
	args_checker(argv[1], argc);
}

