/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 11:33:42 by seojeong          #+#    #+#             */
/*   Updated: 2020/11/07 22:27:33 by seojeong         ###   ########.fr       */
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
	static char	*backup;
	int			rd_size;
	int			idx;

	if ((fd < 0) || (line == 0) || (BUFFER_SIZE <= 0) || read(fd, buf, 0) < 0)
		return (-1);
	while ((rd_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[rd_size] = '\0';
		backup = ft_strjoin(backup, buf);
		if ((idx = is_newline(backup)) != -1)
			return (fill_line(&backup, line, idx));
	}
	if (backup && (idx = is_newline(backup)) != -1)
		return (fill_line(&backup, line, idx));
	if (backup)
	{
		*line = ft_strdup(backup);
		free(backup);
		backup = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}
