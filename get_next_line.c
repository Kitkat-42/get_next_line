/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 11:33:42 by seojeong          #+#    #+#             */
/*   Updated: 2020/11/02 22:32:02 by seojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// #include <string.h>
// #include <unistd.h> //read함수
// #include <fcntl.h> //open함수
// #include <stdio.h>
// #include <limits.h>

#define BUFF_SIZE 1024

int	is_newline(char *backup) //backup[fd]를 받음
{
	int	i;
	
	i = 0;
	while (backup[i])
	{
		if (backup[i] == '\n')
			return (i); // backup에 개행문자가 있으면 그 개행문자의 index 반환
		i++;
	}
	return (-1); // 개행문자가 없는 경우
}

int	split_line(char **backup, char **line, int idx)
{
	char	*tmp;
	int		len;
	
	(*backup)[idx] = '\0'; //backup의 개행문자 index에 null문자 넣어줌
	*line = ft_strdup(*backup); //string이 된 backup을 line에 넣어줌
	len = ft_strlen(*backup + idx + 1); //?
	if (len == 0)
	{
		free(*backup);
		*backup = 0;
		return (1);
	}
	tmp = ft_strdup(*backup + idx + 1);
	free(*backup);
	*backup = tmp;
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char	buf[BUFF_SIZE + 1];
	static char	*backup[OPEN_MAX]; //fd마다 string저장 위해 char 포인터 배열생성. OPEN_MAX는 파일을 열 수 있는 상한값(fd = 0 ~ OPEN_MAX(10240)).
	ssize_t	rd_size;
	int		idx;
	
	if ((fd < 0) || (line == 0) || (BUFFER_SIZE <= 0))
		return (-1);
	while ((rd_size = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[rd_size] = '\0';
		// printf("buf = %s\n", buf);
		backup[fd] = ft_strjoin(backup[fd], buf);
		if ((idx = is_newline(backup[fd])) >= 0) // 개행문자가 있는 경우(없으면 idx= -1)
		 	return (split_line(&backup[fd], line, idx));	
		// backup에 개행문자가 없으면 read 반복
	}
	// return (return_all(&backup[fd], line, read_size));
}
