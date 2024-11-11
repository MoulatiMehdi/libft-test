/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_to.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 10:59:55 by mmoulati          #+#    #+#             */
/*   Updated: 2024/11/10 11:24:40 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"

typedef int		(*is_funcs)(int);
typedef struct
{
	is_funcs	buildin;
	is_funcs	custom;
	char		*name;
}				test_func;

int	main(void)
{
	int		res;
	int		exp;
	int		error;
	char	nb1[30];
	char	nb2[30];
	int		size;

	test_func funcs[] = {
		{.custom = ft_tolower, .buildin = tolower, .name = "ft_tolower"},
		{.custom = ft_toupper, .buildin = toupper, .name = "ft_toupper"},
	};
	size = sizeof(funcs) / sizeof(funcs[0]);
	for (int i = 0; i < size; i++)
	{
		error = 0;
		for (int j = -256; j < 256; j++)
		{
			exp = funcs[i].buildin(j);
			res = funcs[i].custom(j);
			sprintf(desc, "%s(%d)", funcs[i].name, j);
			if (exp != res)
			{
				sprintf(nb1, "%c", exp);
				sprintf(nb2, "%c", res);
				error++;
				msg_fail(desc, nb1, nb2);
				break ;
			}
		}
		if (error == 0)
			msg_status(funcs[i].name, error);
	}
}
