/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:09:34 by mmoulati          #+#    #+#             */
/*   Updated: 2024/11/08 13:59:21 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"
#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 4096

typedef struct s_args
{
	char	*s1;
	char	*s2;
	char	*expected;
}			t_args;

char		buffer[BUFFER_SIZE + 1];

void fill_desc(char *desc ,t_args* args)
{
	sprintf(desc, "ft_strjoin(");
	
	if(args->s1 == 0)
		sprintf(desc + strlen(desc),"NULL,");
	else
		sprintf(desc + strlen(desc),"\"%s\",", args->s1);
	
	if(args->s2 == 0)
		sprintf(desc + strlen(desc),"NULL)");
	else
		sprintf(desc + strlen(desc),"\"%s\")", args->s2);

}

void *test_custom(void *args)
{
	t_args	*p;

	p = (t_args *)args;
	return (ft_strjoin(p->s1, p->s2));
}

int	is_same_str(char *str, char *expected)
{
	int	i;

	i = 0;
	if (str == NULL || expected == NULL)
	{
		if (str != expected)
			printf("\t\t\tgot :%p expected :%p\n", str, expected);
		return (str == expected);
	}
	return strcmp(str,expected) == 0;
}


int	main(void)
{
	int		i;
	int		len;
	int		exp;
	int		error;
	char	desc[BUFFER_SIZE + 1];
	char	*str;
	char	*expected;

	error = 0;
	t_args args[] = {
		{
			.s2 = 0,
			.s1 = 0,
			.expected = 0,
		},
		{
			.s1 = 0,
			.s2 = "Hello",
			.expected = 0,
		},
		{
			.s1 = "Hello",
			.s2 = 0,
			.expected = 0,
		},
		{
			.s2 = "",
			.s1 = "Hello World",
			.expected = "Hello World",
		},
		{
			.s2 = "bbbbb",
			.s1 = "a",
			.expected = "abbbbb",
		},
		{
			.s1 = "ababab",
			.s2 = "bobobo",
			.expected = "abababbobobo",
		},
		{
			.s1 = "1337",
			.s2 = " Bengrier",
			.expected = "1337 Bengrier",
		},
	};
	len = sizeof(args) / sizeof(args[0]);
	i = 0;
	while (i < len)
	{
		fill_desc(desc,args + i);
		exp = run_test(test_custom, &args[i]);
		printf("\t");
		report_test_result(exp);
		printf(GRAY "    ===> %s \n", desc);
		if (exp != 0)
			error++;
		i++;
	}
	printf("\n");
	if (error == 0)
	{
		i = 3;
		while (i < len)
		{
			fill_desc(desc,args + i);
			expected = args[i].expected;
			str = test_custom(&args[i]);
			if (!is_same_str(str, expected))
			{
				error++;
				msg_fail(desc, expected, str);
			}
			else
				msg_pass(desc);
			i++;
		}
	}
	msg_status("ft_strjoin", error);
}
