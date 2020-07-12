/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 19:44:56 by jaeskim           #+#    #+#             */
/*   Updated: 2020/07/12 19:45:59 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern int g_colup[4];
extern int g_coldown[4];
extern int g_rowleft[4];
extern int g_rowright[4];
extern int g_board[4][4];
extern int g_board_bak[4][4];

void	check_last_part1(int i)
{
	int j;

	if (g_rowleft[i] == 4)
	{
		j = 0;
		while (j < 4)
		{
			g_board[i][j] = j + 1;
			j++;
		}
	}
	if (g_rowright[i] == 4)
	{
		j = 3;
		while (j >= 0)
		{
			g_board[i][j] = 4 - j;
			j--;
		}
	}
}

void	check_last_part2(int i)
{
	int j;

	if (g_colup[i] == 4)
	{
		j = 0;
		while (j < 4)
		{
			g_board[j][i] = j + 1;
			j++;
		}
	}
	if (g_coldown[i] == 4)
	{
		j = 3;
		while (j >= 0)
		{
			g_board[j][i] = 4 - j;
			j--;
		}
	}
}

void	check_first(int i)
{
	if (g_colup[i] == 1)
		g_board[0][i] = 4;
	if (g_coldown[i] == 1)
		g_board[3][i] = 4;
	if (g_rowleft[i] == 1)
		g_board[i][0] = 4;
	if (g_rowright[i] == 1)
		g_board[i][3] = 4;
}

void	check_first_second(int i)
{
	if (g_colup[i] == 1 && g_coldown[i] == 2)
		g_board[3][i] = 3;
	if (g_coldown[i] == 1 && g_colup[i] == 2)
		g_board[0][i] = 3;
	if (g_rowleft[i] == 1 && g_rowright[i] == 2)
		g_board[i][3] = 3;
	if (g_rowright[i] == 1 && g_rowleft[i] == 2)
		g_board[i][0] = 3;
}

void	check_second_third(int i)
{
	if (g_colup[i] == 2 && g_coldown[i] == 3)
		g_board[1][i] = 4;
	if (g_coldown[i] == 2 && g_colup[i] == 3)
		g_board[2][i] = 4;
	if (g_rowleft[i] == 2 && g_rowright[i] == 3)
		g_board[i][1] = 4;
	if (g_rowright[i] == 2 && g_rowleft[i] == 3)
		g_board[i][2] = 4;
}
