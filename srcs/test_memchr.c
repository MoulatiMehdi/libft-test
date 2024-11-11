/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 22:03:09 by mmoulati          #+#    #+#             */
/*   Updated: 2024/11/10 10:45:40 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"
#include <stdio.h>

char		desc[4096];

typedef struct s_args
{
	char	*str;
	int		c;
	size_t	size;
}			t_args;

void	*memchr_wrapper(void *args)
{
	t_args	*params;

	params = (t_args *)args;
	memchr(params->str, params->c, params->size);
	return (0);
}

void	*ft_memchr_wrapper(void *args)
{
	t_args	*params;

	params = (t_args *)args;
	ft_memchr(params->str, params->c, params->size);
	return (0);
}

int	main(void)
{
	int		len;
	int		exp_status;
	int		res_status;
	void	*exp;
	void	*res;
	int		error;
	int		errors;

	errors = 0;
	t_args strs[] = {
		{.str = NULL},
		{.str = ""},
		{.str = "Hello, World!"},
		{.str = "Test with special char: \n"},
		{.str = "12341567890"},
		{.str = "\x00\x01\x02\x03\x7f\x55"},
	};
	len = sizeof(strs) / sizeof(strs[0]);
	for (int i = 0; i < len; i++)
	{
		error = 0;
		for (size_t size = 0; size < 20; size++)
		{
			strs[i].size = size;
			for (int c = -128; c < 256; c++)
			{
				strs[i].c = c;
				sprintf(desc, "memchr(\"%s\",%d,%lu)", strs[i].str, c, size);
				exp_status = run_test(memchr_wrapper, &strs[i]);
				res_status = run_test(ft_memchr_wrapper, &strs[i]);
				if (exp_status != res_status)
				{
					msg_fail(desc, str_sig(exp_status), str_sig(res_status));
					error++;
					break ;
				}
				else if (exp_status == 0)
				{
					exp = memchr(strs[i].str, c, size);
					res = ft_memchr(strs[i].str, c, size);
					if (exp != res)
					{
						msg_fail(desc, exp, res);
						error++;
					}
				}
			}
			if (exp_status != res_status)
				break ;
		}
		if (error == 0)
			msg_pass(desc);
		errors += error;
	}
	msg_status("ft_memchr", errors);
}
