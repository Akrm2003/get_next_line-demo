#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

size_t	ft_strlen(const	char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
char 	*get_next_line(int fd);