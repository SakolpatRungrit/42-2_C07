/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakrungr <sakrungr@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 17:05:13 by sakrungr          #+#    #+#             */
/*   Updated: 2026/11/25 16:36:54 by sakrungr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		base_validation(char *base);
int		ft_atoi_base(char *str, char *base);

int	ft_nbr_len(long n, int base_len)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len = 1;
		n *= -1;
	}
	while (n > 0)
	{
		n = n / base_len;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(int nbr, char *base)
{
	char	*str;
	int		len;
	int		base_len;
	long	n;

	n = nbr;
	base_len = base_validation(base);
	len = ft_nbr_len(n, base_len);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str[0] = base[0];
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	str[len] = '\0';
	while (n > 0)
	{
		len--;
		str[len] = base[n % base_len];
		n = n / base_len;
	}
	return (str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	n;

	if (base_validation(base_from) == 0 || base_validation(base_to) == 0)
		return (NULL);
	n = ft_atoi_base(nbr, base_from);
	return (ft_itoa_base(n, base_to));
}
