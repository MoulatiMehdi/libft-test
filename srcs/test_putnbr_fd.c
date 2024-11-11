/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putnbr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:09:34 by mmoulati          #+#    #+#             */
/*   Updated: 2024/11/09 14:10:23 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"
#include <limits.h>
#include <stdio.h>

typedef struct s_args
{
	int	fd;
	int	c;
}		t_args;

void	*test_custom(void *args)
{
	t_args	*p;

	p = (t_args *)args;
	ft_putnbr_fd(p->c, p->fd);
	return (0);
}

int	main(void)
{
	int	i;
	int	len;
	int	exp;
	int	error;
	char desc[4096];

	error = 0;
	t_args args[] = {
		{1, 0},
		{1, INT_MAX},
		{1, INT_MIN},
		{1, 10000},
		{1, 9999},
		{0, 9999},
		{2, 9999},
		{3, 9999},
		{-1, 9999},
	};
	len = sizeof(args) / sizeof(args[0]);
	i = 0;
	while (i < len)
	{
		exp = run_test(test_custom, &args[i]);
		sprintf(desc,GRAY"\tft_putnbr_fd(%3d,%3d)\n", args[i].c, args[i].fd);
		printf("\n");
		report_test_result(exp);
		printf("%s"REST,desc);
		if (exp != 0)
			error++;
		i++;
	}
	msg_status("ft_putnbr_fd", error);
	printf("\n");
}
