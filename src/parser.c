/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:10:51 by albillie          #+#    #+#             */
/*   Updated: 2024/11/29 00:33:03 by albillie         ###   ########.fr       */
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
		ft_printf("Error\nInvalid map name !\n");
		exit(1);
	}
	if (!check_extension(filename, "ber"))
	{
		ft_printf("Error\nMap file extension is invalid !\n");
		exit(1);
	}
	ft_printf("Map (%s) opened!\n", filename);
}

/* void	new_allocate_try(int fd, t_global *game)
{
	int i  = 0;

	while (get_next_line(fd))
	{
		i++;
	}
	map = malloc(sizeof(char *) * i);
} */

/* t_map	map_allocation(int fd)
{
	char *line;
	t_map map;
	int i = 0;

	map.height = 0;
	map.width = 0;

	line = get_next_line(fd);
	map.grid = malloc(sizeof(char *) * 7);
	ft_strlcpy(map.grid[i], line, ft_strlen(line) + 1);
	ft_printf("%s", map.grid[i]);
	i++;
	line = get_next_line(fd);
	while (line != NULL)
	{
		map.grid[i] = malloc(sizeof(char) * ft_strlen(line));
		ft_strlcpy(map.grid[i], line, ft_strlen(line) + 1);
		ft_printf("%s", map.grid[i]);
		line = get_next_line(fd);
		i++;
	}
	printf("~%s~", map.grid[1]);
	return (map);
} */

/* void	allocate_and_fill_map(int fd, t_global *map, int count)
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
} */

/* void	map_size_checker(t_global *game)
{
	int	i = 0;
	while (map[1][i])
		i++;
	printf("%d", i);
} */

/* int	check_map_size(int fd, t_global *map)
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
} */

/* void	allocate_map(int fd, t_global *map)
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
} */

/* void	fill_map(int fd, t_global *map)
{
	char	*line;
	(void) map;

	line = get_next_line(fd);
	printf("%s", line);
} */

/* char *string_filler(const char *s)
{
	char *string;

	string = malloc(ft_strlen(s) + 1);
	if (!string)
		printf("failed something");
	strcpy(string, s);
	return (string);
}
void	recursive_checker(int fd, t_map *map, int height)
{
	char	*line;
	int i = 0;

	line = get_next_line(fd);
	if (line == NULL)
	{
		return ;
	}
	map->grid = malloc(sizeof(char *) * 1);
	map->grid[i] = string_filler(line);
	recursive_checker(fd, map ,height);
} */
int	get_height(char *filename)
{
	int		height;
	int		fd;
	char	*line;

	height = 0;
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		height++;
	}
	free(line);
	close(fd);
	return (height);
}
int get_width(char *filename)
{
	int		width;
	int		fd;
	char	*line;

	width = 0;
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	width = ft_strlen(line);
	free(line);
	get_next_line(-1);
	close(fd);
	return (width);
}
void	map_checker(char **map, int width, int height)
{
	check_map_size(map, width, height);
	check_map_closure(map, width, height);
	check_map_char(map, height);

}

void	check_map_closure(char **map, int width, int height)
{
	int	i;
	int	j;

	i = 0;
	j = height - 1;
	while (map[j][i] != '\n')
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			exit_free("Invalid characters on first or/and last line !", map);
		while (j > 0)
		{
			if (map[j][width - 2] != '1' || map[j][0] != '1')
				exit_free("Invalid enclosure on sides !", map);
			j--;
		}
		i++;
	}
}
void	check_map_char(char **map, int height) // TODO Faire le parsing de l'interieur de la map !
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	(void) height;
	while (map[i][j])
	{
		if (map[i][j] == '\n')
			i++;
		if (map[i][j] == 'C')
			printf("FOUND C");
		printf("%c", map[i][j]);
		j++;
	}
}

void	exit_free(char *str, char **map)
{
	if (str)
	{
		printf("Error\n%s\n", str);
		free_map(map);
		exit(1);
	}
}


/* void	check_map_char(char **map)
{
	int	i;
	int	j;


	i = 0;
	j = 0;
	while (map[i][j] != '\n')
	{
		if (map[i][j] == '1')
		{
			i++;
		}
		printf
		i++;
		j++;
	}
} */

void	check_map_size(char **map, int width, int height)
{
	int		i;
	size_t	ref;

	i = 0;
	ref = ft_strlen(map[i++]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != ref)
		{
			printf("Error\nInvalid map line length on line !\n");
			free_map(map);
			exit(1);
		}
		i++;
	}
	if (width == height)
	{
		printf("Error\nYour map is square !\n");
		free_map(map);
		exit(1);
	}
}


/* char	**ft_creatematrix(int width, int height)
{
	char	**grid;
	// int		i;
	(void) width;
	grid = malloc(sizeof(char *) * (height + 1));
	return (grid);
} */

char	**fill_matrix(char **map, char *filename, int height)
{
	int		fd;
	int		i;
	char	*line;

	map = malloc(sizeof(char *) * (height + 1));
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	map[0] = line;
	i = 1;
	while (i < height)
	{
		line = get_next_line(fd);
		map[i] = line;
		i++;
	}
	map[i] = NULL;
	get_next_line(-1);
	close(fd);
	return (map);
}
void	free_map(char **map)
{
	int i = 0;
	while(map && map[i])
		free(map[i++]);
	free(map);
}

/*
void	map_checker(char **map)
{
	printf("%s", map[0]);
	printf("%s", map[1]);
	printf("%s", map[2]);
	printf("%s", map[3]);
	printf("%s", map[4]);
	int i = 0;
	while(map && map[i])
		free(map[i++]);
	free(map);
}*/


int main(int argc, char **argv)
{
	args_checker(argv[1], argc);
	//t_global game;
	t_map *map;
	// map.height = 0;
	// map.width = 0;
	//game.map = &map;
	map = (t_map *)malloc(sizeof(t_map)); //free
	map->height = get_height(argv[1]);
	map->width = get_width(argv[1]);
	map->grid = fill_matrix(map->grid, argv[1], map->height);
	map_checker(map->grid, map->width, map->height);
	free_map(map->grid);
	//map_checker(map->grid);
	return 0;
	//int height = 0;
	//printf("~\n%s\n~", map.grid[2]);
	//printf("%s", game.map->grid[1]);
	//printf("%s", game.map->grid[1]);
	//map_size_checker(&game);
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
	map = map;
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


