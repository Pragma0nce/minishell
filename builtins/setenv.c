/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 11:08:11 by lchant            #+#    #+#             */
/*   Updated: 2017/09/25 15:21:58 by kcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int		list_len(t_env *list)
{
	int		i;
	t_env	*head;

	i = 1;
	head = list;
	while (list)
	{
		list = list->next;
		i++;
	}
	list = head;
	return (i);
}


char	**env_list_to_arr(t_env *list)
{
	t_env *itt;
	int i;
	int len;
	char **result;
	
	i = 0;
	itt = list;
	len = list_len(itt);
	result = (char**)malloc(sizeof(char*) * len);
	while (itt)
	{
		result[i++] = ft_strdup(itt->str);
		itt = itt->next;
	}
	return (result);
}

int		pos_equal(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '=' && str[i])
		i++;
	i++;
	return (i);
}

t_env	*ft_set_env(char *key, char *value, t_env *list)
{
	int		len;
	char	*join;
	char	*str;
	t_env	*head;
	t_env	*itt;

	itt = list;
	str = ft_addchar(key, '=');
	len = ft_strlen(key);
	head = list;
	while (itt->next != NULL)
	{
		if (ft_strncmp(itt->next->str, str, pos_equal(itt->next->str)) == 0)
		{
			join = ft_strjoin(str, value); 
			itt->next->str = ft_strdup(join);

			free(join);	
			free(str);
			free(value);
			return (list);
		}
		itt = itt->next;
	}

	itt->next = (t_env*)malloc(sizeof(t_env));
	join = ft_strjoin(str, value);
	itt->next->str = ft_strdup(join);
	itt->next->next = NULL;
	//fprintf(stderr, "ft_set_env: %s\n", itt->str);
	//list->next = (t_env*)malloc(sizeof(t_env));
	
	//list->next = (t_env*)malloc(sizeof(t_env));
	//list->str = ft_strdup(join);
	//list->next->next = NULL;
	//list->next = NULL;

	free(join);
	free(str);
	free(value);
	//debug_print_env_list(list);
	return (list);
}
int		run_builtin_setenv(t_command *command, char ***envp)
{
	char	*result;
	t_env	*list;

	list = ft_create_env_list(*envp); // freed		
	list = ft_set_env(command->args->str, command->args->next->str, list); // freed
	*envp = env_list_to_arr(list); 
	ft_free_list(list);	
	return (1);
}
