/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:09:34 by mmoulati          #+#    #+#             */
/*   Updated: 2024/11/09 22:45:44 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"
#include <stdio.h>

typedef struct s_args
{
	size_t	n;
	int		c;
	char	*str;
}			t_args;

void	*memset_wrapper(void *args)
{
	t_args	*p;

	p = (t_args *)args;
	memset(p->str, p->c, p->n);
	return (0);
}

void	*ft_memset_wrapper(void *args)
{
	t_args	*p;

	p = (t_args *)args;
	ft_memset(p->str, p->c, p->n);
	return (0);
}

int	main(void)
{
	int		i;
	int		len;
	int		exp;
	int		error;
	int		errors;
	char	desc[4096];
	int		res;

	error = 0;
	errors = 0;
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
		error = 0;
		for (int j = -256; j < 256; j++)
		{
			args[i].c = j;
			exp = run_test(memset_wrapper, &args[i]);
			res = run_test(ft_memset_wrapper, &args[i]);
			sprintf(desc, "ft_memset(\"%s\",x,%lu)",
				args[i].str ? args[i].str : "NULL", args[i].n);
			if (exp != res)
			{
				msg_fail(desc, str_sig(exp), str_sig(res));
				error++;
				break ;
			}
		}
		if (error == 0)
			msg_pass(desc);
		i++;
		errors += error;
	}
	msg_status("ft_memset", errors);
}
