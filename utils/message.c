/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:03:29 by mmoulati          #+#    #+#             */
/*   Updated: 2024/11/12 16:06:03 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	print_all(char *str)
{
	int		i;
	char	*base;

	base = "0123456789ABCDEF";
	if (!str)
	{
		printf("(null)");
		return ;
	}
	i = 0;
	while (str[i])
	{
		if (isprint(str[i]))
			printf("%c", str[i]);
		else
		{
			printf("\\x%02x", str[i]);
		}
		i++;
	}
}

void	msg_pass(char *str)
{
	printf("\t" GREEN CHECK GRAY "  ");
	print_all(str);
	printf(REST "\n");
}

void	msg_fail(char *desc, char *expected, char *result)
{
	printf("\t" RED CROSS GRAY " ");
	print_all(desc);
	printf("\n");
	printf("\t\tExpected : ");
	print_all(expected);
	printf("\n");
	printf("\t\tGOT      : ");
	print_all(result);
	printf("\n" REST);
}

void	msg_status(char *func_name, int errors)
{
	printf("\n");
	printf(errors ? FAIL : PASS);
	printf(PURPLE " ");
	printf("");
	print_all(func_name);
	printf("\n\x1b[1;35m__________________________________________________________\n" REST);
	printf(" \n" REST);
}
