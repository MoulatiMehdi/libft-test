/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 22:03:09 by mmoulati          #+#    #+#             */
/*   Updated: 2024/11/10 10:41:08 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"
#include <string.h>

typedef struct strlcat_args
{
	char		*dst;
	const char	*src;
	size_t		dstsize;
}				t_strlcat_args;

void	*strlcat_wrapper(void *args)
{
	t_strlcat_args	*params;

	params = args;
	(strlcat(params->dst, params->src, params->dstsize));
	return (0);
}

void	*ft_strlcat_wrapper(void *args)
{
	t_strlcat_args	*params;

	params = args;
	(ft_strlcat(params->dst, params->src, params->dstsize));
	return (0);
}

int	main(void)
{
	int				show;
	int				strs_len;
	int				sizes_len;
	int				exp_status;
	int				res_status;
	size_t			exp;
	size_t			res;
	char			arr_exp[100];
	char			arr_res[100];
	int				error;
	size_t			lens[6] = {0, 1, 2, 50};
	int				i;
	int				j;
	int				k;
	t_strlcat_args	exp_args;
	t_strlcat_args	res_args;
	int				total_erros;
	char			nb1[30];
	char			nb2[30];

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
				exp_status = run_test(strlcat_wrapper, &exp_args);
				res_status = run_test(ft_strlcat_wrapper, &res_args);
				if (exp_status != res_status)
				{
					msg_fail(desc, str_sig(exp_status), str_sig(exp_status));
					error++;
					break ;
				}
				if (exp_status == res_status && exp_status == 0)
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
					res = ft_strlcat(res_args.dst, res_args.src,
							res_args.dstsize);
					exp = strlcat(exp_args.dst, exp_args.src, exp_args.dstsize);
					if (res != exp)
					{
						sprintf(nb1, "%lu", exp);
						sprintf(nb2, "%lu", res);
						msg_fail(desc, nb1, nb2);
						error++;
						break ;
					}
					else if (exp_status == 0 && res_args.dst != exp_args.dst)
					{
						if ((res_args.dst == 0 || exp_args.dst == 0)|| strcmp(exp_args.dst,
								res_args.dst))
						{
							error++;
							msg_fail(desc, exp_args.dst, res_args.dst);
							break ;
						}
					}
				}
			}
		}
		if (error == 0)
			msg_pass(strs[i]);
		total_erros += error;
	}
	msg_status("ft_strlcat", total_erros);
}
