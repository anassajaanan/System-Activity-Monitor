#include "cpu.h"

typedef struct s_cpu
{
	float   overall_usage;
	float   free;
}           t_cpu;

t_cpu *calculateOverallCpuUsage()
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

int main(void)
{
	t_cpu *cpu = calculateOverallCpuUsage();
	printf("Overall CPU usage: %.2f%%\n", cpu->overall_usage);
	printf("Free CPU: %.2f%%\n", cpu->free);
	free(cpu);
	return (0);
}