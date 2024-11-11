/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:31:46 by mmoulati          #+#    #+#             */
/*   Updated: 2024/11/09 13:58:45 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"
#include <limits.h>
#include <stdio.h>
#include <string.h>

int	main(void)
{
	int		i;
	char	exp[30];
	char	*res;
	int		len;
	int		error;
	char	desc[4096];

	long nbrs[] = {
		0,
		100000,
		999999,
		900000,
		111111,
		CHAR_MAX,
		CHAR_MIN,
		INT_MAX,
		INT_MIN,
		LONG_MAX,
		LONG_MIN,
	};
	len = sizeof(nbrs) / sizeof(nbrs[0]);
	i = 0;
	error = 0;
	while (i < len)
	{
		sprintf(desc, "ft_itoa(%ld)", nbrs[i]);
		sprintf(exp, "%d", (int)nbrs[i]);
		res = ft_itoa(nbrs[i]);
		if (strcmp(exp, res))
		{
			msg_fail(desc, exp, res);
			error++;
		}
		else
			msg_pass(desc);
		i++;
	}
	msg_status("ft_itoa", error);
	printf("\n\n");
}
