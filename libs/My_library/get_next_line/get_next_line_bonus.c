/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:24:50 by fbicane           #+#    #+#             */
/*   Updated: 2024/12/13 17:08:05 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../my_library.h"

static char	*get_the_reminder(char *container)
{
	char	*new_container;
	char	*temp_container;

	if (!container)
		return (NULL);
	temp_container = ft_strchr(container, '\n');
	if (!temp_container)
		return (free(container), NULL);
	new_container = ft_strdup(temp_container + 1);
	free(container);
	return (new_container);
}

static char	*get_the_newline(char *container)
{
	size_t	i;
	char	*new_line;

	if (!container)
		return (NULL);
	i = 0;
	while (container[i] && container[i] != '\n')
		i++;
	if (container[i] == '\n')
		i++;
	new_line = malloc((i + 1) * sizeof(char));
	if (!new_line)
		return (free (container), NULL);
	new_line = ft_memmove(new_line, container, i);
	new_line[i] = '\0';
	return (new_line);
}

static char	*read_from_fd(int fd, char *container)
{
	ssize_t	bytes_read;
	char	*buffer;

	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free (buffer), free (container), NULL);
		buffer[bytes_read] = '\0';
		container = ft_strjoin(container, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	if (bytes_read == 0 && (!container || !*container))
		return (free(container), container = NULL);
	return (container);
}

char	*get_next_line(int fd)
{
	static char	*container[FD];
	char		*line;
//this is a solotion for the offset glitch (when the container still have data even after u close the fd in main)
	if (fd < 0)
		return (free(container[fd * -1]), container[fd * -1] = NULL, NULL);
	if (BUFFER_SIZE <= 0 || fd > FD)
		return (NULL);
	if (!container[fd])
	{
		container[fd] = malloc(1 * sizeof (char));
		if (!container[fd])
			return (NULL);
		*container[fd] = 0;
	}
	if (!ft_strchr(container[fd], '\n'))
		container[fd] = read_from_fd(fd, container[fd]);
	if (!container[fd])
		return (free (container[fd]), NULL);
	line = get_the_newline(container[fd]);
	container[fd] = get_the_reminder(container[fd]);
	return (line);
}
