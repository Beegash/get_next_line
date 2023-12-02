/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iozmen <iozmen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:25:15 by iozmen            #+#    #+#             */
/*   Updated: 2023/12/02 18:20:59 by iozmen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_readlines(int fd, char *src)
{
	int		readb;
	char	*buff;
	
	readb = 1;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
	{
		return (NULL);
	}
	while (!ft_strchr(src, '\n') && readb != 0)
	{
		readb = read(fd, buff, BUFFER_SIZE);
		if (readb == -1)
		{
			free(buff);
			free(src);
			return (NULL);			
		}
		buff[readb] = '\0';
		src = ft_strjoin(src, buff);
	}
	free(buff);
	return (src);
}

char *get_next_line(int fd)
{
	static char	*src;
	char		*prnt;
	
	if(fd < 0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
	src = ft_readlines(fd, src);
	if(!src)
	{
		return (NULL);
	}
	prnt = ft_getline(src);
	src = ft_getget(src);
	return (prnt);
}
