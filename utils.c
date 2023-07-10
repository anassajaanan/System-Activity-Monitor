
#include "include/system_monitor.h"

void    print_ascii()
{
	printf(ANSI_COLOR_GREEN "               _   _       _ _           __  __             _ _             \n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "     /\\       | | (_)     (_| |         |  \\/  |           (_| |            \n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "    /  \\   ___| |_ ___   ___| |_ _   _  | \\  / | ___  _ __  _| |_ ___  _ __ \n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "   / /\\ \\ / __| __| \\ \\ / | | __| | | | | |\\/| |/ _ \\| '_ \\| | __/ _ \\| '__|\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "  / ____ | (__| |_| |\\ V /| | |_| |_| | | |  | | (_) | | | | | || (_) | |   \n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN " /_/    \\_\\___|\\__|_| \\_/ |_|\\__|\\__, | |_|  |_|\\___/|_| |_|_|\\__\\___/|_|   \n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "                                  __/ |                                     \n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "                                 |___/                                      \n\n\n" ANSI_COLOR_RESET);
}


void    display_cpu_memory(t_cpu *cpu, t_memory *memory)
{
	printf(BLUB "               CPU               " reset);
	printf(MAGB "             Memory              \n" reset);
	printf(BHMAG "    CPU usage   " reset);
	printf(BHYEL "   Free CPU     " reset);
	printf(BHCYN "   Total memory  " reset);
	printf(BHGRN "  Free memory   \n" reset);
	printf("------------------------------------------------------------------\n");
	printf("     %.2f%%      |    %.2f%%     |     %.2fGB     |   %.2fGB    \n", cpu->overall_usage, cpu->free, memory->total, memory->free);
	printf("------------------------------------------------------------------\n\n");
}
