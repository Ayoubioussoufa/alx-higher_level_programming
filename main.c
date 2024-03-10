#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>

int main(int ac, char **av) {
    if (ac != 2) {
        printf("1st parameter : program name | 2nd parameter : the reference to the other terminal.");
        return 1;
    }

    struct stat file_stat;

    if (lstat(av[1], &file_stat) == -1) {
        perror("lstat");
        return 1;
    }
    if (S_ISCHR(file_stat.st_mode) || S_ISFIFO(file_stat.st_mode)) {
        ;
    } else if (S_ISREG(file_stat.st_mode)) {
        printf("%s is a regular file, please enter the other's terminal reference\n", av[1]);
        return 1;
    } else {
        printf("%s is neither a terminal device nor a regular file, please enter the other's terminal referenc\n", av[1]);
        return 1;
    }
    while (1)
    {
        int fd;
        // Open the target terminal's file
        fd = open(av[1], O_WRONLY);
        if (fd == -1) {
            perror("open");
            exit(1);
        }
        char message[1024];
        fgets(message, sizeof(message), stdin);
        printf("Currently writing here : ");
        // // Write the message to the other terminal
        if (write(fd, message, strlen(message)) == -1) {
            perror("write");
            close(fd);
            exit(1);
        }
        close(fd);
    }
    return 0;
}