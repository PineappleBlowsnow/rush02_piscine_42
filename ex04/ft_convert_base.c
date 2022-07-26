/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yijin <yijin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 19:17:09 by yijin             #+#    #+#             */
/*   Updated: 2022/07/23 19:17:11 by yijin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);
int	ft_isspace(char c);
int	ft_base_is_not_ok(char *base);

int	ft_find_index(char c, char *base)
{
	int	i;

	i = 0;
	while (i < ft_strlen(base))
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *nbr, char *base_from)
{
	int	count_minus;
	int	nb;

	count_minus = 1;
	while (ft_isspace(*nbr))
		nbr++;
	while ((*nbr == '+') || (*nbr == '-'))
	{
		if (*nbr == '-')
			count_minus *= -1;
		nbr++;
	}
	nb = 0;
	while ((ft_find_index(*nbr, base_from) != -1) && (*nbr))
	{
		nb = nb * ft_strlen(base_from) + count_minus
			* (ft_find_index(*nbr, base_from));
		nbr++;
	}
	return (nb);
}

void	ft_putnbr_base(int nbr, char *base_to, int ind, char *str)
{
	long long int	nbr1;

	nbr1 = nbr;
	if (nbr1 < 0)
	{
		nbr1 = -nbr1;
		str[0] = '-';
	}
	if (nbr1 / ft_strlen(base_to))
		ft_putnbr_base(nbr1 / ft_strlen(base_to), base_to, ind - 1, str);
	str[ind] = *(base_to + nbr1 % ft_strlen(base_to));
}

char	*ft_remove_plus(char *str)
{
	int	i;

	i = 1;
	if (str[0] == '+')
	{
		while (i < ft_strlen(str))
		{
			str[i - 1] = str[i];
			i++;
		}
		str[i - 1] = '\0';
		return (str);
	}
	else
		return (str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb;
	int		temp;
	int		size;
	char	*str;

	if (ft_base_is_not_ok(base_from) || ft_base_is_not_ok(base_to))
		return (NULL);
	nb = ft_atoi_base(nbr, base_from);
	temp = nb;
	size = 2;
	while (nb)
	{
		size++;
		nb = nb / ft_strlen(base_to);
	}
	str = malloc(sizeof(*str) * size);
	str[0] = '+';
	str[size - 1] = '\0';
	ft_putnbr_base(temp, base_to, size - 2, str);
	return (ft_remove_plus(str));
}
