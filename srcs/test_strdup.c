/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:05:29 by mmoulati          #+#    #+#             */
/*   Updated: 2024/11/09 22:45:54 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "test.h"

void	*ft_strdup_wrapper(void *str)
{
	ft_strdup((char *)str);
	return (0);
}

void	*strdup_wrapper(void *str)
{
	strdup((char *)str);
	return (0);
}

int	main(void)
{
	int		len;
	int		exp_status;
	int		res_status;
	char	*exp;
	char	*res;
	char	*s1;
	int		errors;
	int		error;
	char	desc[4096];

	errors = 0;
	char *strs[] = {
		NULL,
		"",
		"Hello",
		"Hello, World!",
		"Hello\0World",
		"12345",
		"12345\0abc",
		"Special chars: \n",
		"Spaces   ",
		"Tabs\tare\tfun",
		"abcde",
		"ABCDE",
		"MixedCase123",
		"Repeating characters: aaa",
		"Edge case with \x80",
		"Last character null\0",
		"First part\0Second part",
	};
	len = sizeof(strs) / sizeof(strs[0]);
	for (int i = 0; i < len; i++)
	{
		error = 0;
		s1 = strs[i];
		exp_status = run_test(strdup_wrapper, s1);
		res_status = run_test(ft_strdup_wrapper, s1);
		sprintf(desc, "strdup(\"%s\")\n", (char *)s1);
		if (exp_status != res_status)
		{
			msg_fail(desc, str_sig(exp_status), str_sig(res_status));
			error++;
			break ;
		}
		else if (exp_status == 0)
		{
			exp = strdup(s1);
			res = ft_strdup(s1);
			if (exp == 0 ^ res == 0 || (exp != 0 && strcmp(exp, res)))
			{
				error++;
				msg_fail(desc, exp, res);
			}
		}
		if (error == 0)
			msg_pass(desc);
		errors += error;
	}
	msg_status("ft_strdup", errors);
}
