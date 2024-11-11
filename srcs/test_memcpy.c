/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 22:03:09 by mmoulati          #+#    #+#             */
/*   Updated: 2024/11/10 09:57:05 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"

extern char		desc[];
typedef struct args
{
	char		*dst;
	const char	*src;
	size_t		dstsize;
}				t_args;

void	*memcpy_wrapper(void *args)
{
	t_args	*params;

	params = args;
	return (memcpy(params->dst, params->src, params->dstsize));
}

void	*ft_memcpy_wrapper(void *args)
{
	t_args	*params;

	params = args;
	return (ft_memcpy(params->dst, params->src, params->dstsize));
}
int	main(void)
{
	int		strs_len;
	int		sizes_len;
	int		exp_status;
	int		res_status;
	char	*exp;
	char	*res;
	char	arr_exp[100];
	char	arr_res[100];
	int		error;
	size_t	lens[6] = {0, 1, 2, 50,100};
	int		i;
	int		j;
	int		k;
	t_args	exp_args;
	t_args	res_args;
	int		errors;

	errors = 0;
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
	sizes_len = sizeof(lens) / sizeof(lens[0]);
	for (i = 0; i < strs_len; i++)
	{
		lens[sizes_len - 2] = strs[i] ? strlen(strs[i]) : 0;
		error = 0;
		for (j = 0; j < strs_len; j++)
		{
			lens[sizes_len - 1] = strs[j] ? strlen(strs[j]) : 0;
			for (k = 0; k < sizes_len; k++)
			{
				exp_args.dstsize = lens[k];
				exp_args.src = strs[j];
				res_args.dstsize = lens[k];
				res_args.src = strs[j];
				if (!strs[i])
				{
					exp_args.dst = 0;
					res_args.dst = 0;
				}
				else
				{
					res_args.dst = arr_exp;
					exp_args.dst = arr_res;
					strcpy(exp_args.dst, strs[i]);
					strcpy(res_args.dst, strs[i]);
				}
				exp_status = run_test(memcpy_wrapper, &exp_args);
				res_status = run_test(ft_memcpy_wrapper, &res_args);
				sprintf(desc, "memcpy(\"%s\",\"%s\",%lu)", res_args.dst,
					res_args.src, lens[k]);
				if (exp_status != res_status)
				{
					msg_fail(desc, str_sig(exp_status), str_sig(exp_status));
				}
				else if (exp_status == 0)
				{
					res = ft_memcpy_wrapper(&res_args);
					exp = memcpy_wrapper(&exp_args);
					if (res == exp)
						continue ;
					else if (res == 0 ^ exp == 0 || memcmp(res, exp,
							lens[k]) != 0)
					{
						msg_fail(desc, exp_args.dst, res_args.dst);
						error++;
					}
				}
			}
		}
		if (error == 0)
			msg_pass(desc);
		errors += error;
	}
	msg_status("memcpy", errors);
}
