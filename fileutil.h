#ifndef FILEUTIL_H
#define FILEUTIL_H

char **loadFileAA(char *filename, int *size);
char *substringSearchAA(char *target, char **arr, int size);
void freeAA(char **arr, int size);

#endif
