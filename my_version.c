/*
 * my_version.c
 * 
 * Description: Read and print the information from '/etc/os-release' (name and version of OS) 
 *              and '/proc/version' (kernel version id)
 *                
 *                 
 * Created on: May 22th, 2022
 * Author: Guanhua Lao
 */

#include <stdio.h>

int main(void) {
    // Info of OS from /etc/os-release
    char os_release[100];
    FILE *fp = fopen("/etc/os-release", "r");

    // Open the path successfully
    if (fp != NULL) {
        // Read in lines of information
        while (fgets(os_release, sizeof(os_release), fp)) {
            printf("%s", os_release); 
        } 
    } else {
        printf("Failed to open /etc/os-release\n");
    }
    fclose(fp);

    // Kernel version id from /proc/version 
    char kernel_version[100];

    // Open the path successfully
    FILE *fp2 = fopen("/proc/version", "r");
    if (fp2 != NULL) {
        // Read in information
        while (fgets(kernel_version, sizeof(kernel_version), fp2)) {
            printf("%s", kernel_version);
        }
    } else {
        printf("Failed to open /proc/version\n");
    }
    fclose(fp2);

    return 0;
}