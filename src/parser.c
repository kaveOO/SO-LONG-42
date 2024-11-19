/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:10:51 by albillie          #+#    #+#             */
/*   Updated: 2024/11/19 07:50:33 by albillie         ###   ########.fr       */
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
bool	is_map_valid(char *filename)
{
	int fd;
	char *buffer = NULL;
	fd = open(filename, O_RDONLY);
	int i = 0;

	while (!ft_strchr(buffer, '\n'))
	{
		read(fd, buffer, 1);
		i++;
	}
	printf("%d", i);
	return true;
}



int main(int argc, char **argv)
{
	check_if_map(argv[1], argc);
	is_map_valid(argv[1]);
}
