/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpu.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 08:46:22 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/10 12:48:46 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/system_monitor.h"
#include "include/helpers.h"



t_cpu *calculate_overall_cpu_usage()
{
	FILE                *fp;
	char                line[256];
	unsigned long int   user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
	t_cpu 			    *cpu;

	fp = fopen("/proc/stat", "r");
	if (fp == NULL)
	{
		printf("Error opening file\n");
		fclose(fp);
		return (NULL);
	}
	else
	{
		fgets(line, sizeof(line), fp);
		cpu = (t_cpu *)malloc(sizeof(t_cpu));
		char    **infos = ft_split(line, ' ');
		user = ft_atoi(infos[1]);
		nice = ft_atoi(infos[2]);
		system = ft_atoi(infos[3]);
		idle = ft_atoi(infos[4]);
		iowait = ft_atoi(infos[5]);
		irq = ft_atoi(infos[6]);
		softirq = ft_atoi(infos[7]);
		steal = ft_atoi(infos[8]);
		guest = ft_atoi(infos[9]);
		guest_nice = ft_atoi(infos[10]);

		unsigned  long int total_idle = idle + iowait;
		unsigned long int total_non_idle = user + nice + system + irq + softirq + steal + guest + guest_nice;
		unsigned long int total = total_idle + total_non_idle;
		float overall_cpu_usage = ((float)total_non_idle / (float)(total)) * 100;
		float free_cpu_percentage = (float)idle / (float)total * 100;
		cpu->overall_usage = overall_cpu_usage;
		cpu->free = free_cpu_percentage;
		fclose(fp);
		return (cpu);
	}
}

float   get_process_cpu_usage(char *process_id)
{
	char *path = ft_strjoin("/proc/", process_id);
	path = ft_strjoin(path, "/stat");
	FILE *stat_file = fopen(path, "r");
	if (stat_file == NULL)
	{
		printf("Error opening file\n");
		fclose(stat_file);
		return (-1);
	}
	else {
		char line[256];
		unsigned long int u_time, s_time;
		fscanf(stat_file, "%*d %*s %*c %*d %*d %*d %*d %*d %*u %*u %*u %*u %lu %lu", &u_time, &s_time);
		unsigned long int total_time = u_time + s_time;
		// Get the current time to calculate the elapsed time
		struct timespec current_time;
		clock_gettime(CLOCK_MONOTONIC, &current_time);
		float elapsed_time = (float)current_time.tv_sec + (float) current_time.tv_nsec / 1e9;

		// Calculate the CPU usage per second
		float cpu_usage_per_second = total_time / elapsed_time;

		// Calculate the CPU usage percentage for the process
		float cpu_usage_percentage = cpu_usage_per_second * 100.0;
		fclose(stat_file);
		return (cpu_usage_percentage);
	}
}

// CPU usage per process/application

void    display_processes_cpu_usage()
{
	int i = 0;
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
				float cpu_usage = get_process_cpu_usage(entry->d_name);
				unsigned long int memory_usage = get_process_memory_usage(entry->d_name);
				if (cpu_usage != -1)
				{
					if (i == 0)
					{
						printf(REDB "        |   Process ID   |     CPU Usage     |   Memory Usage     \n" reset);
						i++;
					}
					char space[3];
					memset(space, ' ', 3);
					space[4 - strlen(entry->d_name)] = '\0';
//					if (strlen(entry->d_name) == 1)
//						printf("process |         %s      |       %.2f%%       |     %lu KB\n", entry->d_name, cpu_usage, memory_usage);
//					else if (strlen(entry->d_name) == 2)
//						printf("process |        %s      |       %.2f%%       |     %lu KB\n", entry->d_name, cpu_usage, memory_usage);
//					else if (strlen(entry->d_name) == 3)
//						printf("process |       %s      |       %.2f%%       |     %lu KB\n", entry->d_name, cpu_usage, memory_usage);
//					else
					printf("process |      %s%s      |       %.2f%%       |     %lu KB\n", space, entry->d_name, cpu_usage, memory_usage);
				}
			}
		}
	}
	closedir(proc_dir);
}

// display the monitor in the terminal



void    display_monitor()
{
	t_cpu *cpu = calculate_overall_cpu_usage();
	t_memory *memory = get_memory_infos();

	printf("\033[2J");
	printf("\033[H");

	// Print the system activity monitor header

	print_ascii();

	// Print the CPU usage
	printf(BLUB "               CPU               " reset);
	printf(MAGB "             Memory              \n" reset);
	printf(BHMAG "    CPU usage   " reset);
	printf(BHYEL "   Free CPU     " reset);
//	printf("||");
	printf(BHCYN "   Total memory  " reset);
	printf(BHGRN "  Free memory   \n" reset);
	printf("------------------------------------------------------------------\n");
	printf("     %.2f%%      |    %.2f%%     |     %.2fGB     |   %.2fGB    \n", cpu->overall_usage, cpu->free, memory->total, memory->free);
	printf("------------------------------------------------------------------\n\n");
	free(cpu);
	free(memory);

//	printf(BMAG "Total memory: %.2fGB\n" reset, memory->total);
//	printf(BGRN "Free memory: %.2fGB\n\n\n" reset, memory->free);


	display_processes_cpu_usage();
}

int main(void)
{
	while (1)
	{
		display_monitor();
		sleep(1);
	}
}