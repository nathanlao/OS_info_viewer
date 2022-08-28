/*
 * my_current_processes.c
 * 
 * Description: Printing the process ID of all running processes on the system by 
 *              finding process ID from the "/proc" directory.
 *              
 *                 
 * Created on: May 22th, 2022
 * Author: Guanhua Lao
 */

#include <stdio.h>
#include <dirent.h> // opendir(), readdir(), closedir()
#include <ctype.h> // isdigit()

int main(void) {

    DIR *procdir = opendir("/proc"); // Open the directory of /proc
    struct dirent *ptr; // Read the file
    char pid[300]; // For processes ID

    // Open the directory successfully
    if (procdir != NULL) {
        
        // Read /proc successfully
        while ((ptr = readdir(procdir)) != NULL) {

            // Check /proc and print the numeric name
            if (!isdigit(*ptr->d_name)) {
                continue;
            }

            sprintf(pid, "%s", ptr->d_name);
            puts(pid);
        }
        
        closedir(procdir);

    } else {
        perror("Unable to opendir \"/proc\".");
        return 1;
    }

    return 0;
}