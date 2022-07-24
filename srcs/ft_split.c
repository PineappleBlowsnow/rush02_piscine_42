/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yijin <yijin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 19:36:09 by yijin             #+#    #+#             */
/*   Updated: 2022/07/23 19:36:11 by yijin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	char	*end;

	end = str;
	while (*end)
		end++;
	return (end - str);
}

int	check_char_is_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (check_char_is_charset(*str, charset))
		{
			while (check_char_is_charset(*str, charset))
				str++;
		}
		if (!check_char_is_charset(*str, charset) && *str)
		{
			count++;
			while (!check_char_is_charset(*str, charset) && *str)
				str++;
		}
	}
	return (count);
}

char	*get_every_word(char *str, char *charset)
{
	char	*start;
	int		length;
	char	*word;
	int		i;

	i = 0;
	while (check_char_is_charset(*str, charset))
		str++;
	start = str;
	while (!check_char_is_charset(*str, charset) && *str)
		str++;
	length = str - start;
	word = malloc(sizeof(*word) * (length + 1));
	str = start;
	while (i < length)
	{
		word[i] = *str;
		i++;
		str++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	int		words;
	char	**res;
	int		index;

	words = count_words(str, charset);
	res = malloc(sizeof(*res) * (words + 1));
	index = 0;
	while (index < words)
	{
		res[index] = get_every_word(str, charset);
		while (check_char_is_charset(*str, charset))
			str++;
		str = str + ft_strlen(get_every_word(str, charset));
		index++;
	}
	res[index] = 0;
	return (res);
}
