#ifndef SYSTEM_ACTIVITY_MONITOR_CPU_H
#define SYSTEM_ACTIVITY_MONITOR_CPU_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <dirent.h>
# include <string.h>
# include <time.h>

char	    **ft_split(const char *str, char sep);
int         is_numeric(const char *str);
long int	ft_atoi(const char *str);
char	    *ft_strjoin(const char *s1, const char *s2);

#endif //SYSTEM_ACTIVITY_MONITOR_CPU_H
