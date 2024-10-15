#pragma once
#include "domain.h"

typedef Offer TElement;


typedef struct{
    TElement* elements;
    int length;
    int capacity;
}DynamicVector;

DynamicVector* CreateDynamicVector(int capacity);

void DestroyDynamicVector(DynamicVector* vector);

void ResizeDynamicVector(DynamicVector* vector);

void AddElement(DynamicVector* vector, TElement element);

int GetCapaacity(DynamicVector* vector);

int GetSize(DynamicVector* vector);

void RemoveElement(DynamicVector* vector, int index);

DynamicVector* Copy(DynamicVector* original);

Offer* Get(DynamicVector* vector, int pos);