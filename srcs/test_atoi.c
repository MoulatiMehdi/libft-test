/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:32:18 by mmoulati          #+#    #+#             */
/*   Updated: 2024/11/09 23:56:25 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "test.h"

char	desc[4096];
int	test_atoi(const char *str)
{
	char	res[30];
	char	exp[30];
	int		test;

	sprintf(exp, "%d", atoi(str));
	sprintf(res, "%d", ft_atoi(str));
	test = (strcmp(exp, res) == 0);
	sprintf(desc,"ft_atoi(\"%s\")", str);
	if (!test)
		msg_fail(desc, exp, res);
	else
		msg_pass(desc);
	return (test);
}

void	*atoi_wrapper(void *str)
{
	atoi((char *)str);
	return (0);
}

void	*ft_atoi_wrapper(void *str)
{
	atoi((char *)str);
	return (0);
}

int	main(void)
{
	int	i;
	int	size;
	int	error;
	int	exp;
	int	res;

	error = 0;
	char *strs[] = {
		0,
		"0",
		"",
		"-",
		"+",
		"+-",
		"-+",
		"++",
		"--",
		"0000000002147483647",
		"\x08 0000000002147483647",
		"\x09\x0a\x0b\x0c\x0d 2147483647",
		"2147483648",
		"2147483648",
		"-2147483648",
		"9223372036854775806",
		"9223372036854775807", // LONG_MAX
		"9223372036854775808",
		"-9223372036854775806",
		"-9223372036854775807",
		"-9223372036854775808", // LONG_MIN
		"-22233720368547758090",
		"22233720368547758090",
		"111111111111111111l",
		"1000000000000000000l",
		"-111111111111111111l",
		"1111111111111111111l",
		"11111111111111111111l",
		"-1111111111111111111l",
		"-11111111111111111111l",
		"100000000000000000000l",
		"1111111111111111111111111111111111111111111111111",
		"-1111111111111111111111111111111111111111111111111",
	};
	size = sizeof(strs) / sizeof(strs[0]);
	i = 0;
	while (i < size)
	{
		exp = run_test(atoi_wrapper, strs[i]);
		res = run_test(ft_atoi_wrapper, strs[i]);
		if (res != exp)
		{
			printf("\t");
			report_test_result(exp);
			printf("\t");
			report_test_result(res);
			printf("\t");
			sprintf(desc,"ft_atoi(\"%s\")", strs[i]);
			printf("%s\n", desc);
			getchar();
		}
		i++;
	}
	i = 1;
	while (i < size)
	{
		if (!test_atoi(strs[i]))
			error++;
		i++;
	}
	msg_status("ft_atoi", error);
}
