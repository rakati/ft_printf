/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 13:51:28 by nouhaddo          #+#    #+#             */
/*   Updated: 2018/11/15 19:57:54 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*ft_strndup(char *src, size_t len)
{
	char *res;

	len++;
	res = (char*)malloc(len * sizeof(char));
	res[--len] = '\0';
	while (--len)
		res[len] = src[len];
	return (res);
}

t_result	*ft_copie_until_flag(char *src)
{
	int i;
	t_result *result;

	i = -1;
	while (src[++i])
		if (src[i] == '%')
			if (src[i + 1] == '%')
				break ;
	result = (t_result*)malloc(sizeof(t_result));
	result.len = i;
	result.res = ft_strndup(src, i);
	return (result);
}

int		ft_printf(const char *format, ...)
{
	char *res;
	char *to_manage;
	t_result result;
	size_t count;
	va_list params;

	to_manage = (char*)format;
	count = 0;
	va_start(params, format);
	while (*to_manage)
	{
		/* copie string to_manage until %followed by flags*/
		result = ft_copie_until_flag(to_manage);
		/* add nbr reads to counter*/
		count += result.len;
		/*join result string to res and free memory*/
		res = ft_strjoin(res, result.res);
		free(result.res);
		free(result);
		/*incream to_manage by nbr of char copied */
		to_manage += result.len;
		/**/
		result = ft_manage()
	}
	va_end(params);
	return (ft_strlen(managed));
}