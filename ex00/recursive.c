/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 21:50:12 by jeujeon           #+#    #+#             */
/*   Updated: 2020/07/12 21:25:05 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

extern int g_board[4][4];
extern int g_board_bak[4][4];
int g_flag = 0;

void	recursive_col(int r, int c, int *i)
{
	while (*i < 5)
	{
		if (g_flag)
			return ;
		g_board[r][c] = *i;
		if (check_no_wrap(r, c))
			recursive(r, c + 1);
		*i = *i + 1;
	}
}

int		recursive(int r, int c)
{
	int i;

	if (g_flag)
		return (1);
	if (r < 4)
	{
		if (c < 4)
		{
			i = 1;
			if (g_board_bak[r][c] == 0)
				recursive_col(r, c, &i);
			recursive(r, c + 1);
		}
		else
			recursive(r + 1, 0);
	}
	else
	{
		if (check_is_vaild())
			g_flag = 1;
	}
	return (g_flag);
}
