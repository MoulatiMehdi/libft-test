/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:09:34 by mmoulati          #+#    #+#             */
/*   Updated: 2024/11/09 23:07:42 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"
#include <stdio.h>

typedef struct s_args
{
	size_t	n;
	char	*str;
}			t_args;

void	*bzero_wrapper(void *args)
{
	t_args	*p;

	p = (t_args *)args;
	bzero(p->str, p->n);
	return (0);
}

void	*ft_bzero_wrapper(void *args)
{
	t_args	*p;

	p = (t_args *)args;
	ft_bzero(p->str, p->n);
	return (0);
}

int	main(void)
{
	int		i;
	int		len;
	int		exp;
	int		error;
	char	desc[4096];
	int		res;

	error = 0;
	t_args args[] = {
		{
			.n = 10,
			.str = "Hello World",
		},
		{
			.n = 0,
			.str = 0,
		},
		{
			.n = 1,
			.str = 0,
		},
		{
			.n = 10,
			.str = malloc(0),
		},
		{
			.n = 100,
			.str = malloc(5),
		},
		{
			.n = 7,
			.str = malloc(7),
		},
	};
	len = sizeof(args) / sizeof(args[0]);
	i = 0;
	printf("\n");
	while (i < len)
	{
		exp = run_test(bzero_wrapper, &args[i]);
		res = run_test(ft_bzero_wrapper, &args[i]);
		sprintf(desc, "ft_bzero(\"%s\",%lu)",
			args[i].str ? args[i].str : "NULL", args[i].n);
		if (exp != res)
		{
			msg_fail(desc, str_sig(exp), str_sig(res));
			error++;
		}
		if (error == 0)
			msg_pass(desc);
		i++;
	}
	msg_status("ft_bzero", error);
}
