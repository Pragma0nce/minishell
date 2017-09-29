/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 11:07:38 by lchant            #+#    #+#             */
/*   Updated: 2017/09/25 15:40:17 by kcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

t_env		*ft_unset_env(char *key, t_env *list)
{
	int		len;
	t_env	*head;
	t_env	*temp;

	head = list;
	len = ft_strlen(key);
	while (list->next != NULL)
	{
		if (list->next->str == NULL)
			return (head);
		if (ft_strncmp(list->next->str, key, len) == 0)
		{
			temp = list->next;
			list->next = list->next->next;
			free(temp->str);
			free(temp);
			return (head);
		}
		list = list->next;
	}
	return (head);
}

int			run_builtin_unsetenv(t_command *command)
{
	g_shell.env_list = ft_unset_env(command->args->str, g_shell.env_list);
	return (1);
}
