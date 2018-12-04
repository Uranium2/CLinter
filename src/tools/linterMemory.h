//
// Created by theo on 03/12/18.
//

#ifndef CLINTER_LINTERMEMORY_H
#define CLINTER_LINTERMEMORY_H


typedef struct LinterMemory {
    char *type;
    int line;
    int position;
    char *filename;
    struct LinterMemory* next;
} LinterMemory;

LinterMemory* addElement(char *,int line, int position, char *filename);
void freeLinterMemory(LinterMemory *);
void printLinterMemory(LinterMemory *);

#endif //CLINTER_LINTERMEMORY_H
