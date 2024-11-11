/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putendl_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:09:34 by mmoulati          #+#    #+#             */
/*   Updated: 2024/11/09 14:08:13 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"
#include <stdio.h>

typedef struct s_args
{
	int		fd;
	char	*str;
}			t_args;

void	*test_custom(void *args)
{
	t_args	*p;

	p = (t_args *)args;
	ft_putendl_fd(p->str, p->fd);
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
		{
			.fd = 1,
			.str = 0,
		},
		{
			.fd = 1,
			.str = "",
		},
		{
			.fd = 1,
			.str = "Hello World",
		},
		{
			.fd = 1,
			.str = "a",
		},
	};
	len = sizeof(args) / sizeof(args[0]);
	i = 0;
	while (i < len)
	{
		sprintf(desc, GRAY "\t ft_putendl_fd(\"%s\",%3d)" REST, args[i].str,
			args[i].fd);
		exp = run_test(test_custom, &args[i]);
		report_test_result(exp);
		if (exp != 0)
			error++;
		printf("%s\n", desc);
		i++;
	}
	msg_status("ft_putendl_fd", error);
	printf("\n");
}
