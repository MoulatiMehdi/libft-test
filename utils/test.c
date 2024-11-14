/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:04:06 by mmoulati          #+#    #+#             */
/*   Updated: 2024/11/14 12:11:16 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "test.h"


int	run_test(t_func test_func, void *args)
{
	pid_t	pid;
	int		status;
	int		sig;

	fflush(stdout);
	pid = fork();
	if (pid == -1)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		alarm(TEST_TIMEOUT);
		test_func(args);
		exit(0);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
			return (0);
		else if (WIFSIGNALED(status))
		{
			sig = WTERMSIG(status);
			return (sig);
		}
		else
			return (-1);
	}
}
