/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btan <btan@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:24:40 by btan              #+#    #+#             */
/*   Updated: 2023/11/11 15:02:36 by btan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fill_buffer(int *read_bytes, int fd, char *buffer)
{
	char	*ptr;
	char	*temp;

	if (!buffer)
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	ptr = buffer;
	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	*read_bytes = read(fd, temp, BUFFER_SIZE);
	buffer = ft_strjoin(buffer, temp);
	free(temp);
	free(ptr);
	if (*read_bytes < 0 || (!*read_bytes && !*buffer))
	{
		free(buffer);
		buffer = NULL;
	}
	return (buffer);
}

static char	*cut_line(char **buffer)
{
	int		len;
	char	*ptr;
	char	*temp;

	len = 0;
	ptr = *buffer;
	while ((*buffer)[len] != '\n')
		len++;
	len++;
	temp = ft_calloc(len + 1, sizeof(char));
	while (len--)
		temp[len] = (*buffer)[len];
	*buffer = ft_strdup(ft_strchr(*buffer, '\n') + 1);
	free(ptr);
	return (temp);
}

char	*get_next_line(int fd)
{
	int			read_bytes;
	static char	*buffer;
	char		*line;

	read_bytes = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (ft_strchr(buffer, '\n') == NULL && read_bytes)
	{
		buffer = fill_buffer(&read_bytes, fd, buffer);
		if (!buffer)
			break ;
	}
	if (ft_strchr(buffer, '\n') != NULL)
		return (cut_line(&buffer));
	if (!buffer)
		return (NULL);
	line = ft_strdup(buffer);
	free(buffer);
	buffer = NULL;
	return (line);
}

//#include <stdio.h>
//#include <fcntl.h>
//int	main()
//{
//	int	fd = open("tests/test.txt", O_RDONLY);
//	char	*line = get_next_line(fd);
//	for (int i = 1; i < 16; i++)
//	{
//		printf("Line %d: %s", i, line);
//		free(line);
//		line = get_next_line(fd);
//	}
//}

//#include <stdio.h>
//#include <fcntl.h>
//
//int main(void)
//{
//  // Create a temporary file and write test content to it.
//  char test_content[] =
//						// "0123456789012345678901234567890123456789x0\n"
//						// "0123456789012345678901234567890123456789x1\n"
//						// "0123456789012345678901234567890123456789x2\n"
//						// "0123456789012345678901234567890123456789x3\n"
//						// "0123456789012345678901234567890123456789x4\n"
//						// "0123456789012345678901234567890123456789x5\n"
//						// "\n"
//						// "\n"
//						// "\n"
//							// "0123456789\n"
//							// "012345678\n"
//							// "90123456789\n" //here ownwards weird
//							// "0123456789\n"
//							// "xxxx\n"
//
//						"\n"
//						"0123456789012345678901234567890123456789x2\n"
//						"0123456789012345678901234567890123456789x3\n"
//						"\n"
//						"0123456789012345678901234567890123456789x5\n"
//						"\n"
//						"\n"
//						"0123456789012345678901234567890123456789x8\n"
//						"\n"
//						"\n"
//						"\n"
//						"0123456789012345678901234567890123456789x12";
//
//	FILE *temp = fopen("temp_test.txt", "w+");
//	if (!temp)
//	{
//		perror("Error creating temporary file");
//		return 1;
//	}
//	fwrite(test_content, sizeof(char), sizeof(test_content) - 1, temp);
//	fclose(temp);
//	// Open the temporary file to read with get_next_line.
//	int fd = open("temp_test.txt", O_RDONLY);
//	if (fd == -1)
//	{
//		perror("Error opening the temporary file");
//		return 1;
//	}
//	int i = 0;
//	char *line = NULL;
//	// line = get_next_line(fd);
//	// printf("res:%s;\n",line);
//	while ( (line = get_next_line(fd)) != NULL)
//	{
//		if (line[0] == '\0')
//		{
//			free(line);
//			break;
//		}
//		printf("res%d:%s;\n",i ,line);
//		free(line);
//		i ++;
//	}
//	close(fd);
//	// Optionally, remove the temporary file after testing.
//	remove("temp_test.txt");
//	return 0;
//}
