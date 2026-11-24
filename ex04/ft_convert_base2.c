/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakrungr <sakrungr@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 16:54:38 by sakrungr          #+#    #+#             */
/*   Updated: 2026/11/24 16:59:58 by sakrungr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	base_validation(char *base)
{
	long	i;
	long	s_i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		if (base[i] <= 32 || base[i] >= 127)
			return (0);
		s_i = i + 1;
		while (base[s_i])
		{
			if (base[i] == base[s_i])
				return (0);
			s_i++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	return (i);
}

int	ft_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int		i;
	int		sign;
	long	sum;
	int		base_l;

	i = 0;
	sum = 0;
	sign = 1;
	base_l = base_validation(base);
	if (base_l == 0)
		return (0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_index(str[i], base) != -1)
	{
		sum = sum * base_l + ft_index(str[i], base);
		i++;
	}
	return (sum * sign);
}
