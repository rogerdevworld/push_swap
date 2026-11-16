/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 18:45:00 by student           #+#    #+#             */
/*   Updated: 2026/11/16 18:45:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	count_words(char *s, char c)
{
	int		count;
	bool	in_word;

	count = 0;
	while (*s)
	{
		in_word = false;
		while (*s == c)
			++s;
		while (*s != c && *s)
		{
			if (!in_word)
			{
				++count;
				in_word = true;
			}
			++s;
		}
	}
	return (count);
}

static char	*get_next_word(char *s, char c, int *cursor)
{
	char	*word;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (s[*cursor] == c)
		++(*cursor);
	while ((s[*cursor + len] != c) && s[*cursor + len])
		++len;
	word = malloc((size_t)len * sizeof(char) + 1);
	if (!word)
		return (NULL);
	while ((s[*cursor] != c) && s[*cursor])
		word[i++] = s[(*cursor)++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *s, char c)
{
	int		words;
	char	**res;
	int		i;
	int		cursor;

	i = 0;
	cursor = 0;
	words = count_words(s, c);
	if (!words)
		return (NULL);
	res = malloc(sizeof(char *) * (size_t)(words + 1));
	if (!res)
		return (NULL);
	while (words-- > 0)
		res[i++] = get_next_word(s, c, &cursor);
	res[i] = NULL;
	return (res);
}
