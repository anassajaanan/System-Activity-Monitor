#include "../include/helpers.h"

int  is_numeric(const char *str)
{
	while (*str && *str >= '0' && *str <= '9')
		str++;
	if (*str == '\0')
		return (1);
	return (0);
}