/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asid-ahm <asid-ahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:07:17 by asid-ahm          #+#    #+#             */
/*   Updated: 2024/02/11 10:37:36 by asid-ahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const	char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while(str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;
	char	x;

	x = c;
	i = 1;
	if (!s)
		return(NULL);
	while (s[i] && s[i] != x )
		i++;
	if (s[i] == '\0')
		return (NULL);
	return ((char *)&s[i]);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	counter;
	char	*d;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	i = 0;
	counter = (ft_strlen(s1) + ft_strlen(s2));
	// printf("%zu -- %zu\n", ft_strlen(s2), ft_strlen(s1));
	d = (char *)malloc((counter + 1) * sizeof (char));
	if (!d)
		return (NULL);
	counter = 0;
	while (s1[i])
	{
		d[i] = s1[i];
		i++;
	}
	// printf("%s\n", d);
	while (s2[counter])
		d[i++] = s2[counter++];
	d[i] = '\0';
	return (d);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	n;
	char	*dup;

	i = 0;
	if (!s1)
		return (NULL);
	n = ft_strlen(s1);
	dup = (char *)malloc((n + 1) * sizeof (char));
	if (!dup)
		return (NULL);
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = s1[i];
	return (dup);
}
