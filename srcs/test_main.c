/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:06:46 by mmoulati          #+#    #+#             */
/*   Updated: 2024/11/12 21:34:50 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "test.h"
#include <stdlib.h>
#include <string.h>

typedef struct
{
	void	*s1;
	void	*s2;
	size_t	len;
}			t_args;

void	*ft_strlcat_wrapper(void *args)
{
	t_args	*params;

	params = args;
	ft_strlcat(params->s1, params->s2, params->len);
	return (0);
}
void	*ft_strlcpy_wrapper(void *args)
{
	t_args	*params;

	params = args;
	ft_strlcpy(params->s1, params->s2, params->len);
	return (0);
}

void	*ft_memmove_wrapper(void *args)
{
	t_args	*params;

	params = args;
	ft_memmove(params->s1, params->s2, params->len);
	return (0);
}
void	*ft_memcpy_wrapper(void *args)
{
	t_args	*params;

	params = args;
	ft_memcpy(params->s1, params->s2, params->len);
	return (0);
}
void	*strlcat_wrapper(void *args)
{
	t_args	*params;

	params = args;
	strlcat(params->s1, params->s2, params->len);
	return (0);
}
void	*strlcpy_wrapper(void *args)
{
	t_args	*params;

	params = args;
	strlcpy(params->s1, params->s2, params->len);
	return (0);
}

void	*memmove_wrapper(void *args)
{
	t_args	*params;

	params = args;
	memmove(params->s1, params->s2, params->len);
	return (0);
}
void	*memcpy_wrapper(void *args)
{
	t_args	*params;

	params = args;
	memcpy(params->s1, params->s2, params->len);
	return (0);
}

int	main(void)
{
	int		len;
	t_args	args;
	int		i;
	int		res;
	int		exp;
	char	*s;
	int		error;

	s = "alo";
	i = 0;
	args.s1 = s;
	args.s2 = s;
	args.len = 50;
	char *names[] = {
		"memmove",
		"memcpy",
		"strlcat",
		"strlcpy",
	};
	t_func f[][2] = {
		{memmove_wrapper, ft_memmove_wrapper},
		{memcpy_wrapper, ft_memcpy_wrapper},
	};
	len = sizeof(f) / sizeof(f[0]);
	error = 0;
	while (i < len)
	{
		exp = run_test(f[i][0], &args);
		res = run_test(f[i][1], &args);
		sprintf(desc, "%s(\"%s\",\"%s\",%lu)", names[i], args.s1, args.s2,
			args.len);
		if (exp != res)
		{
			msg_fail(desc, str_sig(exp), str_sig(res));
			error++;
		}
		else
			msg_pass(desc);
		i++;
	}
	msg_status("Special Tests (Bus Error)", error);
}
