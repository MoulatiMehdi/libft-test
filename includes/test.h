/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:03:50 by mmoulati          #+#    #+#             */
/*   Updated: 2024/11/10 09:53:12 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef TEST_H

# define TEST_H

# include "libft.h"
# include <ctype.h>
# include <limits.h>
# include <signal.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

# define RED "\x1b[1;31m"
# define BLUE "\x1b[1;36m"
# define GREEN "\x1b[1;32m"
# define YELLOW "\x1b[1;33m"
# define PURPLE "\x1b[1;35m"
# define REST "\x1b[0m"
# define GRAY "\x1b[1;90m"

# define CROSS "\u274c"
# define CHECK "\u2714"
# define PASS "\x1b[30;42m PASS \x1b[0m"
# define FAIL "\x1b[30;41m FAIL \x1b[0m"
# define TAB "\t"

void			msg_pass(char *str);
void			msg_fail(char *desc, char *expected, char *result);
void			msg_status(char *func_name, int state);

# define TEST_TIMEOUT 6
# define BUFFER_SIZE 4096

char			desc[BUFFER_SIZE];

typedef void	*(*t_func)();

void			report_test_result(int status);
int				run_test(t_func test_func, void *args);
char			*str_sig(int status);

#endif
