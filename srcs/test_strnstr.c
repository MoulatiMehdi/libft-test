/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strnstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 22:03:09 by mmoulati          #+#    #+#             */
/*   Updated: 2024/11/12 16:10:29 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"
#include <string.h>

typedef struct args
{
	const char	*dst;
	const char	*src;
	size_t		dstsize;
}				t_args;

void	*strnstr_wrapper(void *args)
{
	t_args	*params;

	params = args;
	return (strnstr(params->dst, params->src, params->dstsize));
}

void	*ft_strnstr_wrapper(void *args)
{
	t_args	*params;

	params = args;
	return (ft_strnstr(params->dst, params->src, params->dstsize));
}

int	main(void)
{
	int		show;
	int		strs_len;
	int		sizes_len;
	int		exp_status;
	int		res_status;
	char	*exp;
	char	*res;
	int		error;
	int		i;
	int		j;
	int		k;
	t_args	args;
	int		total_erros;
	size_t	lens[10] = {0, 1, 2, 7, 10, 20, 50};

	total_erros = 0;
	show = 0;
	void *strs[] = {
		NULL,
		"",
		"Hello",
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
				args.src = strs[j];
				args.dstsize = lens[k];
				args.dst = strs[i];
				exp_status = run_test(strnstr_wrapper, &args);
				res_status = run_test(ft_strnstr_wrapper, &args);
				sprintf(desc, "ft_strnstr(\"%s\",\"%s\",%lu)", strs[i], strs[j],
					lens[k]);
				if (exp_status != res_status)
				{
					msg_fail(desc, str_sig(exp_status), str_sig(exp_status));
					error++;
					break ;
				}
				if (exp_status == 0)
				{
					res = strnstr_wrapper(&args);
					exp = strnstr_wrapper(&args);
					if (res != exp)
					{
						msg_fail(desc, exp, res);
						error++;
						break ;
					}
				}
			}
		}
		if (error == 0)
		{
			sprintf(desc, "ft_strnstr(\"%s\",\"%s\",x)", strs[i], strs[j]);
			msg_pass(desc);
		}
		total_erros += error;
	}
	msg_status("ft_strnstr", total_erros);
}
