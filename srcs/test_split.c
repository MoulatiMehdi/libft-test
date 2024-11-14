/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:09:34 by mmoulati          #+#    #+#             */
/*   Updated: 2024/11/14 18:34:31 by mmoulati         ###   ########.fr       */
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
	char	*str;
	int		c;
	char	**expected;
}			t_args;

char		buffer[BUFFER_SIZE + 1];

void	fill_desc(char *desc, t_args *args)
{
	sprintf(desc, "ft_split(");
	if (args->str == 0)
		sprintf(desc + strlen(desc), "NULL,");
	else
		sprintf(desc + strlen(desc), "\"%s\",", args->str);
	if (isprint(args->c))
		sprintf(desc + strlen(desc), "'%c')", args->c);
	else
		sprintf(desc + strlen(desc), "%d)", args->c);
}

char	**make_strs(int count, ...)
{
	char		**strs;
	va_list		args;
	const char	*arg;

	if (count == 0)
	{
		return (NULL);
	}
	strs = malloc(sizeof(char *) * (count + 1));
	if (!strs)
		return (NULL);
	va_start(args, count);
	for (int i = 0; i < count; i++)
	{
		arg =  va_arg(args, const char *);
		strs[i] = arg ? strdup(arg) : NULL;
	}
	strs[count] = NULL;
	va_end(args);
	return (strs);
}

void	free_strs(char **strs)
{
	if (strs)
	{
		for (int i = 0; strs[i] != NULL; i++)
		{
			free(strs[i]);
		}
		free(strs);
	}
}

void	*test_custom(void *args)
{
	t_args	*p;

	p = (t_args *)args;
	return (ft_split(p->str, p->c));
}

int	is_same_strs(char **strs, char **expected)
{
	int	i;

	i = 0;
	if (strs == NULL || expected == NULL)
	{
		return (strs == expected);
	}
	while (strs[i] != NULL || expected[i] != NULL)
	{
		if (strs[i] == NULL || expected[i] == NULL)
			return (strs[i] == expected[i]);
		if (strcmp(strs[i], expected[i]) != 0)
			return (0);
		i++;
	}
	return (1);
}

char	*strs_to_str(char **strs)
{
	int	i;

	memset(buffer, 0, BUFFER_SIZE);
	printf("%s\n", buffer);
	if (!strs)
		return ("0");
	else
	{
		i = 0;
		while (strs[i])
		{
			strcat(buffer, "\"");
			strcat(buffer, strs[i]);
			strcat(buffer, "\" -> ");
			i++;
		}
		if (!strs[i])
		{
			strcat(buffer, "\"(NULL)\"");
		}
		return (buffer);
	}
}

int	main(void)
{
	int		i;
	int		len;
	int		res;
	int		error;
	char	desc[BUFFER_SIZE + 1];
	char	**strs;
	char	**expected;

	error = 0;
	t_args args[] = {
		{
			.c = 1,
			.str = 0,
			.expected = 0,
		},
		{
			.c = 1,
			.str = "",
			.expected = make_strs(1, 0),
		},
		{
			.c = 1,
			.str = "Hello World",
			.expected = make_strs(1, "Hello World"),
		},
		{
			.c = 1,
			.str = "a",
			.expected = make_strs(1, "a"),
		},
		{
			.c = -128,
			.str = "Hello\200world",
			.expected = make_strs(2, "Hello", "world"),
		},
		{
			.c = 'a',
			.str = "aaaaaaaaaaaaaaa",
			.expected = make_strs(1, 0),
		},
		{
			.c = 'b',
			.str = "aaaabaaaa",
			.expected = make_strs(2, "aaaa", "aaaa"),
		},
		{
			.c = 'b',
			.str = "abbaabbaaabbbbaaaa",
			.expected = make_strs(4, "a", "aa", "aaa", "aaaa"),
		},
		{
			.c = '\0',
			.str = "abbaabba\0abbbbaaaa",
			.expected = make_strs(1, "abbaabba"),
		},
		{
			.c = '\200',
			.str = "abbaabba\200abbbbaaaa",
			.expected = make_strs(2, "abbaabba", "abbbbaaaa"),
		},
	};
	len = sizeof(args) / sizeof(args[0]);
	i = 0;
	while (i < len)
	{
		i++;
	}
	printf("\n");
	if (error == 0)
	{
		i = 0;
		while (i < len)
		{
			expected = args[i].expected;
			fill_desc(desc, args + i);
			res = run_test(test_custom, &args[i]);
			if (res != 0)
			{
				msg_fail(desc, str_sig(0), str_sig(res));
				error++;
			}
			else
			{
				strs = test_custom(&args[i]);
				if (!is_same_strs(strs, expected))
				{
					error++;
					msg_fail(desc, strs_to_str(expected), strs_to_str(strs));
				}
				else
					msg_pass(desc);
			}
			i++;
		}
	}
	msg_status("ft_split", error);
}
