/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_sort_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 02:13:39 by myko              #+#    #+#             */
/*   Updated: 2022/07/13 02:34:37 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	int	n, tmp;
	scanf("%d", &n);

	int	numbers[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &numbers[i]);

	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < n - i; j++)
		{
			if (numbers[j - 1] < numbers[j])
			{
				tmp = numbers[j - 1];
				numbers[j - 1] = numbers[j];
				numbers[j] = tmp;
			}
		}
        printf("%d\n", numbers[n - i - 1]);
	}
	return (0);
}
