#ifndef GETNEXTLINE_H
#define GETNEXTLINE_H

# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>

char *get_next_line(int fd);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char *ft_strdup(const char *s1);
void *ft_memcpy(void *dst, const void *src, size_t n);

#endif

#ifndef BUFFER_SIZE

# define BUFFER SIZE 3
#endif
