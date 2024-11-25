/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:10:51 by albillie          #+#    #+#             */
/*   Updated: 2024/11/25 18:28:13 by albillie         ###   ########.fr       */
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

char	**new_allocate_try(int fd)
{
	int i  = 0;
	char	**array;

	while (get_next_line(fd))
	{
		i++;
	}
	array = malloc(sizeof(char *) * i + 1);
	return (array);
}

void	allocate_try_1(int fd)
{
	char *line = get_next_line(fd);
	printf("%s", line);
}





void	allocate_and_fill_map(int fd, t_global *map, int count)
{
	char	**line;
	int		i = 0;

	(void)map;
	line = malloc((count + 1) * sizeof(char *));
	line[i] = get_next_line(fd);
	printf("%s", line[i]);
	i++;
	while (i < (count))
	{
		line[i] = get_next_line(fd);
		printf("%s", line[i]);
		i++;
	}
	line[i] = NULL;
	printf("i = %d\n", i);
}

int	check_map_size(int fd, t_global *map)
{
	char	*line;
	size_t	ref_len;
	int		i;
	int count = 0;

	line = get_next_line(fd);
	count++;
	if (!line)
	{
		printf("Error\nMap is empty !\n"), exit(1);
	}
	ref_len = ft_strlen(line);
	free(line);
	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		count++;
		if (ft_strlen(line) != ref_len)
		{
			ft_printf("Error\nInvalid length of lines !\n"), free(line);
			exit(1);
		}
		i++, free(line);
	}
	map->map->height = i + 1;
	map->map->width = ref_len - 1;
	if (map->map->height == map->map->width)
		ft_printf("Error\nYour map is not Rectangle !\n"), exit(1);
	return (count);
}

void	allocate_map(int fd, t_global *map)
{
	int	map_size;
	int	height;
	int width;
	int	i;
	(void) fd;

	height = map->map->height;
	width = map->map->width;
	map_size = height * width;

	map->map->grid = malloc(height + 1);
	if (!map->map->grid)
		printf("Error\nAllocation error\n"), exit(1);
	i = 0;
	while (i < height)
	{
		map->map->grid[i] = malloc(width - 1);
		i++;
	}
	free(map->map->grid);
}

void	fill_map(int fd, t_global *map)
{
	char	*line;
	(void) map;

	line = get_next_line(fd);
	printf("%s", line);
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
	new_allocate_try(fd);
	//close(fd);
	//open(argv[1], O_RDONLY);
	//allocate_try_1(fd);
	//allocate_and_fill_map(fd, &game);
	//int count = check_map_size(fd, &game);
	//allocate_and_fill_map(fd, &game, count);
	//check_map_size(fd, &game);
	//allocate_map(fd, &game);
	//close(fd);
	//fd = open(argv[1], O_RDONLY);
	//fill_map(fd, &game);
	//is_map_square(fd, &game);
	//get_map_size(&game);
	//test_map(game.map->grid);
	//lines_length(fd);
	close(fd);

}

