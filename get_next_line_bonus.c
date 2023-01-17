/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkosemen <mkosemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:09:51 by mkosemen          #+#    #+#             */
/*   Updated: 2023/01/13 19:36:17 by mkosemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<fcntl.h>

#include "get_next_line_bonus.h" 

char	*ft_next_line(char *str)
{
	int		i;
	int		j;
	char	*buff;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (0);
	}
	buff = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	i++;
	if (!buff)
		return (NULL);
	j = 0;
	while (str[i])
		buff[j++] = str[i++];
	buff[j] = '\0';
	free(str);
	return (buff);
}

char	*ft_linechecker(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i] != '\n' && str[i])
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (0);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}	
	line[i] = '\0';
	return (line);
}

char	*ft_reader(int fd, char *str)
{
	char	*s;
	int		i;

	s = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	i = 1;
	while ((ft_strchr(str, '\n')) && i != 0)
	{
		i = read(fd, s, BUFFER_SIZE);
		if (i == -1)
		{	
			free(s);
			return (0);
		}
		s[i] = '\0';
		str = ft_strjoin(str, s);
	}
	free(s);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str[1024];
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str[fd] = ft_reader(fd, str[fd]);
	if (!str[fd])
		return (0);
	result = ft_linechecker(str[fd]);
	str[fd] = ft_next_line(str[fd]);
	return (result);
}
int main()
{
	int fd1;
	int fd2;

	char *a;
	char *b;

	fd1= open("a.txt",O_CREAT | O_RDWR ,0777);
	fd2= open("b.txt",O_CREAT| O_RDWR, 0777);

	a = get_next_line(fd1);
	b = get_next_line(fd2);

	while(a || b)
	{
		printf("%s",a);
		printf("%s",b);
		free(a);
		free(b);
		a = get_next_line(fd1);
		b = get_next_line(fd2);
	}
	
}