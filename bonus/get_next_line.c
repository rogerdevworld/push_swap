#include "../inc/push_swap.h"

char	*get_next_line(int fd)
{
	char	*buf;
	int		i;
	int		bytes_read;

	buf = malloc(1000);
	if (!buf)
		return (NULL);
	i = 0;
	bytes_read = read(fd, &buf[i], 1);
	while (bytes_read > 0 && buf[i] != '\n' && i < 999)
	{
		i++;
		bytes_read = read(fd, &buf[i], 1);
	}
	if (bytes_read <= 0 && i == 0)
	{
		free(buf);
		return (NULL);
	}
	if (buf[i] == '\n')
		i++;
	buf[i] = '\0';
	return (buf);
}
