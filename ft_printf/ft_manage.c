/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 17:01:30 by nouhaddo          #+#    #+#             */
/*   Updated: 2018/11/15 20:27:50 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		check_parametre(t_prefix *pref, char *s)
{
	int i;

	i = 0;
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	if (s[i] == '$')
	{
		pref->para = ft_atoi(s);
		i++;
	}
	else
		pref->para = 0;
	return (i);
}

int		check_width(t_prefix *pref, char *s)
{
	int i;

	i = 0;
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	pref->parametre = ft_atoi(s);
	return (i);
}

int		check_precision(t_prefix *pref, char *s)
{
	int i;
	i = 0;
	pref->parametre = 0;
	if (s[i] == '.')
	{
		i++;
		while (s[i] >= '0' && s[i] <= '9')
			i++;
		pref->parametre = ft_atoi(&s[1]);
	}
	return (i);
}

int		check_type(t_prefix *pref, char *s)
{
	char p[];
	int i;
	int c;

	i = 0;
	p = "cspdiouxX";
	pref->size = 0
	if (s[i] == 'h')
	{
		pref->size = (s[++i] == 'h') ? (1) : (2);
		i += (s[i] == 'h') ? (1) : (0);
	}
	else if (s[i] == 'l')
	{
		pref->size = (s[++i] == 'h') ? (4) : (3);
		i += (s[i] == 'l') ? (1) : (0);
	}
	c = -1;
	while (p[++c])
		if (p[c] == s[i])
		{
			pref->type = c;
			return (i + 1);
		}
	return (-1);	
}

int		ft_reconize_flag(char *s)
{
	t_prefix pref;
	size_t i;
	int count;

	s += check_parametre(&pref, s);
	i = 0;
	while (*s == '#' || *s == '+' || *s == '-' || *s == ' ' || *s == '0')
		i++;
	pref.flag = ft_strndup(s, i);
	s += check_width(&pref, s);
	s += check_precision(&pref, s);
	s += check_precision(&pref, s);
	s += check_type(&pref, s);
}