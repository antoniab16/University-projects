#pragma once
#include "dynamic_vector.h"

typedef struct{
    Offer* offer;
    char* type_operation;
}Operation;

typedef struct {
    DynamicVector* stack;
}OperationStack;

Operation* CreateOperation(Offer* offer, char* type_operation);

void DestroyOperation(Operation* o);

char* GetOperationType(Operation* o);

OperationStack* CreateStack();

void DestroyStack(OperationStack* s);

void Push(OperationStack* s, Operation* o);

Operation* Pop(OperationStack* s);

int isEmpty(OperationStack* s);

Offer* GetOffer(Operation* operation);