/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:10:51 by albillie          #+#    #+#             */
/*   Updated: 2024/11/06 13:16:38 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/home/albillie/Desktop/SO-LONG-42/includes/so_long.h"

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

t_map *read_map(int fd)
{
	t_map	*map;
	char	current;
	int		bytes_read;

	map = malloc(sizeof(t_map));
	while ((bytes_read = read(fd, &current, 1)) > 0 && current != '\n')
		map->width++;
	while ((bytes_read = read(fd, &current, 1)) > 0)
	{
		if (current == '\n')
			map->height++;
	}


	printf("%d\n", bytes_read);
	printf("\nHauteur de la map : %d\n", map->height);
	printf("Largeur de la map : %d\n", map->width);
	return (map);
}

int main(int argc, char **argv)
{
	int fd;

	fd = open("map.ber", O_RDONLY);

	check_if_map(argv[1], argc);
	read_map(fd);
}
