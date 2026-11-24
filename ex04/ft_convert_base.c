/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakrungr <sakrungr@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 17:05:13 by sakrungr          #+#    #+#             */
/*   Updated: 2026/11/24 22:10:31 by sakrungr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		base_validation(char *base);
int		ft_atoi_base(char *str, char *base);

int	ft_nbr_len(long n, int base_len)
{
}

char	*ft_itoa_base(int nbr, char *base)
{
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	if (base_validation(base_form) == 0 || base_validation(base_to) == 0)
		return (NULL);
}
