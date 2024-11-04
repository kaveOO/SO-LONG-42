/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:10:51 by albillie          #+#    #+#             */
/*   Updated: 2024/11/04 20:33:05 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/home/albillie/Desktop/SO-LONG-42/includes/so_long.h"

void	map_checker(int argc, char **argv)
{
	char	*map_name;
	char	*buffer;
	int fd;

	if (argc < 2)
		printf("Please enter the MAP argument !\n");
	else if (argc > 2)
		printf("You have too much arguments !\n");
	else if (argc == 2)
	{
		printf("Checking the MAP availability...\n");
		map_name = argv[1];
		printf("%s\n", map_name);
		if (open(map_name, O_RDONLY))
		{



		}
	}

}
