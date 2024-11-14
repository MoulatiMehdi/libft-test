/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:07:40 by mmoulati          #+#    #+#             */
/*   Updated: 2024/11/14 18:23:01 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

char	name[100];

char	*str_sig(int status)
{
	if (status == 0)
		sprintf(name, "[%s]", "NORMAL");
	else if (status == -1)
		sprintf(name, "[%s]", "UNKOWN");
	else
		sprintf(name, "[SIG%s]", strsignal(status));
	return (strdup(name));
}

int	test_signal(t_func buildin, t_func custom, void *args)
{
	int	exp;
	int	res;

	exp = run_test(buildin, args);
	res = run_test(custom, args);
	if (exp != res)
	{
		msg_fail(desc, str_sig(exp), str_sig(res));
		return (0);
	}
	return (1);
}
