/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 11:56:27 by lchant            #+#    #+#             */
/*   Updated: 2017/09/18 11:56:28 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
** 27 lines needs 2 less
*/

char	*remove_quotes(char *str)
{
	int		i;
	int		j;
	int		size;
	char	*new_str;

	i = 0;
	size = 0;
	while (str[i])
	{
		if (str[i] == '"')
			size++;
		i++;
	}
	new_str = (char*)malloc(sizeof(char) * (ft_strlen(str) - size));
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != '"')
		{
			new_str[j] = str[i];
			j++;
		}
		i++;
	}
	free(str);
	return (new_str);
}
