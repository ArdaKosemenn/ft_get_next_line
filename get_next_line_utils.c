/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkosemen <mkosemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:54:46 by mkosemen          #+#    #+#             */
/*   Updated: 2023/01/10 18:30:27 by mkosemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*hamper;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	i = 0;
	j = 0;
	if (!s2)
		return (0);
	hamper = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!hamper)
		return (0);
	while (s1[i] != '\0')
		hamper[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		hamper[j++] = s2[i++];
	hamper[j] = '\0';
	free (s1);
	return (hamper);
}

int	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	while (str[i])
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}
