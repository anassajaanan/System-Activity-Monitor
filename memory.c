//
// Created by Anas Ajaanan on 7/10/23.
//

#include "memory.h"

typedef struct s_memory
{
	float   total;
	float   free;
}           t_memory;

t_memory *get_memory_infos()
{
	FILE    *mem_info;

	mem_info = fopen("/proc/meminfo", "r");
	if (mem_info == NULL)
	{
		printf("Error opening file\n");
		fclose(mem_info);
		NULL;
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

int main(void)
{
	t_memory *mem = get_memory_infos();
	printf("Total memory: %.2fGB\n", mem->total);
	printf("Free memory: %.2fGB\n", mem->free);
	free(mem);
	return (0);
}