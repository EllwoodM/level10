#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileutil.h"

#define MAX_LINE 1024

char **loadFileAA(char *filename, int *size) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("Error opening file");
        return NULL;
    }

    char **lines = NULL;
    char buffer[MAX_LINE];
    *size = 0;

    while (fgets(buffer, MAX_LINE, fp)) {
        buffer[strcspn(buffer, "\n")] = '\0';  // Strip newline

        char *line = malloc(strlen(buffer) + 1);
        if (!line) {
            perror("Memory allocation failed");
            fclose(fp);
            return NULL;
        }
        strcpy(line, buffer);

        char **temp = realloc(lines, (*size + 1) * sizeof(char *));
        if (!temp) {
            perror("Memory reallocation failed");
            free(line);
            fclose(fp);
            return NULL;
        }
        lines = temp;
        lines[*size] = line;
        (*size)++;
    }

    fclose(fp);
    return lines;
}

char *substringSearchAA(char *target, char **arr, int size) {
    for (int i = 0; i < size; i++) {
        if (strstr(arr[i], target)) {
            return arr[i];
        }
    }
    return NULL;
}

void freeAA(char **arr, int size) {
    for (int i = 0; i < size; i++) {
        free(arr[i]);
    }
    free(arr);
}
