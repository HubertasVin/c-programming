#ifndef FILE_H
#define FILE_H

extern int saveCount;
extern int loadCount;

void saveToFile(int n, int Arr[], char *fileName);
int loadFromFile(int arraySize, int Arr[], char *fileName);

#endif