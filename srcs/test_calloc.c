/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_calloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:32:18 by mmoulati          #+#    #+#             */
/*   Updated: 2024/11/09 23:24:19 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "test.h"

typedef struct s_args
{
	size_t	size;
	size_t	count;
}			t_args;

void	*calloc_wrapper(void *args)
{
	t_args	*params;
	void	*p;

	params = args;
	p = calloc(params->count, params->size);
	return (p);
}

void	*ft_calloc_wrapper(void *args)
{
	t_args	*params;
	void	*p;

	params = args;
	p = ft_calloc(params->count, params->size);
	return (p);
}

int	test_arr(char *exp, char *res)
{
	int	test;

	test = !(exp == 0 ^ res == 0);
	test = test && (exp == 0 || exp[0] == res[0]);
	return (test);
}

int	main(void)
{
	int		i;
	int		size;
	int		error;
	int		exp_status;
	int		res_status;
	char	desc[4096];
	char	*res;
	char	*exp;

	error = 0;
	t_args args[] = {
		{SIZE_MAX, SIZE_MAX},
		{SIZE_MAX, 0},
		{0, 0},
		{0, SIZE_MAX},
		{4, 10},
		{214748365, 10},
	};
	size = sizeof(args) / sizeof(args[0]);
	i = 0;
	while (i < size)
	{
		sprintf(desc, "ft_calloc(%lu,%lu)", args[i].count, args[i].size);
		exp_status = run_test(calloc_wrapper, &args[i]);
		res_status = run_test(ft_calloc_wrapper, &args[i]);
		if (exp_status != res_status)
		{
			msg_fail(desc, str_sig(exp_status), str_sig(res_status));
			error++;
		}
		else if (exp_status == 0)
		{
			res = ft_calloc_wrapper(&args[i]);
			exp = calloc_wrapper(&args[i]);
			if (!test_arr(res, exp))
			{
				msg_fail(desc,exp,res);
				error++;
			}
		}
		if (error == 0)
			msg_pass(desc);
		i++;
	}
	msg_status("ft_calloc", error);
}
