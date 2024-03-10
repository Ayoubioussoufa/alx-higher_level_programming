bb

bubuu
e <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <dirent.h>

// int main() {
//     DIR *dir;
//     struct dirent *entry;
//     char buf[1024];

//     // Open the /proc directory
//     dir = opendir("/proc");
//     if (dir == NULL) {
//         perror("opendir failed");
//         exit(1);
//     }

//     // Read each entry in the /proc directory
//     while ((entry = readdir(dir)) != NULL) {
//         // Check if the entry is a directory and represents a process
//         if (atoi(entry->d_name) != 0) {
//             // Construct the path to the command file for the process
//             snprintf(buf, sizeof(buf), "/proc/%s/comm", entry->d_name);
//             // Open the command file
//             FILE *fp = fopen(buf, "r");
//             if (fp != NULL) {
//                 // Read the command name from the file
//                 fgets(buf, sizeof(buf), fp);
//                 // Check if the command name indicates a terminal process
//                 if (strstr(buf, "terminal") != NULL) {
//                     // Print the PID of the terminal process
//                     printf("Terminal process found with PID: %s\n", entry->d_name);
//                 }
//                 // Close the command file
//                 fclose(fp);
//             }
//         }
//     }

//     // Close the /proc directory
//     closedir(dir);
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <dirent.h>

// int main() {
//     DIR *dir;
//     struct dirent *entry;
//     char buf[1024];

//     // Open the /proc directory
//     dir = opendir("/proc");
//     if (dir == NULL) {
//         perror("opendir failed");
//         exit(1);
//     }

//     // Read each entry in the /proc directory
//     while ((entry = readdir(dir)) != NULL) {
//         // Check if the entry is a directory and represents a process
//         if (atoi(entry->d_name) != 0) {
//             // Construct the path to the command file for the process
//             snprintf(buf, sizeof(buf), "/proc/%s/comm", entry->d_name);
//             // Open the command file
//             FILE *fp = fopen(buf, "r");
//             if (fp != NULL) {
//                 // Read the command name from the file
//                 fgets(buf, sizeof(buf), fp);
//                 // Print the command name for debugging
//                 printf("Command for PID %s: %s\n", entry->d_name, buf);
//                 // Check if the command name indicates a terminal process
//                 if (strstr(buf, "terminal") != NULL) {
//                     // Print the PID of the terminal process
//                     printf("Terminal process found with PID: %s\n", entry->d_name);
//                 }
//                 // Close the command file
//                 fclose(fp);
//             }
//         }
//     }

//     // Close the /proc directory
//     closedir(dir);
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <dirent.h>

// int main() {
//     DIR *dir;
//     struct dirent *entry;
//     char buf[1024];

//     // Open the /proc directory
//     dir = opendir("/proc");
//     if (dir == NULL) {
//         perror("opendir failed");
//         exit(1);
//     }

//     // Read each entry in the /proc directory
//     while ((entry = readdir(dir)) != NULL) {
//         // Check if the entry is a directory and represents a process
//         if (atoi(entry->d_name) != 0) {
//             // Construct the path to the command file for the process
//             snprintf(buf, sizeof(buf), "/proc/%s/comm", entry->d_name);
//             // Open the command file
//             FILE *fp = fopen(buf, "r");
//             if (fp != NULL) {
//                 // Read the command name from the file
//                 fgets(buf, sizeof(buf), fp);
//                 // Print the command name for debugging
//                 printf("Command for PID %s: %s\n", entry->d_name, buf);
//                 // Close the command file
//                 fclose(fp);
//             }
//         }
//     }

//     // Close the /proc directory
//     closedir(dir);
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <dirent.h>
// #include <unistd.h>

