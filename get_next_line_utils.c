/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iozmen <iozmen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:25:18 by iozmen            #+#    #+#             */
/*   Updated: 2023/12/02 18:21:56 by iozmen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}
int	ft_strchr(char *str, char c)
{
	int	i;

	if (!str)
		return (0);
	i = ft_strlen(str);
	while (i >= 0)
	{
		if (*str == c)
			return (1);
		i--;
		str++;
	}
	return (0);
}

char *ft_strjoin(char *s1, char *s2) 
{
	int		i;
	int		j;
	char	*join;
	
	if(!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	join = malloc((sizeof(char)) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!join)
	{
		return (NULL);
	}
	i = -1;
	while(s1[++i] != '\0') // !
	{
		join[i] = s1[i];
	}
	j = 0;
	while(s2[j] != '\0')
	{
		join[i++] = s2[j++];
	}
	join[i] = '\0';
	free (s1);
	return (join);	
}

char *ft_getline(char *dst)
{
	int		i;
	char	*ret;

	i = 0;
	if (!dst[i])
		return (NULL);
	while (dst[i] && dst[i] != '\n')
		i++;
	if (dst[i] == '\n')
		i++;
	ret = malloc(sizeof(char) * (i + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (dst[i] && dst[i] != '\n')
	{
		ret[i] = dst[i];
		i++;
	}
	if (dst[i] == '\n')
	{
		ret[i] = dst[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
char	*ft_getget(char *str)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if(!str[i])
	{
		free(str);
		return (NULL);
	}
	ret = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!ret)
		return (NULL);
	i++;
	while (str[i])
	{
		ret[j] = str[i];
		i++;
		j++;
	}
	ret[j] = '\0';
	free(str);
	return (ret);
}

