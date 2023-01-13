/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 05:27:11 by myko              #+#    #+#             */
/*   Updated: 2023/01/14 05:27:12 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "star_wars.h"

void	count_num(int *num, int n)
{
	int	r, tmp;

	while (n % 9 != 0)
	{
		tmp = n;
		while (tmp)
		{
			num[tmp % 10]++;
			tmp /= 10;
		}
		n--;
	}
	for (int i = 1; n > 0; i *= 10)
	{
		r = n % 10;
		n /= 10;
		for (int j = 0; j < r + 1; j++)
			num[j] += (n + 1) * i;
		for (int j = r + 1; j < 10; j++)
			num[j] += n * i;
		num[0] -= i;
	}
	for (int i = 0; i < 10; i++)
		printf("%d ", num[i]);
	printf("\n");
}
