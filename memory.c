//
// Created by Anas Ajaanan on 7/10/23.
//

#include "include/system_monitor.h"
#include "include/helpers.h"


t_memory *get_memory_infos()
{
	FILE    *mem_info;

	mem_info = fopen("/proc/meminfo", "r");
	if (mem_info == NULL)
	{
		printf("Error opening file\n");
		fclose(mem_info);
		return (NULL);
	}
	else
	{
		t_memory *memory = (t_memory *)malloc(sizeof(t_memory));
		unsigned long int   total_memory;
		unsigned long int   free_memory;
		char    line[256];
		fgets(line, sizeof(line), mem_info);
		sscanf(line, "MemTotal: %lu", &total_memory);
		fgets(line, sizeof(line), mem_info);
		sscanf(line, "MemFree: %lu", &free_memory);
		fclose(mem_info);
		memory->total = (float)total_memory / (1024 * 1024);
		memory->free = (float)free_memory / (1024 * 1024);
		return (memory);
	}
}


unsigned long int   get_process_memory_usage(char   *process_id)
{
	char *path = ft_strjoin("/proc/", process_id);
	path = ft_strjoin(path, "/status");
	FILE *status_file = fopen(path, "r");
	if (status_file == NULL)
	{
		printf("Error opening file\n");
		fclose(status_file);
		return (-1);
	}
	else
	{
		char line[256];
		unsigned long memory_usage = 0;

		while (fgets(line, sizeof(line), status_file) != NULL) {
			if (sscanf(line, "VmRSS: %lu", &memory_usage) == 1) {
				break; // Found the VmRSS line, so stop reading further
			}
		}
		fclose(status_file);
		return (memory_usage);
	}
}

void    display_precesses_memory_usage()
{
	DIR *proc_dir;

	proc_dir = opendir("/proc");
	if (proc_dir == NULL)
	{
		printf("Error opening /proc directory\n");
		return ;
	}
	else
	{
		struct dirent *entry;
		while ((entry = readdir(proc_dir)) != NULL)
		{
			if (entry->d_type == DT_DIR && is_numeric(entry->d_name))
			{
				unsigned long int memory_usage = get_process_memory_usage(entry->d_name);
				if ((int)memory_usage != -1)
				{
					printf("Process %s memory usage: %lu KB\n", entry->d_name, memory_usage);
				}
			}
		}
		closedir(proc_dir);
	}
}
