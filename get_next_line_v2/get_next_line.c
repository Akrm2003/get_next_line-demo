/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asid-ahm <asid-ahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:13:34 by asid-ahm          #+#    #+#             */
/*   Updated: 2024/02/13 13:47:55 by asid-ahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

char *ft_line(char *s)
{
	size_t	i;
	char	*the_line;
	
	i = 0;
	if (!s || !*s)
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	the_line = malloc(i + 1);
	if (!the_line)
	{
		free (the_line);
		return (NULL);
	}
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		the_line[i] = s[i];
		i++;
	}
	the_line[i] = s[i];
	if (s[i] != '\0')
		the_line[++i] = '\0';
	return (the_line);
}

char *ft_leftover(char *rem)
{
	size_t	i;
	size_t	n;
	char	*rem2;

	i = 0;
	n = 0;
	if (!rem)
		return (NULL);
	while (rem[i] && rem[i] != '\n')
		i++;
	if (rem[i] && rem[i] == '\n')
		i++;
	if (rem[i] == '\0')
		return (NULL);
	rem2 = malloc(ft_strlen(rem) - i + 1);
	if (!rem2)
		return(NULL);
	while (rem[i])
		rem2[n++] = rem[i++];
	rem2[n] = '\0';
	return (rem2);
}

// char *ft_leftover(char *whole, char *the_line)
// {
// 	size_t	i;
// 	size_t	n;
// 	char	*rem;

// 	i = 0;
// 	n = 0;
// 	if (!whole || !the_line)
// 		return (NULL);
// 	while (whole[i] == the_line[i])
// 		i++;
// 	rem = malloc(ft_strlen(whole) - i + 1);
// 	if (!rem)
// 		return(NULL);
// 	while (whole[i])
// 		rem[n++] = whole[i++];
// 	rem[n] = '\0';
// 	return (rem);
// }


char *get_next_line(int fd)
{
	static char *rem;
	// char *save;
	char *buffer;
	static int n=1;

	// save = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	// n = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	// printf("buffer size = (%d)\n", BUFFER_SIZE);
	while (n > 0 && !ft_strchr(rem, '\n'))
	{
		n = read(fd, buffer, BUFFER_SIZE); /// think about this ..,.., INT_MAX
		// printf("reading happened\n");
		// if(n == -1)
		// 	return (NULL);
		buffer[n] = '\0';
		rem = ft_strjoin(rem, buffer);
		// printf("save = [%s]\n", save);
		// free(buffer);
		// buffer = NULL;
		// printf("buffer = (%s)\n", buffer);
		// printf("save = (%s)\n", save);
	}
	// printf("n = %i\n", n);
	if (n <= 0 && (rem && !(rem[0])))
		return (NULL);
	if (buffer)
	{
		free(buffer);
		buffer = NULL;
	}
	buffer = ft_line(rem);
	// ft_strjoin(ft_line(rem), ft_line(save));
	if (buffer && !buffer[0])
		return (NULL);
	// printf("rem1 = (%s)\n", rem);
	// if (save)
	// 	rem = ft_leftover(save);
	// else
		rem = ft_leftover(rem);
	// if (save)
	// 	free(save);
	return (buffer);
}

// int main()
// {
//     int fileDescriptor;
//     const char *filename;
// 	size_t		counter;

// 	counter = 1;
// 	filename = "file.txt1";
//     fileDescriptor = open(filename, O_RDONLY);

//     if (fileDescriptor == -1) {
//         perror("Error opening file");
//         exit(EXIT_FAILURE);
//     }
// 	char *line = get_next_line(fileDescriptor);
// 	while (line)
// 	{
// 		printf("counter[%zu] => {%s}\n", counter, line);
// 		// free(line);
// 		// line = NULL;
// 		line = get_next_line(fileDescriptor);
// 		counter++;
// 	}
// 	// line = get_next_line(fileDescriptor);
// 	// printf("\ncounter[%zu] => %s", counter, line);
// 	// printf("\ncounter[%zu] => %s", counter, line);
	
	
//     // printf("[%s] ::::: ", get_next_line(fileDescriptor));
//     // printf("[%s] :::::", get_next_line(fileDescriptor));
//     // printf("[%s] :::::", get_next_line(fileDescriptor));
//     // printf("%s", );
//     // printf("%s", get_next_line(fileDescriptor));
//     // printf("%s", get_next_line(fileDescriptor));
//     // printf("%s", get_next_line(fileDescriptor));
//     // printf("%s", get_next_line(fileDescriptor));
//     // printf("%s", get_next_line(fileDescriptor));
//     // printf("%s", get_next_line(fileDescriptor));

//     close(fileDescriptor);

//     // return 0;
// }
