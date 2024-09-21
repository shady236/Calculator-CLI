#ifndef  _STACK_H_
#define  _STACK_H_

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


typedef struct Stack_t {
    void* data;
    int size;
    int capacity;
    int elemSize;
    void (*printElem)(const void* const);
} Stack_t;


bool Stack_Init(Stack_t* const stack, const int initCap, const int elemSize, void (* const printElem)(const void* const));
bool Stack_Push(Stack_t* const stack, const void* const data);
bool Stack_Peek(Stack_t* const stack, void* const data);
bool Stack_Pop(Stack_t* const stack, void* const data);
int  Stack_Size(Stack_t* const stack);
bool Stack_IsEmpty(Stack_t* const stack);
bool Stack_Print(Stack_t* const stack);
bool Stack_Free(Stack_t* const stack);



#endif  /* _STACK_H_ */