/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asid-ahm <asid-ahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:13:34 by asid-ahm          #+#    #+#             */
/*   Updated: 2024/02/11 10:46:04 by asid-ahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

char *ft_line(char *s)
{
	size_t	i;
	char	*the_line;
	
	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	the_line = malloc(i + 2);
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
	char *save;
	char *buffer;
	int n;

	save = NULL;
	n = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	while (n > 0 && (!ft_strchr(rem, '\n') && !ft_strchr(save, '\n')))
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if(n == -1)
			exit(1);
		buffer[n] = '\0';
		save = ft_strjoin(save, buffer);
		// printf("buffer = %s\n", buffer);
		// printf("save = %s\n", save);
	}
	// printf("n = %i\n", n);
	if (n < 0)
		return (NULL);
	// free (buffer);
	buffer = ft_strjoin(ft_line(rem), ft_line(save));
	// printf("rem1 = (%s)\n", rem);
	// printf("save = (%s)\n", save);
	if (save)
		rem = ft_leftover(save);
	else
		rem = ft_leftover(rem);
	// printf("rem2 = ([%s])\n", rem);
	return (buffer);
}

// int main()
// {
//     int fileDescriptor;
//     const char *filename;

// 	filename = "file.txt1";
//     fileDescriptor = open(filename, O_RDONLY);

//     if (fileDescriptor == -1) {
//         perror("Error opening file");
//         exit(EXIT_FAILURE);
//     }

//     // printf("[%s] ::::: ", get_next_line(fileDescriptor));
//     // printf("[%s] :::::", get_next_line(fileDescriptor));
//     // printf("[%s] :::::", get_next_line(fileDescriptor));
//     printf("%s", get_next_line(fileDescriptor));
//     printf("%s", get_next_line(fileDescriptor));
//     printf("%s", get_next_line(fileDescriptor));
//     printf("%s", get_next_line(fileDescriptor));
//     printf("%s", get_next_line(fileDescriptor));
//     // printf("%s", get_next_line(fileDescriptor));
//     // printf("%s", get_next_line(fileDescriptor));
//     // printf("%s", get_next_line(fileDescriptor));

//     close(fileDescriptor);

//     // return 0;
// }
