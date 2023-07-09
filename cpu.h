#ifndef SYSTEM_ACTIVITY_MONITOR_CPU_H
#define SYSTEM_ACTIVITY_MONITOR_CPU_H

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"


# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <dirent.h>
# include <string.h>
# include <time.h>
# include <ctype.h>
#include "color.h"

char	    **ft_split(const char *str, char sep);
int         is_numeric(const char *str);
long int	ft_atoi(const char *str);
char	    *ft_strjoin(const char *s1, const char *s2);
void        print_ascii();

#endif //SYSTEM_ACTIVITY_MONITOR_CPU_H
