
//
// Created by Anas Ajaanan on 7/10/23.
//

#ifndef SYSTEM_ACTIVITY_MONITOR_HELPERS_H
#define SYSTEM_ACTIVITY_MONITOR_HELPERS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>

long int	ft_atoi(const char *str);
int         is_numeric(const char *str);
char	    **ft_split(const char *str, char sep);
char	    *ft_strjoin(const char *s1, const char *s2);


#endif //SYSTEM_ACTIVITY_MONITOR_HELPERS_H
