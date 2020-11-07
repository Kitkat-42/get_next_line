/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 17:04:28 by seojeong          #+#    #+#             */
/*   Updated: 2020/11/07 23:09:29 by seojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_newline(char *backup)
{
	int	i;

	i = 0;
	while (backup[i])
	{
		if (backup[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	fill_line(char **backup, char **line, int idx)
{
	char	*p_next;

	(*backup)[idx] = '\0';
	if ((*line = ft_strdup(*backup)) == 0)
		return (-1);
	idx++;
	p_next = ft_strdup(*backup + idx);
	free(*backup);
	*backup = p_next;
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*backup[OPEN_MAX];
	int			rd_size;
	int			idx;

	if ((fd < 0) || (line == 0) || (BUFFER_SIZE <= 0) || read(fd, buf, 0) < 0)
		return (-1);
	while ((rd_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[rd_size] = '\0';
		backup[fd] = ft_strjoin(backup[fd], buf);
		if ((idx = is_newline(backup[fd])) != -1)
			return (fill_line(&backup[fd], line, idx));
	}
	if (backup[fd] && (idx = is_newline(backup[fd])) != -1)
		return (fill_line(&backup[fd], line, idx));
	if (backup[fd])
	{
		*line = ft_strdup(backup[fd]);
		free(backup[fd]);
		backup[fd] = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}
