/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 20:29:29 by jaeskim           #+#    #+#             */
/*   Updated: 2020/07/11 22:40:33 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

extern int g_colup[4];
extern int g_coldown[4];
extern int g_rowleft[4];
extern int g_rowright[4];
extern int g_board[4][4];

void print_board()
{
	int i;
	int j;
	char tmp;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			tmp = g_board[i][j] + '0';
			write(1, &tmp, 1);
			write(1, " ", 1);
			++j;
		}
		write(1, "\n", 1);
		++i;
	}
}
