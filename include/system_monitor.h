#ifndef SYSTEM_ACTIVITY_MONITOR_SYSTEM_MONITOR_H
#define SYSTEM_ACTIVITY_MONITOR_SYSTEM_MONITOR_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <dirent.h>
# include <string.h>
# include <time.h>
# include <ctype.h>
#include "color.h"

typedef struct s_cpu
{
	float   overall_usage;
	float   free;
}           t_cpu;

typedef struct s_memory
{
	float   total;
	float   free;
}           t_memory;


/* CPU */
t_cpu   *calculate_overall_cpu_usage();
float   get_process_cpu_usage(char *process_id);
void    display_processes_cpu_memory_usage();

/* Memory */
t_memory            *get_memory_infos();
unsigned long int   get_process_memory_usage(char   *process_id);

/* DISK */
void    display_disk_stats();

/* UTILS */
void    print_ascii();
void    display_cpu_memory(t_cpu *cpu, t_memory *memory);

#endif //SYSTEM_ACTIVITY_MONITOR_SYSTEM_MONITOR_H
