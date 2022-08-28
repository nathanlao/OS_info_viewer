/*
 * my_memory_util.c
 * 
 * Description: Printing the memory utilization of the operator system
 *              from path /proc/meminfo and using the formula: total - 
 *              free - buffers - cached - slab) / total * 100;
 *              
 *                 
 * Created on: May 23th, 2022
 * Author: Guanhua Lao
 */

#include <stdio.h>
#include <string.h>

int main(void) {
    char lines[100];
    float memTotal, memFree, buffers, cached, slab;
    float memUtil = 0.0;

    FILE * fp = fopen("/proc/meminfo", "r");

    if (fp != NULL) {
        while (fgets(lines, sizeof(lines), fp)) {

            // Check substring MemTotal
            char* match = strstr(lines, "MemTotal");
            if (match != NULL) {
                sscanf (match, "MemTotal: %f", &memTotal);
                // Testing Purpose: 
                //printf("memTotal: %f\n", memTotal);
            }

            // Check substring MemFree
            char* match2 = strstr(lines, "MemFree");
            if (match2 != NULL) {
                sscanf (match2, "MemFree: %f", &memFree);
                //printf("memFree: %f\n", memFree);
            }

            // Check substring Buffers
            char* match3 = strstr(lines, "Buffers");
            if (match3 != NULL) {
                sscanf (match3, "Buffers: %f", &buffers);
                //printf("buffer: %f\n", buffers);
            }

            // Check substring Cached but ignore SwapCached
            char* match4 = strstr(lines, "Cached");
            char* notMatch = strstr(lines, "SwapCached");
            if (match4 != NULL && notMatch == NULL) {
                sscanf (match4, "Cached: %f", &cached);
                //printf("cached: %f\n", cached);
            }

            // Check substring Slab
            char* match5 = strstr(lines, "Slab");
            if (match5 != NULL) {
                sscanf (match5, "Slab: %f", &slab);
                //printf("slab: %f\n", slab);
            }
        }
    } else {
        printf("Failed to open /proc/meminfo");
    }

    // Calculate Memory Utilization
    memUtil = (memTotal - memFree - buffers - cached - slab) / memTotal * 100;
    printf("%.2f\n", memUtil);

    fclose(fp);

    return 0;
}