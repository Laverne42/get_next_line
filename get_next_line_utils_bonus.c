/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquez <pmarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:29:51 by pmarquez          #+#    #+#             */
/*   Updated: 2022/06/03 09:19:27 by pmarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	x;

	x = 0;
	while (s[x])
		x++;
	return (x);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*n;
	size_t			x;

	n = b;
	x = 0;
	while (x < len)
	{
		n[x] = c;
		x++;
	}
	return (n);
}

void	*ft_calloc(size_t count, size_t size)

{
	void	*p;

	if (count == __SIZE_MAX__ && size > 1)
		return (NULL);
	else if (size == __SIZE_MAX__ && count > 1)
		return (NULL);
	p = (void *)malloc(size * count);
	if (p == NULL)
		return (NULL);
	ft_memset(p, 0, size * count);
	return (p);
}

char	*ft_strjoin(char *s1, char *s2)

{
	int		s1len;
	int		s2len;
	int		i;
	int		j;
	char	*p;

	if (s1 == NULL)
		s1 = (char *)ft_calloc(1, 1);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	i = 0;
	j = 0;
	p = (char *)malloc(sizeof(char) * (s2len + s1len + 1));
	if (!p)
		return (0);
	while (s1 && s1[i])
		p[i++] = s1[j++];
	j = 0;
	while (s2 && s2[j])
		p[i++] = s2[j++];
	p[i] = '\0';
	free(s1);
	return (p);
}

char	*ft_strchr(const char *s, int c)
{
	int		x;
	char	*t;
	int		slen;

	if (!s)
		return (0);
	slen = ft_strlen(s);
	t = (char *)s;
	x = 0;
	if ((char)c == 0)
		return (&t[slen]);
	while (t[x])
	{
		if (t[x] != (char)c)
			x++;
		else if (t[x] == (char)c)
			return (&t[x]);
	}
	return (0);
}
