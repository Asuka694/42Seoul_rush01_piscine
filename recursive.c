/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 21:50:12 by jeujeon           #+#    #+#             */
/*   Updated: 2020/07/12 18:52:34 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern int g_board[4][4];
extern int g_board_bak[4][4];
int g_flag = 0;

int		check_is_vaild(int r, int c);
int		check_no_wrap(int r, int c);
void	print_board();

int	recursive(int r, int c)
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
			{
				while (i < 5)
				{
					if (g_flag)
						return (1);
					g_board[r][c] = i;
					if (check_no_wrap(r, c))
						recursive(r, c + 1);
					i++;
				}
			}
			if (r == 3 && c == 3)
			{
				if (check_is_vaild(r, c))
				{
					g_flag = 1;
					return (1);
				}
			}
			recursive(r, c + 1);
		}
		else
		{
			c = 0;
			recursive(r + 1, c);
		}
	}
	return (g_flag);
}


