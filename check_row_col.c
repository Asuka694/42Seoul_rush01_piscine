/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_row_col.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 22:24:55 by jaeskim           #+#    #+#             */
/*   Updated: 2020/07/12 19:51:30 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern int g_colup[4];
extern int g_coldown[4];
extern int g_rowleft[4];
extern int g_rowright[4];
extern int g_board[4][4];
extern int g_board_bak[4][4];

int		check_left(void);
int		check_right(void);
int		check_up(void);
int		check_down(void);

int		check_row(int r, int c)
{
	int i;

	i = 0;
	while (i < r)
	{
		if (g_board[r][c] == g_board[i][c])
			return (0);
		i++;
	}
	return (1);
}

int		check_col(int r, int c)
{
	int i;

	i = 0;
	while (i < c)
	{
		if (g_board[r][c] == g_board[r][i])
			return (0);
		i++;
	}
	return (1);
}

int		check_no_wrap(int r, int c)
{
	int result;

	result = check_row(r, c);
	result &= check_col(r, c);
	return (result);
}

int		check_is_vaild(int r, int c)
{
	int result;

	result = check_left();
	result &= check_right();
	result &= check_up();
	result &= check_down();
	return (result);
}
