#include "cpu.h"

int  is_numeric(const char *str)
{
	while (*str && *str >= '0' && *str <= '9')
		str++;
	if (*str == '\0')
		return (1);
	return (0);
}

long int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long int	num;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * sign);
}



void    print_ascii()
{
	printf(ANSI_COLOR_GREEN "               _   _       _ _           __  __             _ _             \n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "     /\\       | | (_)     (_| |         |  \\/  |           (_| |            \n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "    /  \\   ___| |_ ___   ___| |_ _   _  | \\  / | ___  _ __  _| |_ ___  _ __ \n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "   / /\\ \\ / __| __| \\ \\ / | | __| | | | | |\\/| |/ _ \\| '_ \\| | __/ _ \\| '__|\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "  / ____ | (__| |_| |\\ V /| | |_| |_| | | |  | | (_) | | | | | || (_) | |   \n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN " /_/    \\_\\___|\\__|_| \\_/ |_|\\__|\\__, | |_|  |_|\\___/|_| |_|_|\\__\\___/|_|   \n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "                                  __/ |                                     \n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "                                 |___/                                      \n\n\n" ANSI_COLOR_RESET);
}