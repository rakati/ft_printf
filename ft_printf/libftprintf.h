/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 01:29:55 by nouhaddo          #+#    #+#             */
/*   Updated: 2018/11/15 19:40:20 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>

typedef struct	t_prefix
{
	int para;
	char *flag;
	int width;
	int precision;
	int size;
	char type;
	
}				s_prefix;

typedef struct t_result
{
	int len;
	char *res;
}				s_result;

void	ft_strrev(char *str);

#endif
