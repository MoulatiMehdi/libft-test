/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strrchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 22:03:09 by mmoulati          #+#    #+#             */
/*   Updated: 2024/11/09 22:46:13 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"

typedef struct strrchr_args
{
	const char	*dst;
	int			c;
}				t_args;

void	*strrchr_wrapper(void *args)
{
	t_args	*params;

	params = args;
	return (strrchr(params->dst, params->c));
}

void	*ft_strrchr_wrapper(void *args)
{
	t_args	*params;

	params = args;
	return (ft_strrchr(params->dst, params->c));
}
int	main(void)
{
	int		strs_len;
	int		exp_status;
	int		res_status;
	char	*exp;
	char	*res;
	int		error;
	int		i;
	t_args	exp_args;
	int		errors;
	char desc[4096];

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
	for (i = 0; i < strs_len; i++)
	{
		error = 0;
		for (int k = -256; k <= 256; k++)
		{
			exp_args.c = k;
			if (!strs[i])
				exp_args.dst = 0;
			else
				exp_args.dst = strs[i];
			exp_status = run_test(strrchr_wrapper, &exp_args);
			res_status = run_test(ft_strrchr_wrapper, &exp_args);
			sprintf(desc, "strrchr(\"%s\",%d)", exp_args.dst, exp_args.c);
			if (exp_status != res_status)
			{
				msg_fail(desc, str_sig(exp_status), str_sig(res_status));
				error++;
				break ;
			}
			else if (exp_status == 0)
			{
				res = ft_strrchr_wrapper(&exp_args);
				exp = strrchr_wrapper(&exp_args);
				if (res != exp)
				{
					msg_fail(desc, exp, res);
					error++;
					break ;
				}
			}
		}
		if (error == 0)
			msg_pass(desc);
		errors += error;
	}
	msg_status("strrchr", error);
}
