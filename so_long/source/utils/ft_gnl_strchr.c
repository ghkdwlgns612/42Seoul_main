#include "../../so_long.h"

char *ft_gnl_strchr(char *s, int c)
{
    if (c == '\0')
        return (&((char *)s)[ft_gnl_strlen(s)]);
    while (*s)
    {
        if (*s == c)
            return ((char *)s);
        s++;
    }
    return (NULL);
}