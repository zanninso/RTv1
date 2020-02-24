#include "libft.h"

int	ft_is_number(char *str)
{
	int	i;

	i = -1;
	if (str[0] == '-')
		i++;
	while (str[++i])
		if (!ft_isdigit(str[i]) && str[i] != '.')
			return (1);

	
	return (0);
}