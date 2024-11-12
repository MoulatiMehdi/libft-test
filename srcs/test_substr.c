/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_substr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:09:34 by mmoulati          #+#    #+#             */
/*   Updated: 2024/11/12 17:04:59 by mmoulati         ###   ########.fr       */
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
	char			*s1;
	unsigned int	start;
	size_t			end;
	char			*expected;
}					t_args;

char				buffer[BUFFER_SIZE + 1];

void	fill_desc(char *desc, t_args *args)
{
	int	len;

	sprintf(desc, "ft_substr(");
	len = strlen(desc);
	if (args->s1 == 0)
	{
		sprintf(desc + len, "NULL");
		len += 4;
	}
	else
	{
		sprintf(desc + len, "\"%s\"", args->s1);
		len += strlen(args->s1) + 2;
	}
	sprintf(desc + len, ",%u,%lu)", args->start, args->end);
}

void	*test_custom(void *args)
{
	t_args	*p;

	p = (t_args *)args;
	return (ft_substr(p->s1, p->start, p->end));
}

int	is_same_str(char *str, char *expected)
{
	int	i;

	i = 0;
	if (str == NULL || expected == NULL)
		return (str == expected);
	return (strcmp(str, expected) == 0);
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
			.start = 0,
			.end = 0,
			.s1 = 0,
			.expected = 0,
		},
		{
			.s1 = "Hello",
			.start = 0,
			.end = 0,
			.expected = "",
		},
		{
			.s1 = "Hello",
			.start = 4,
			.end = 1,
			.expected = "o",
		},
		{
			.start = 1,
			.end = 5,
			.s1 = "Hello World",
			.expected = "ello ",
		},
		{
			.start = UINT_MAX,
			.end = LONG_MAX,
			.s1 = "Hello World",
			.expected = "",
		},
		{
			.s1 = "HELLO WORLD",
			.start = 1,
			.end = 1,
			.expected = "E",
		},
		{
			.s1 = "1337",
			.start = 0,
			.end = 4,
			.expected = "1337",
		},

		{
			.s1 = "Hello",
			.start = -1,
			.end = 0,
			.expected = "",
		},
		{
			.s1 = "Hello",
			.start = 0,
			.end = -1,
			.expected = "Hello",
		},
	};
	len = sizeof(args) / sizeof(args[0]);
	i = 0;
	while (i < len)
	{
		exp = run_test(test_custom, &args[i]);
		fill_desc(desc, args + i);
		if (exp != 0)
		{
			msg_fail(desc, str_sig(0), str_sig(exp));
			error++;
		}
		else
		{
			expected = args[i].expected;
			str = test_custom(&args[i]);
			if (!is_same_str(str, expected))
			{
				error++;
				msg_fail(desc, expected, str);
			}
			else
				msg_pass(desc);
		}
		i++;
	}
	msg_status("ft_substr", error);
}
