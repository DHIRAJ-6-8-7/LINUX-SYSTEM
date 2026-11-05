#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

int main() {
    DIR *dir = opendir(".");

    if (dir == NULL) {
        perror("Unable to open directory");
        return EXIT_FAILURE;
    }

    struct dirent *entry;

    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);

    return EXIT_SUCCESS;
}