/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sight.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 22:04:32 by jaeskim           #+#    #+#             */
/*   Updated: 2020/07/11 22:38:04 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern int g_colup[4];
extern int g_coldown[4];
extern int g_rowleft[4];
extern int g_rowright[4];
extern int g_board[4][4];
extern int g_board_bak[4][4];

int		check_left(void)
{
	int row;
	int pivot;
	int col;
	int visible_box;

	row = 0;
	while (row < 4)
	{
		pivot = 0;
		col = 0;
		visible_box = 0;
		while (col < 4)
		{
			if (pivot < g_board[row][col])
			{
				pivot = g_board[row][col];
				visible_box++;
			}
			col++;
		}
		if (g_rowleft[row] != visible_box)
			return (0);
		row++;
	}
	return (1);
}

int		check_right(void)
{
	int row;
	int pivot;
	int col;
	int visible_box;

	row = 0;
	while (row < 4)
	{
		pivot = 0;
		col = 3;
		visible_box = 0;
		while (col >= 0)
		{
			if (pivot < g_board[row][col])
			{
				pivot = g_board[row][col];
				visible_box++;
			}
			col--;
		}
		if (g_rowright[row] != visible_box)
			return (0);
		row++;
	}
	return (1);
}

int		check_up(void)
{
	int row;
	int pivot;
	int col;
	int visible_box;

	col = 0;
	while (col < 4)
	{
		pivot = 0;
		row = 0;
		visible_box = 0;
		while (row < 4)
		{
			if (pivot < g_board[row][col])
			{
				pivot = g_board[row][col];
				visible_box++;
			}
			row++;
		}
		if (g_colup[col] != visible_box)
			return (0);
		col++;
	}
	return (1);
}

int		check_down(void)
{
	int row;
	int pivot;
	int col;
	int visible_box;

	col = 0;
	while (col < 4)
	{
		pivot = 0;
		row = 3;
		visible_box = 0;
		while (row >= 0)
		{
			if (pivot < g_board[row][col])
			{
				pivot = g_board[row][col];
				visible_box++;
			}
			row--;
		}
		if (g_colup[col] != visible_box)
			return (0);
		col++;
	}
	return (1);
}
