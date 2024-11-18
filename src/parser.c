/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:10:51 by albillie          #+#    #+#             */
/*   Updated: 2024/11/18 06:35:56 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_if_map(char *filename, int argc)
{
	int fd;

	if (argc < 2)
	{
		printf("Error\nPlease enter map name !\n"), exit(EXIT_FAILURE);
	}
	else if (argc > 2)
	{
		printf("Error\nYou have too much arguments !\n"), exit(EXIT_FAILURE);
	}
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\nInvalid map name !\n");
		exit(EXIT_FAILURE);
	}
	printf("Map (%s) opened!\n", filename);
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

int main(int argc, char **argv)
{
	(void) argc;

	count_lines(argv[1]);

}
