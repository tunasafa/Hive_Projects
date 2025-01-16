#include "../headers/libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*s;

	s = (char *)str;
	while (*s != (unsigned char)c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return (s);
}

/* 
	if character is inside of string, it returns position of character,
	or return -1 if character is not inside
*/
int	is_in_str(char *str, char c, int start, int end)
{
	int	i;

	i = start;
	while (i < end && str[i] != 0)
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
