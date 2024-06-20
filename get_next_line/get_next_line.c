/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 22:42:09 by eahn              #+#    #+#             */
/*   Updated: 2024/05/13 14:37:16 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*static_str;
	int			newline_len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	static_str = read_save_str(fd, static_str);
	if (!static_str)
		return (NULL);
	line = extract_line(static_str, &newline_len);
	static_str = extract_next_str(static_str, &newline_len);
	return (line);
}

char	*read_save_str(int fd, char *static_str)
{
	char	*buffer;
	int		read_bytes;

	buffer = gnl_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	while (!gnl_strchr(static_str, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			free(static_str);
			buffer = NULL;
			static_str = NULL;
			return (NULL);
		}
		if (read_bytes == 0)
			break ;
		buffer[read_bytes] = '\0';
		static_str = gnl_strjoin(static_str, buffer);
	}
	free(buffer);
	buffer = NULL;
	return (static_str);
}

char	*extract_line(char *static_str, int *newline_len)
{
	char	*line;

	if (!static_str)
		return (NULL);
	*newline_len = gnl_strchr(static_str, '\n');
	if (*newline_len == 0)
		*newline_len = gnl_strlen(static_str);
	if (*newline_len == 0)
	{
		free(static_str);
		static_str = NULL;
		return (NULL);
	}
	line = gnl_calloc((*newline_len + 1), sizeof(char));
	if (!line)
		return (NULL);
	gnl_strcpy(line, static_str, *newline_len + 1);
	return (line);
}

char	*extract_next_str(char *static_str, int *newline_len)
{
	char	*next_str;
	int		size;

	if (!static_str)
		return (NULL);
	size = gnl_strlen(static_str) - *newline_len + 1;
	if (size == 1)
	{
		free(static_str);
		return (NULL);
	}
	next_str = gnl_calloc(size, sizeof(char));
	if (!next_str)
		return (NULL);
	gnl_strcpy(next_str, static_str + *newline_len, size);
	free(static_str);
	static_str = NULL;
	return (next_str);
}

// int	main(void)
// {
// 	char	*result_line;
// 	int		nb_line;
// 	int		fd;

// 	nb_line = 1;
// 	fd = open("./test.txt", O_RDONLY);
// printf("FD : %d\n", fd);
// 	while (nb_line < 5)
// 	{
// 		result_line = get_next_line(fd);
// 		if (result_line == NULL)
// 			break ;
// 		printf("line %d: %s\n", nb_line, result_line);
// 		nb_line++;
// 		free(result_line);
// 	}
// 	// system("leaks --list -- a.out");
// 	close(fd);
// 	return (0);
// }
