/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 12:35:28 by jaeskim           #+#    #+#             */
/*   Updated: 2020/07/12 21:10:11 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int g_colup[4];
int g_coldown[4];
int g_rowleft[4];
int g_rowright[4];
int g_board[4][4];
int g_board_bak[4][4];

void	set_argv(char *str, int cnt, int i)
{
	if (cnt / 4 == 0)
		g_colup[i] = *str - '0';
	else if (cnt / 4 == 1)
		g_coldown[i] = *str - '0';
	else if (cnt / 4 == 2)
		g_rowleft[i] = *str - '0';
	else if (cnt / 4 == 3)
		g_rowright[i] = *str - '0';
}

int		pars_argv(char *str)
{
	int cnt;
	int i;

	cnt = 0;
	while (*str)
	{
		if ('1' <= *str && *str <= '4')
		{
			if (cnt % 4 == 0)
				i = 0;
			set_argv(str, cnt, i++);
			cnt++;
			if (*++str == ' ')
				++str;
			else if (*str == '\0')
				break ;
			else
				return (0);
		}
		else
			return (0);
	}
	if (cnt == 16)
		return (1);
	return (0);
}

int		main(int ac, char **av)
{
	if (ac == 2 && pars_argv(av[1]) && fill_board())
		print_board();
	else
		write(1, "Error\n", 6);
	return (0);
}
