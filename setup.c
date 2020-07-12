/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 17:01:15 by jaeskim           #+#    #+#             */
/*   Updated: 2020/07/12 20:06:57 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern int g_colup[4];
extern int g_coldown[4];
extern int g_rowleft[4];
extern int g_rowright[4];
extern int g_board[4][4];
extern int g_board_bak[4][4];

int		recursive(int r, int c);
void	check_last_part1(int i);
void	check_last_part2(int i);
void	check_first(int i);
void	check_first_second(int i);
void	check_second_third(int i);

int		fill_board(void)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		check_first(i);
		check_last_part1(i);
		check_last_part2(i);
		check_first_second(i);
		check_second_third(i);
		++i;
	}
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			g_board_bak[i][j] = g_board[i][j];
			++j;
		}
		++i;
	}
	return (recursive(0, 0));
}
