//
// Created by Anas Ajaanan on 7/10/23.
//
#include "include/system_monitor.h"

int main(void)
{
	while (1)
	{
		t_cpu *cpu = calculate_overall_cpu_usage();
		t_memory *memory = get_memory_infos();

		printf("\033[2J");
		printf("\033[H");
		print_ascii();

		display_cpu_memory(cpu, memory);
		display_processes_cpu_memory_usage();
		display_disk_stats();

		free(cpu);
		free(memory);
		sleep(1);
	}
}