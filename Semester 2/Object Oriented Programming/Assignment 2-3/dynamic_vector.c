#include "dynamic_vector.h"
#include <stdlib.h>

DynamicVector* CreateDynamicVector(int capacity){
    DynamicVector* vector = malloc(sizeof(DynamicVector));
    if(vector == NULL)
        return NULL;
    vector->capacity = capacity;
    vector->length = 0;
    vector->elements = malloc(capacity * sizeof(TElement));
    if(vector->elements == NULL)
        return NULL;
    return vector;
}

void DestroyDynamicVector(DynamicVector* vector){
    if(vector == NULL)
        return;
    free(vector->elements);
    vector->elements = NULL;
    free(vector);
}

void ResizeDynamicVector(DynamicVector* vector){
    if(vector == NULL)
        return;
    vector->capacity *= 2;
    TElement* copy = realloc(vector->elements, vector->capacity * sizeof(TElement));
    if(copy == NULL)
        return;
    vector->elements = copy;
}

void AddElement(DynamicVector* vector, TElement element){
    if(vector == NULL)
        return;
    if(vector->elements == NULL)
        return;
    if(vector->length == vector->capacity)
        ResizeDynamicVector(vector);
    vector->elements[vector->length] = element;
    vector->length++;
}


void RemoveElement(DynamicVector* vector, int index){
    if(vector == NULL || index < 0 || index > vector->length)
        return;
    for(int i = index; i < vector->length; i++)
        vector->elements[i] = vector->elements[i+1];
    vector->length--;
}


int GetCapaacity(DynamicVector* vector){
    if(vector == NULL)
        return 0;
    return vector->capacity;
}

int GetSize(DynamicVector* vector){
    if(vector == NULL)
        return 0;
    return vector->length;
}

Offer* Get(DynamicVector* vector, int pos)
{
    if (vector == NULL)
        return NULL;
    if (pos < 0 || pos >= vector->length)
        return NULL;
    return &vector->elements[pos];
}

