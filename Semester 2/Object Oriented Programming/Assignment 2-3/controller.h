#pragma once
#include "repository.h"
#include "operation_stack.h"

typedef struct {
    Repository* repo;
    OperationStack* stack_undo;
    OperationStack* stack_redo;
}Services;

Services CreateServices(Repository* repo, OperationStack* undo_stack, OperationStack* redo_stack);

Repository* GetRepo(Services services);

Services AddOfferController(Services services, char type[], char destination[], char departure[], int price);

Services RemoveOfferController(Services services, char destination[], char departure[]);

Services UpdateOfferController(Services services, char destination[], char departure[], int price);

Offer* GetOffersByDestinationController(char destination[], Services services, int* result_size);

Repository* DestroyService(Services services);

Offer* GetOffersByTyperController(char departure[], char type[], Services services, int* result_size);

int Undo(Services services);

int Redo(Services services);

void test_functionalities();