/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:10:51 by albillie          #+#    #+#             */
/*   Updated: 2024/11/21 02:57:21 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

bool	check_extension(char *filename, char *extension)
{
	const char	*dot;

	if (!filename || !extension)
		return false;
	dot = strrchr(filename, '.');
	if (!dot)
		return false;
	return (strcmp(dot + 1, extension)) == 0;
}

void	map_checker(char *filename, int argc)
{
	int fd;

	if (argc < 2)
		ft_printf("Error\nPlease enter map name !\n"), exit(EXIT_FAILURE);
	else if (argc > 2)
		ft_printf("Error\nYou have too much arguments !\n"), exit(EXIT_FAILURE);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_printf("Error\nInvalid map name !\n"), exit(EXIT_FAILURE);
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
	(void) argc;
	//check_if_map(argv[1], argc);
	//ft_printf("%d", count_lines(argv[1]));
	printf("%d", check_extension(argv[1], "ber"));
}

