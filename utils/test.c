/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:04:06 by mmoulati          #+#    #+#             */
/*   Updated: 2024/11/10 09:53:41 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "test.h"

void	report_test_result(int status)
{
	printf("%6s" REST, str_sig(status));
}

char	*str_sig(int status)
{
	char	*p;

	switch (status)
	{
	case SIGSEGV:
		p = "[SIGSEG]";
		break ;
	case SIGABRT:
		p = "[SIGABR]";
		break ;
	case SIGBUS:
		p = "[SIGBUS]";
		break ;
	case SIGALRM:
		p = "[SIGALR]";
		break ;
	case 0:
		p = "[NORMAL]";
		break ;
	case -1:
		p = "[FAILED]";
		break ;
	default:
		p = "[UKNOWN]";
	}
	return (p);
}

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