// void print_fds(int pid) {
//     char path[256];
//     sprintf(path, "/proc/%d/fd", pid);
//     DIR *dir = opendir(path);
//     if (dir == NULL) {
//         perror("opendir failed");
//         return;
//     }
//     struct dirent *entry;
//     while ((entry = readdir(dir)) != NULL) {
//         if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
//             char fd_path[256];
//             sprintf(fd_path, "/proc/%d/fd/%s", pid, entry->d_name);
//             char link[256];
//             ssize_t len = readlink(fd_path, link, sizeof(link) - 1);
//             if (len != -1) {
//                 link[len] = '\0';
//                 printf("File descriptor %s -> %s\n", entry->d_name, link);
//             }
//         }
//     }
//     closedir(dir);
// }

// int main() {
//     // Replace 1234 with the PID of the process you want to inspect
//     print_fds(8);
//     return 0;
// }

// int main() {
//     DIR *dir;
//     struct dirent *entry;
//     char buf[1024];

//     // Open the /proc directory
//     dir = opendir("/proc");
//     if (dir == NULL) {
//         perror("opendir failed");
//         exit(1);
//     }

//     // Read each entry in the /proc directory
//     while ((entry = readdir(dir)) != NULL) {
//         // Check if the entry is a directory and represents a process
//         if (atoi(entry->d_name) != 0) {
//             // Construct the path to the command file for the process
//             snprintf(buf, sizeof(buf), "/proc/%s/comm", entry->d_name);
//             // Open the command file
//             FILE *fp = fopen(buf, "r");
//             if (fp != NULL) {
//                 // Read the command name from the file
//                 fgets(buf, sizeof(buf), fp);
//                 // Print the command name for debugging
//                 printf("Command for PID %s: %s\n", entry->d_name, buf);
//                 // Close the command file
//                 fclose(fp);
//             }
//         }
//     }

//     // Close the /proc directory
//     closedir(dir);
//     return 0;
// }
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <dirent.h>

// char **retrieve_fds() {
//     DIR *dir;
//     struct dirent *ent;
//     char **fds = malloc(256 * sizeof(char *));
//     if (fds == NULL) {
//         perror("Error allocating memory");
//         return NULL;
//     }
//     int i = 0;
//     // Open the /proc directory
//     if ((dir = opendir("/proc")) != NULL) {
//         // Iterate through each entry in the /proc directory
//         while ((ent = readdir(dir)) != NULL) {
//             // Check if the entry is a numeric directory representing a process
//             if (atoi(ent->d_name) != 0) {
//                 // Construct the path to the /proc/[PID]/fd directory
//                 char fd_path[256];
//                 snprintf(fd_path, sizeof(fd_path), "/proc/%s/fd", ent->d_name);
//                 DIR *fd_dir = opendir(fd_path);
//                 if (fd_dir != NULL) {
//                     // Iterate through the /proc/[PID]/fd directory
//                     struct dirent *fd_ent;
//                     while ((fd_ent = readdir(fd_dir)) != NULL) {
//                         // Exclude "." and ".." entries
//                         if (strcmp(fd_ent->d_name, ".") != 0 && strcmp(fd_ent->d_name, "..") != 0) {
//                             // Allocate memory for the file descriptor path
//                             fds[i] = malloc((strlen(fd_path) + strlen(fd_ent->d_name) + 2) * sizeof(char));
//                             if (fds[i] == NULL) {
//                                 perror("Error allocating memory for file descriptor path");
//                                 return NULL;
//                             }
//                             // Construct the full file descriptor path
//                             snprintf(fds[i], 256, "%s/%s", fd_path, fd_ent->d_name);
//                             i++;
//                         }
//                     }
//                     closedir(fd_dir);
//                 }
//             }
//         }
//         closedir(dir);
//     } else {
//         perror("Error opening /proc directory");
//         return NULL;
//     }
//     // Null-terminate the array of file descriptors
//     fds[i] = NULL;
//     return fds;
// }

// int main() {
//     char **fds = retrieve_fds();
//     if (fds != NULL) {
//         for (int i = 0; fds[i] != NULL; i++) {
//             printf("File descriptor %d: %s\n", i + 1, fds[i]);
//             free(fds[i]);
//         }
//         free(fds);
//     }
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <dirent.h>
// #include <unistd.h>

