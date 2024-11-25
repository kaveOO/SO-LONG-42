/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:09:31 by albillie          #+#    #+#             */
/*   Updated: 2024/11/23 13:23:38 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main()
{
	t_global *global;

	global = (t_global *)malloc(sizeof(t_global));

	free(global);
	ft_printf("j'adore le caca puant!");
}
