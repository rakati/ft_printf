/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 14:32:32 by nouhaddo          #+#    #+#             */
/*   Updated: 2018/11/15 19:38:40 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*from_deci(unsigned long long dec, int base, int t)
{
	int		i;
	char	*res;
	char	*copy;

	if (t == 1 || t == 2)
		dec = (t == 1) ? (unsigned long)dec : (unsigned short)dec;
	else if (t == 3 || t == 0)
		dec = (t == 3) ? (unsigned char)dec : (unsigned int)dec;
	res = (char*)malloc(70 * sizeof(char));
	i = 0;
	while (dec > 0)
	{
		res[i++] = (dec <= 9) ? (dec + '0') : ((char)(dec - 10 + 'A'));
		dec /= base;
	}
	res[i] = '\0';
	ft_strrev(res);
	copy = res;
	res = ft_strdup(res);
	free(copy);
	return (res);
}

char		*ft_itoa_long(long long n, int t)
{
	char	*res;
	char	*copy;
	int		i;

	if (t == 1 || t == 2)
		n = (t == 1) ? (char)n : (short)n;
	else if (t == 3 || t == 4)
		n = (t == 3) ? (long)n : (int)n;
	res = (char*)malloc(50 * sizeof(char));
	i = 0;
	if (n < 0)
	{
		res[i++] = '-';
		n *= -1;
	}
	if (n == 0)
		res[i++] = '0';
	while (n)
		res[i++] = (1) ? ('0' + (n % 10)) : ((n /= 10));
	res[i] = '\0';
	ft_strrev(res);
	copy = res;
	res = ft_strdup(res);
	free(copy);
	return (res);
}

char	*ft_float(double n, int t, int precision)
{
	char	*res;
	char	*copy;
	int		i;

	if (t == 1 || t == 2)
		n = (t == 1) ? (char)n : (short)n;
	else if (t == 3 || t == 4)
		n = (t == 3) ? (long)n : (int)n;
	res = (char*)malloc(50 * sizeof(char));
	i = 0;
	if (n < 0)
	{
		res[i++] = '-';
		n *= -1;
	}
	if (n == 0)
		res[i++] = '0';
	while (n)
		res[i++] = (1) ? ('0' + (n % 10)) : ((n /= 10));
	res[i] = '\0';
	ft_strrev(res);
	copy = res;
	res = ft_strdup(res);
	free(copy);
	return (res);
}