/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquez <pmarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:18:57 by pmarquez          #+#    #+#             */
/*   Updated: 2022/06/03 09:00:42 by pmarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_newline(char *op)
{
	int	x;

	x = 0;
	while (op && op[x])
	{
		if (op[x] == '\n')
			return (x + 1);
		x++;
	}
	return (0);
}

char	*ft_extract_line(char *op)
{
	char	*line;
	int		x;
	int		y;

	y = 0;
	x = 0;
	if (!op[y])
		return (NULL);
	if (ft_newline(op) > 0)
	{
		line = (char *)ft_calloc(sizeof(char), (ft_newline(op) + 1));
		while (op[y] != '\n' && op[y] != '\0')
			line[x++] = op[y++];
		if (op[y] == '\n')
			line[x++] = '\n';
	}
	else
	{
		line = (char *)ft_calloc(sizeof(char), (ft_strlen(op) + 1));
		while (op && op[y])
			line[x++] = op[y++];
	}
	return (line);
}

char	*ft_optemp(char *op)
{
	int		x;
	int		y;
	char	*op_temp;

	x = 0;
	y = 0;
	while (op[x] != '\n' && op[x])
		x++;
	if (!op[x])
	{
		free(op);
		return (NULL);
	}
	op_temp = (char *)ft_calloc((ft_strlen(op) - x + 1), sizeof(char));
	x++;
	while (op[x])
	{
		op_temp[y] = op[x];
		x++;
		y++;
	}
	free(op);
	return (op_temp);
}

char	*ft_read(int fd, char *op)
{
	char	*buff;
	int		fd_number;

	if (!op)
		op = ft_calloc(1, 1);
	fd_number = 1;
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (!ft_strchr(op, '\n') && fd_number != 0)
	{
		fd_number = read(fd, buff, BUFFER_SIZE);
		if (fd_number == -1)
		{
			free(buff);
			free(op);
			return (NULL);
		}
		buff[fd_number] = '\0';
		op = ft_strjoin(op, buff);
	}
	free(buff);
	return (op);
}

char	*get_next_line(int fd)
{
	static char	*op;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	op = ft_read(fd, op);
	if (!op)
		return (NULL);
	line = ft_extract_line(op);
	op = ft_optemp(op);
	return (line);
}
