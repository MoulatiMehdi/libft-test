/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 11:40:25 by mmoulati          #+#    #+#             */
/*   Updated: 2024/11/10 12:00:10 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"

void	*lstnew_wrapper(void *content)
{
	return (ft_lstnew(content));
}

int	main(void)
{
	t_list		*p;
	int			size;
	int			error;
	int			errors;
	extern char	desc[];
	int			i;
	int			status;

	error = 0;
	errors = 0;
	char *strs[] = {
		NULL,
		"Hello",
		"\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0a",
	};
	size = sizeof(strs) / sizeof(strs[0]);
	i = 0;
	while (i < size)
	{
		if (strs[i])
			sprintf(desc, "ft_lstnew(\"%s\")", strs[i]);
		else
			sprintf(desc, "ft_lstnew(NULL)");
		status = run_test(lstnew_wrapper, strs[i]);
		if (status != 0)
		{
			msg_fail(desc, str_sig(0), str_sig(status));
		}
		else
		{
			p = lstnew_wrapper(strs[i]);
			if (p == 0)
			{
				msg_fail(desc, "No Null", "Null");
				errors++;
			}
			else if (p->content != strs[i])
			{
				msg_fail(desc, strs[i], p->content);
				errors++;
			}
			else if (p->next != 0)
			{
				msg_fail(desc, "Null", "No Null");
				errors++;
			}
			else
				msg_pass(desc);
		}
		i++;
	}
	msg_status("ft_lstnew", errors);
}
