#include "libft.h"

double	ft_str_to_dbl(char *str)
{
	if (!str || (str[0] != '(') || (str[ft_strlen(str) - 1] != ')'))
		return (-1);
	str++;
	str[ft_strlen(str) - 1] = '\0';
	return (ft_atof(str));
}