#include "Stack.h"


bool Stack_Init(Stack_t* const stack, const int initCap, const int elemSize, void (* const printElem)(const void* const)) {
    if (stack == NULL || initCap <= 0) {
        return false;
    }

    stack->data = malloc(initCap * elemSize);
    if (stack->data == NULL) {
        return false;
    }

    stack->elemSize = elemSize;
    stack->capacity = initCap;
    stack->size = 0;
    stack->printElem = printElem;
    return true;
}

bool Stack_Push(Stack_t* const stack, const void* const data) {
    if (stack->size >= stack->capacity) {
        void* newData = realloc(stack->data, 2 * stack->capacity * stack->elemSize);
        if (newData == NULL) {
            return false;
        }

        stack->data = newData;
        stack->capacity *= 2;
    }

    memcpy(stack->data + stack->size * stack->elemSize, data, stack->elemSize);
    stack->size++;
}

bool Stack_Peek(Stack_t* const stack, void* const data) {
    if (stack->size == 0) {
        return false;
    }

    stack->size--;
    memcpy(data, stack->data + stack->size * stack->elemSize, stack->elemSize);
    stack->size++;
    return true;
}

bool Stack_Pop(Stack_t* const stack, void* const data) {
    if (stack->size == 0) {
        return false;
    }

    stack->size--;
    memcpy(data, stack->data + stack->size * stack->elemSize, stack->elemSize);
    return true;
}

int Stack_Size(Stack_t* const stack) {
    if (stack == NULL) {
        return 0;
    }
    return stack->size;
}

bool Stack_IsEmpty(Stack_t* const stack) {
    return (stack == NULL) || (stack->size == 0);
}

bool Stack_Print(Stack_t* const stack) {
    for (int i = 0; i < stack->size; i++) {
        stack->printElem(stack->data + i * stack->elemSize);
        printf(" ");
    }
    printf("\n");
}

bool Stack_Free(Stack_t* const stack) {
    if (stack != NULL) {
        free(stack->data);
        stack->capacity = 0;
        stack->size = 0;
    }
}
