#include "../headers/libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n > 0)
	{
		*(p++) = (unsigned char)c;
		n--;
	}
	return (s);
}
