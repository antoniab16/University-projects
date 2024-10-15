#include "operation_stack.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

Operation* CreateOperation(Offer* offer, char* type_operation)
{
    Operation* o = malloc(sizeof(Operation));
    if (o == NULL)
        return NULL;
    o->offer = offer;

    if (type_operation != NULL)
    {
        o->type_operation = malloc(sizeof(char) * (strlen(type_operation) + 1));
        if (o->type_operation == NULL)
        {
            free(o);
            return NULL;
        }
        strcpy(o->type_operation, type_operation);
    }
    else
        o->type_operation = NULL;

    return o;
}

Offer* GetOffer(Operation* operation){
    return operation->offer;
}

void DestroyOperation(Operation* o)
{
    if (o == NULL)
        return;
    free(o->type_operation);
    free(o);
}

char* GetOperationType(Operation* o)
{
    return o->type_operation;
}

OperationStack* CreateStack()
{
    OperationStack* s = malloc(sizeof(OperationStack));
    if (s == NULL)
        return NULL;
    s->stack = CreateDynamicVector(10);
    if (s->stack == NULL)
    {
        free(s);
        return NULL;
    }
    return s;
}

void DestroyStack(OperationStack* s)
{
    if (s == NULL)
        return;
    DestroyDynamicVector(s->stack);
    free(s);
}

void Push(OperationStack* s, Operation* o)
{
    if (s == NULL || o == NULL)
        return;
    Offer offer = *GetOffer(o);
    AddElement(s->stack, offer);
}

Operation* Pop(OperationStack* s)
{
    if (s == NULL)
        return NULL;
    int lastPos = GetSize(s->stack) - 1;
    Operation* lastOp = (Operation*) Get(s->stack, lastPos);
    RemoveElement(s->stack, lastPos);
    return lastOp;
}

int isEmpty(OperationStack* s)
{
    if (s == NULL)
        return 1;
    return (GetSize(s->stack) == 0);
}


