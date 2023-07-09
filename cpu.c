#include "cpu.h"


float   calculateOverallCpuUsage()
{
	FILE                *fp;
	char                line[256];
	unsigned long int   user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;

	fp = fopen("/proc/stat", "r");
	if (fp == NULL)
	{
		printf("Error opening file\n");
		fclose(fp);
		return (-1);
	}
	else
	{
		fgets(line, sizeof(line), fp);
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
		fclose(fp);
		return (overall_cpu_usage);
	}
}

int main(void)
{
	printf("Overall CPU usage: %.2f%%\n", calculateOverallCpuUsage());
	return (0);
}