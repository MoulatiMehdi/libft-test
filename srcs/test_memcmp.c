/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 22:03:09 by mmoulati          #+#    #+#             */
/*   Updated: 2024/11/12 17:20:05 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"
#include <string.h>

char			desc[4096];

typedef struct s_args
{
	char		*dst;
	const char	*src;
	size_t		dstsize;
}				t_args;

void	*memcmp_wrapper(void *args)
{
	t_args	*params;

	params = args;
	memcmp(params->dst, params->src, params->dstsize);
	return (0);
}

void	*ft_memcmp_wrapper(void *args)
{
	t_args	*params;

	params = args;
	ft_memcmp(params->dst, params->src, params->dstsize);
	return (0);
}

int	main(void)
{
	int		strs_len;
	int		exp_status;
	int		res_status;
	int		exp;
	int		res;
	char	arr_exp[100];
	char	arr_res[100];
	int		error;
	int		i;
	int		j;
	int		k;
	t_args	args;
	int		total_erros;

	total_erros = 0;
	void *strs[] = {
		NULL,
		"",
		"Hello"
		"Hello, World!",
		"12345",
		"12345\0abc",
		"Special chars: \n",
		"Tabs\tare\tfun",
		"MixedCase123",
		"Repeating characters: aaa",
		"Edge case with \x80",
		"Last character null\0",
		"First part\0Second part",
	};
	strs_len = sizeof(strs) / sizeof(strs[0]);
	for (i = 0; i < strs_len; i++)
	{
		error = 0;
		for (j = 0; j < strs_len; j++)
		{
			for (k = 0; k < 30; k++)
			{
				args.dst = strs[i];
				args.src = strs[j];
				args.dstsize = k;
				exp_status = run_test(memcmp_wrapper, &args);
				res_status = run_test(ft_memcmp_wrapper, &args);
				sprintf(desc, "ft_memcmp(\"%s\",\"%s\",%lu)", args.dst,
					args.src, args.dstsize);
				if (exp_status != res_status)
				{
					msg_fail(desc, str_sig(exp_status), str_sig(res_status));
					error++;
					break ;
				}
				if (exp_status == res_status && exp_status == 0)
				{
					res = ft_memcmp(args.dst, args.src, args.dstsize);
					exp = memcmp(args.dst, args.src, args.dstsize);
					sprintf(arr_exp, "%d", exp);
					sprintf(arr_res, "%d", res);
					if (res != exp)
					{
						msg_fail(desc, arr_exp, arr_res);
						error++;
						break ;
					}
				}
			}
			if (error == 0)
			{
				sprintf(desc, "ft_memcmp(\"%s\",\"%s\",x)", args.dst, args.src);
				msg_pass(desc);
			}
			if (error != 0)
				break ;
		}
		total_erros += error;
	}
	msg_status("ft_memcmp", total_erros);
}
