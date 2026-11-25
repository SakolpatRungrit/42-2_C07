/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakrungr <sakrungr@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 16:41:19 by sakrungr          #+#    #+#             */
/*   Updated: 2026/11/25 19:18:50 by sakrungr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	c_is_sep(char c, char *sep)
{
	int	i;

	i = 0;
	while (sep[i] != '\0')
	{
		if (c == sep[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && c_is_sep(str[i], charset))
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] && !(c_is_sep(str[i], charset)))
			i++;
	}
	return (count);
}

int	word_len(char *str, char *charset)
{
	int	len;

	len = 0;
	while (str[len] && !(c_is_sep(str[len], charset)))
		len++;
	return (len);
}

char	*dup_word(char *str, int len)
{
	char	*word;
	int		i;

	word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		i;
	int		w;
	int		len;

	result = (char **)malloc(sizeof(char *) * (count_words(str, charset) + 1));
	if (!result)
		return (NULL);
	i = 0;
	w = 0;
	while (str[i])
	{
		while (str[i] && c_is_sep(str[i], charset))
			i++;
		if (str[i])
		{
			len = word_len(str + i, charset);
			result[w] = dup_word(str + i, len);
			w++;
			i += len;
		}
	}
	result[w] = '\0';
	return (result);
}
