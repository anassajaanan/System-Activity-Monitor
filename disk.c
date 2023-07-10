/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:47:41 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/10 14:53:09 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Anas Ajaanan on 7/10/23.
//

#include "include/system_monitor.h"
#include "include/helpers.h"

void display_disk_stats() {
	FILE* diskstats_file = fopen("/proc/diskstats", "r");
	if (diskstats_file == NULL) {
		printf("Error opening /proc/diskstats file\n");
		fclose(diskstats_file);
		return;
	}

	printf(GRNHB "\n%-21s %-17s %-16s\n", "Device/Partition", "Read Rate (sectors/s)", "Write Rate (sectors/s)" reset);
	printf("------------------------------------------------------------------\n");

	char line[256];

	while (fgets(line, sizeof(line), diskstats_file) != NULL) {
		char    **infos;
		infos = ft_split(line, ' ');
		if (infos[2] != NULL && infos[5] != NULL && infos[9] != NULL) {
			char* device_name = infos[2];
			unsigned long long read_sectors = strtoull(infos[5], NULL, 10);
			unsigned long long write_sectors = strtoull(infos[9], NULL, 10);
			printf("%-30s %-22llu %-15llu\n", device_name, read_sectors, write_sectors);
		}
	}
	fclose(diskstats_file);
}

