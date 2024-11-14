/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putchar_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:09:34 by mmoulati          #+#    #+#             */
/*   Updated: 2024/11/09 14:04:47 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"
#include <stdio.h>

typedef struct s_args
{
	int		fd;
	char	c;
}			t_args;

void	*test_custom(void *args)
{
	t_args	*p;

	p = (t_args *)args;
	ft_putchar_fd(p->c, p->fd);
	return (0);
}

int	main(void)
{
	int		i;
	int		len;
	int		exp;
	int		error;
	char	desc[4096];

	error = 0;
	t_args args[] = {
		{0, 'a'},
		{1, 'a'},
		{-1, 'b'},
		{257, 'a'},
		{1, 'a'},
	};
	len = sizeof(args) / sizeof(args[0]);
	i = 0;
	while (i < len)
	{
		sprintf(desc, GRAY "\tft_putchar_fd(%3d,%3d) :\t ", args[i].c,
			args[i].fd);
		exp = run_test(test_custom, &args[i]);
		printf("\t");
		str_sig(exp);
		if (exp != 0)
			error++;
		printf("%s\n" REST, desc);
		i++;
	}
	msg_status("ft_putchar_fd", error);
	printf("\n");
}
