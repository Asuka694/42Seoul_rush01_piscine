/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 21:50:12 by jeujeon           #+#    #+#             */
/*   Updated: 2020/07/11 21:50:14 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern int g_board[4][4];
extern int g_board_bak[4][4];
int g_flag = 0;

int	check_is_vaild(int r, int c);
void	print_board();

int	recursive(int r, int c)
{
	int i;

	if (g_flag)
		return (1);

	if (r <= 3)
	{
		if (c <= 3)
		{
			i = 1;
			while (i < 4)
			{
				if (g_board_bak[r][c] == 0)
				{
					g_board[r][c] = i;
					printf("r: %d,c: %d, value: %d, check: %d, bak: %d\n",r, c, g_board[r][c], check_is_vaild(r, c), g_board_bak[r][c]);
					print_board();
					printf("-----------\n");
					if (check_is_vaild(r, c))
					{
						if (r == 3 && c == 3)
						{
							g_flag = 1;
							return (1);	
						}	
						return (recursive(r, c + 1));
					}
				}
				i++;
			}
			return (recursive(r, c + 1));
		}
		else
		{
			c = 0;
			return (recursive(r + 1, c));
		}
	}
	return (0);
}


