/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yijin <yijin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 19:07:43 by yijin             #+#    #+#             */
/*   Updated: 2022/07/23 19:08:53 by yijin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strcomp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_strlen(char *src)
{
	char	*start;

	start = src;
	while (*src)
		src++;
	return (src - start);
}

char	*ft_strcat(char *dest, char *src)
{
	char	*st;

	st = dest;
	while (*dest)
		dest++;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	return (st);
}

int	ft_allocated_memo(int size, char **strs, char *sep)
{
	int	num;
	int	i;

	i = 0;
	num = 0;
	while (i < size)
	{
		num += ft_strlen(*(strs + i));
		i++;
	}
	num = num + (size - 1) * ft_strlen(sep) + 1;
	return (num);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	int		i;
	int		num;

	if (size == 0)
		return (NULL);
	i = 0;
	num = ft_allocated_memo(size, strs, sep);
	res = malloc(sizeof(*res) * num);
	res[0] = '\0';
	i = 0;
	while (i < size)
	{
		res = ft_strcat(res, *(strs + i));
		if (i != (size - 1))
			res = ft_strcat(res, sep);
		i++;
	}
	res[num] = '\0';
	return (res);
}
