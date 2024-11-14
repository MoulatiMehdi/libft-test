/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_striteri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:09:34 by mmoulati          #+#    #+#             */
/*   Updated: 2024/11/08 22:52:44 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 4096

typedef struct s_args
{
	char	*s1;
	void	(*func)(unsigned, char *);
}			t_args;

char		buffer[BUFFER_SIZE + 1];

void	fill_desc(char *desc, t_args *args)
{
	sprintf(desc, "ft_striteri(");
	if (args->s1 == 0)
		sprintf(desc + strlen(desc), "NULL,");
	else
		sprintf(desc + strlen(desc), "\"%s\",", args->s1);
	if (args->func == 0)
		sprintf(desc + strlen(desc), "NULL)");
	else
		sprintf(desc + strlen(desc), "\"%p\")", args->func);
}

void	*test_custom(void *args)
{
	t_args	*p;

	p = (t_args *)args;
	ft_striteri(p->s1, p->func);
	return (0);
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
	return (strcmp(str, expected) == 0);
}

void	func_test(unsigned int c, char *s)
{
	buffer[c] = *s;
}

int	main(void)
{
	int		i;
	int		len;
	int		exp;
	int		error;
	char	desc[BUFFER_SIZE + 1];
	char	*expected;

	error = 0;
	t_args args[] = {
		{
			.func = 0,
			.s1 = "Hello World",
		},
		{
			.func = func_test,
			.s1 = 0,
		},
		{
			.func = 0,
			.s1 = 0,
		},
		{
			.s1 = "Hello",
			.func = func_test,
		},
		{
			.s1 = "Hello World",
			.func = func_test,
		},
		{
			.s1 = ",,,,Hell,o,,,,Worl,d,,,,,,,",
			.func = func_test,
		},
		{
			.s1 = "Hello World",
			.func = func_test,
		},
		{
			.s1 = "aaaaaaaaaaaaaaaaaaaaaaa____hello world",
			.func = func_test,
		},
		{
			.s1 = "abcdefghijklmnopqrstuvwxyz____hello world",
			.func = func_test,
		},
	};
	len = sizeof(args) / sizeof(args[0]);
	i = 0;
	while (i < len)
	{
		fill_desc(desc, args + i);
		exp = run_test(test_custom, &args[i]);
		printf("\t");
		str_sig(exp);
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
			fill_desc(desc, args + i);
			expected = args[i].s1;
			test_custom(&args[i]);
			buffer[strlen(expected ? expected : "")] = 0;
			if (!is_same_str(buffer, expected))
			{
				error++;
				msg_fail(desc, expected, buffer);
			}
			else
				msg_pass(desc);
			i++;
		}
	}
	msg_status("ft_striteri", error);
}
