/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:55:25 by jmeruma           #+#    #+#             */
/*   Updated: 2023/09/21 11:55:26 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	len_till_quote(char *line, int index, char c)
{
	int	len;

	len = 1;
	while (line[index + len] != c && line[index + len])
		len++;
	if (line[index + len] != '\0')
		return (len);
	return (0);
}

int	how_many_quotes(char *line)
{
	int	index;
	int	len;
	int	quotes;

	quotes = 0;
	index = 0;
	while (line[index])
	{
		if (line[index] == '\"' || line[index] == '\'')
		{
			len = len_till_quote(line, index, line[index]);
			index += len;
			if (len != 0)
				quotes++;
			if (line[index])
				return (quotes * 2);
		}
		index++;
	}
	return (quotes * 2);
}

void	destroy_quotes(char *line, char *new_line, int length, int index)
{
	char	c;

	while (line[length])
	{
		if ((line[length] == '\"' || line[length] == '\'') \
			&& len_till_quote(line, length, line[length]) != 0)
		{
			c = line[length];
			length++;
			while (line[length] != c)
			{
				new_line[index] = line[length];
				index++;
				length++;
			}
			length++;
		}
		else
		{
			new_line[index] = line[length];
			index++;
			length++;
		}
	}
}

char	*create_string(char *line)
{
	int		length;
	char	*new_line;
	int		amount_quotes;

	length = ft_strlen(line);
	amount_quotes = how_many_quotes(line);
	new_line = ft_calloc((length - amount_quotes) + 1, sizeof(char));
	if (!new_line)
		return (NULL);
	destroy_quotes(line, new_line, 0, 0);
	return (new_line);
}

int	remove_quotes(t_lexer **lexer)
{
	t_lexer	*node;
	char	*new_line;

	node = *lexer;
	while (node != NULL)
	{
		new_line = create_string(node->argument);
		if (!new_line)
			return (ERROR);
		free(node->argument);
		node->argument = new_line;
		node = node->next;
	}
	return (SUCCES);
}