// int is_terminal_process(const char *pid) {
//     char comm_path[256];
//     snprintf(comm_path, sizeof(comm_path), "/proc/%s/comm", pid);
//     FILE *fp = fopen(comm_path, "r");
//     if (fp != NULL) {
//         char comm[256];
//         fgets(comm, sizeof(comm), fp);
//         fclose(fp);
//         // Check if the command name indicates a terminal process
//         if (strstr(comm, "terminal") != NULL) {
//             return 1;
//         }
//     }
//     return 0;
// }

// char **retrieve_terminal_fds() {
//     DIR *dir;
//     struct dirent *ent;
//     char **fds = malloc(256 * sizeof(char *));
//     if (fds == NULL) {
//         perror("Error allocating memory");
//         return NULL;
//     }
//     int i = 0;
//     // Open the /proc directory
//     if ((dir = opendir("/proc")) != NULL) {
//         // Iterate through each entry in the /proc directory
//         while ((ent = readdir(dir)) != NULL) {
//             // Check if the entry is a numeric directory representing a process
//             if (atoi(ent->d_name) != 0) {
//                 // Check if the process is a terminal process
//                 if (is_terminal_process(ent->d_name)) {
//                     // Construct the path to the /proc/[PID]/fd directory
//                     char fd_path[256];
//                     snprintf(fd_path, sizeof(fd_path), "/proc/%s/fd", ent->d_name);
//                     DIR *fd_dir = opendir(fd_path);
//                     if (fd_dir != NULL) {
//                         // Iterate through the /proc/[PID]/fd directory
//                         struct dirent *fd_ent;
//                         while ((fd_ent = readdir(fd_dir)) != NULL) {
//                             // Exclude "." and ".." entries
//                             if (strcmp(fd_ent->d_name, ".") != 0 && strcmp(fd_ent->d_name, "..") != 0) {
//                                 // Construct the full file descriptor path
//                                 char full_fd_path[256];
//                                 snprintf(full_fd_path, sizeof(full_fd_path), "%s/%s", fd_path, fd_ent->d_name);
//                                 // Allocate memory for the file descriptor path
//                                 fds[i] = malloc((strlen(full_fd_path) + 1) * sizeof(char));
//                                 if (fds[i] == NULL) {
//                                     perror("Error allocating memory for file descriptor path");
//                                     return NULL;
//                                 }
//                                 strcpy(fds[i], full_fd_path);
//                                 i++;
//                             }
//                         }
//                         closedir(fd_dir);
//                     }
//                 }
//             }
//         }
//         closedir(dir);
//     } else {
//         perror("Error opening /proc directory");
//         return NULL;
//     }
//     // Null-terminate the array of terminal file descriptors
//     fds[i] = NULL;
//     return fds;
// }

// int main() {
//     char **terminal_fds = retrieve_terminal_fds();
//     if (terminal_fds != NULL) {
//         for (int i = 0; terminal_fds[i] != NULL; i++) {
//             printf("Terminal file descriptor %d: %s\n", i + 1, terminal_fds[i]);
//             free(terminal_fds[i]);
//         }
//         free(terminal_fds);
//     }
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int ac, char **av) {
    if (ac != 2) {
        fprintf(stderr, "Usage: %s <terminal_device>\n", av[0]);
        return EXIT_FAILURE;
    }

    char *tty_name = av[1]; // Get the terminal file name
    printf("Terminal device: %s\n", tty_name);

    // Open the target terminal's file descriptor
    int fd = open(tty_name, O_WRONLY);
    if (fd == -1) {
        perror("open");
        return EXIT_FAILURE;
    }

    while (1) {
        char message[1000];
        printf("Enter message to write to terminal: ");
        fgets(message, sizeof(message), stdin);

        // Write the message to the terminal
        if (write(fd, message, strlen(message)) == -1) {
            perror("write");
            close(fd);
            return EXIT_FAILURE;
        }
    }

    // Close the file descriptor (this part of the code is unreachable)
    close(fd);

    return 0;
}
