#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

char    **retrieve_fds()
{
    DIR *dir;
    struct dirent *ent;
    char **fds = malloc(256 * sizeof(char *));
    int i = 0;
    // Open the /dev/pts directory
    if ((dir = opendir("/dev/pts")) != NULL) {
        // Iterate through each entry in the /dev/pts directory
        while ((ent = readdir(dir)) != NULL) {
            // Check if the entry is a terminal device
            if (strncmp(ent->d_name, "ptmx", 4) != 0) {
                // Construct the path to the terminal device
                char path[256];
                snprintf(path, sizeof(path), "/dev/pts/%s", ent->d_name);
                
                // Use the terminal device to identify the associated processes
                // (You can use tools like 'fuser' or 'lsof' to do this)
                // Once you have the PIDs, proceed to access their file descriptors
                // For demonstration purposes, let's print the terminal device and PID
                // printf("Terminal: %s, PID: <retrieve PID here>\n", path);
                fds[i] = malloc((strlen(path) + 1) * sizeof(char));
                strcpy(fds[i], path);
                i++;
                // Now, for each PID, access the /proc/<PID>/fd directory to get file descriptors
                // (You can implement this using the prev./qious approach described)
            }
        }
        closedir(dir);
    } else {
        perror("Error opening /dev/pts directory");
        return EXIT_FAILURE;
    }
    fds[i] = NULL;
    return fds;
}

// Function to join string and int
char *strjoinf(const char *s1, int num) {
    // Calculate the length of the resulting string
    int len1 = strlen(s1);
    int len2 = snprintf(NULL, 0, "%d", num); // Get length of integer as string
    int total_len = len1 + len2;

    // Allocate memory for the result string
    char *result = (char *)malloc(total_len + 1);
    if (!result) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    // Copy the first string
    strcpy(result, s1);

    // Append the integer as string
    sprintf(result + len1, "%d", num);

    return result;
}

char *find_next_tty(char **terminals, int num_terminals, const char *tty_name) {
    // Search for tty_name in the terminals array
    for (int i = 0; i < num_terminals; i++) {
        if (strcmp(terminals[i], tty_name) == 0) {
            // If tty_name is found, return the next element
            if (i + 1 < num_terminals) {
                return terminals[i + 1];
            } else {
                // If tty_name is the last element, return the previous element
                return terminals[i - 1];
            }
        }
    }
    // If tty_name is not found, return NULL or handle accordingly
    return NULL;
}

int count_strings(char **strings) {
    int count = 0;
    while (*strings != NULL) {
        strings++;
        count++;
    }
    return count;
}

void free_strings(char **strings) {
    char **ptr = strings;
    while (*ptr != NULL) {
        free(*ptr);  // Free memory for each string
        ptr++;       // Move to the next string
    }
    free(strings); // Free memory for the array of pointers
}


int main() {
    char **av = retrieve_fds();
    while (1)
    {
        int fd;
        char *tty_name = ttyname(STDIN_FILENO); // Get the terminal file name
        if (tty_name == NULL) {
            perror("Error getting terminal file name");
            return EXIT_FAILURE;
        }
        char *next_terminal = find_next_tty(av, count_strings(av), tty_name);
        // if (next_terminal != NULL)
        //     printf("Next terminal: %s\n", next_terminal);
        // else
        //     printf("Terminal not found or no next terminal.\n");
        // printf("%s, %s\n", tty_name, next_terminal);
        // // Open the target terminal's file descriptor
        fd = open(next_terminal, O_WRONLY); // Change the file descriptor as needed
        if (fd == -1) {
            perror("open");
            exit(EXIT_FAILURE);
        }
        char message[1000];
        // scanf("%s", message);
        fgets(message, sizeof(message), stdin);
        // // Write the message to the other terminal
        if (write(fd, message, strlen(message)) == -1) {
            perror("write");
            close(fd);
            exit(EXIT_FAILURE);
        }
        // // Close the file descriptor
        close(fd);
    }
    free_strings(av);
    return 0;
}
