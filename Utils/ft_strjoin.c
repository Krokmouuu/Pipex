/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 13:33:06 by bleroy            #+#    #+#             */
/*   Updated: 2022/01/11 17:36:07 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		c;
	char	*r;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = ft_strlen(s1);
	c = ft_strlen(s2);
	r = (char *)malloc(i + c + 2);
	i = -1;
	while (s1[++i])
		r[i] = s1[i];
	r[i] = '/';
	i++;
	c = 0;
	while (s2[c])
	{
		r[i] = s2[c];
		i++;
		c++;
	}
	r[i] = '\0';
	return (r);
}
