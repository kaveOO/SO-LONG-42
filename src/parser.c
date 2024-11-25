/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:10:51 by albillie          #+#    #+#             */
/*   Updated: 2024/11/25 10:17:58 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	args_checker(char *filename, int argc)
{
	if (argc < 2)
	{
		ft_printf("Error\nPlease enter map name !\n");
		exit(1);
	}
	else if (argc > 2)
	{
		ft_printf("Error\nYou have too much arguments !\n");
		exit(1);
	}
	if (!check_if_opened(filename))
	{
		ft_printf("Error\nInvalid map name !\n"), exit(1);
	}
	if (!check_extension(filename, "ber"))
	{
		ft_printf("Error\nMap file extension is invalid !\n");
		exit(1);
	}
	ft_printf("Map (%s) opened!\n", filename);
}

void	check_map_size(int fd, t_global *map)
{
	char	*line;
	size_t	ref_len;
	int		i;

	line = get_next_line(fd);
	if (!line)
	{
		printf("Error\nMap is empty !\n"), exit(1);
	}
	ref_len = ft_strlen(line);
	free(line);
	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		if (ft_strlen(line) != ref_len)
		{
			ft_printf("Error\nInvalid length of lines !\n"), free(line);
			exit(1);
		}
		i++, free(line);
	}
	map->map->height = i + 1;
	map->map->width = ref_len;
	if (map->map->height == map->map->width)
		ft_printf("Error\nYour map is not Rectangle !\n"), exit(1);
}
void	allocate_map(int fd, t_global *map)
{
	int		map_size;
	(void) fd;

	map_size = map->map->height * map->map->width;
	map->map->grid = malloc(map_size);
	if (!map)
		ft_printf("Error\nFailed map allocation !\n"), exit(1)
}

/* void	is_map_square(t_global *map)
{
	if (map->map->height == map->map->width)
	{
		printf("Error\nMap is a Square !\n"), exit(1);
	}
} */
/* void	get_map_size(t_global *game)
{
	char	**map;
	int		map_size;
	int		i;

	map_size = game->map->height * game->map->width;
	map = malloc(map_size);
	if (!map)
		printf("Error\nFailed map allocation !\n"), exit(1);
	game->map->grid = map;
	printf("%d\n", map_size);
	i = 0;
	while (map[i])
	{
		printf("%s", map[i]);
	}
} */

/* void	test_map(char **map)
{
	if (!map)
		printf("Error\n");
	printf("Printing map !\n");
	printf("%s", map[0]);
} */

/* void	allocate_map(int fd)
{
	char	*line;
	int		i;
	char	*map;

	line = get_next_line(fd);
	if (!line)
		printf("Error\n"), exit(1);
	printf("%s", line);
	i = 0;
	while (line[i])
	{
		map = malloc(line[i]);
		i++;
	}
	printf("\n%c", map[0]);
} */



/* void	verify_map(int fd)
{
	char	*line;
	int		i;

	while (line)
	{
		while (line[i] != '\n')
		{


		}






	}

} */

/* void	allocate_entire_map(int fd)
{
	int		lines_count;
	char	*lines;
	char 	*line;
	char	*buffer = NULL;

	lines_count = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%zu\n", ft_strlen(line));
		lines_count++;
	}
	printf("%d\n", lines_count);
	lines = malloc(sizeof(char *) * lines_count);
	if (!lines)
		printf("Error\nAllocation error !\n"), exit(1);
	int i = 0;
	while (read(fd, buffer, 1))
	{
		lines = malloc(sizeof(char *) * 1);
		printf("%c", lines[i]);
		i++;
		if (lines[i] == '\n')
		{
			printf("NUll car");
		}
	}
} */

/* int	count_lines(char *filename, t_global *s_global)
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
} */
/* bool	is_map_valid(char *filename)
{
	open(filename, O_RDONLY);
} */



int main(int argc, char **argv)
{
	t_global game;
	t_map map;
	game.map = &map;
	int fd = open(argv[1], O_RDONLY);

	args_checker(argv[1], argc);
	check_map_size(fd, &game);
	allocate_map(fd, &game);
	printf("\n%d\n", game.map->height);
	printf("%d\n", game.map->width);
	//is_map_square(fd, &game);
	//get_map_size(&game);
	//test_map(game.map->grid);
	//lines_length(fd);
	close(fd);

}
