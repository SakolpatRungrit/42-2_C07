/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakrungr <sakrungr@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 14:20:11 by sakrungr          #+#    #+#             */
/*   Updated: 2026/11/24 15:56:38 by sakrungr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcat(char *dest, char *src)
{
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	char	*tmp;
	int		i;
	int		s_l;

	i = 0;
	s_l = 0;
	if (!size)
	{
		str = (char *)malloc(sizeof(char) * 1);
		*str = '\0';
		return (str);
	}
	while (i < size)
		s_l += ft_strlen(strs[i++]);
	str = (char *)malloc(s_l + ft_strlen(sep) * (size - 1) + 1);
	tmp = ft_strcat(str, strs[0]);
	i = 1;
	while (i < size)
	{
		tmp = ft_strcat(tmp, sep);
		tmp = ft_strcat(tmp, strs[i++]);
	}
	*tmp = '\0';
	return (str);
}
