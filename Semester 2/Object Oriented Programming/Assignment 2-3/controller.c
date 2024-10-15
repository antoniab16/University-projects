#include "controller.h"
#include <string.h>
#include <assert.h>

Services CreateServices(Repository* repo, OperationStack* undo_stack, OperationStack* redo_stack){
    Services services;
    services.repo = repo;
    services.stack_undo = undo_stack;
    services.stack_redo = redo_stack;
    return services;
}

Repository* GetRepo(Services services){
    return services.repo;
}

Services AddOfferController(Services services, char type[], char destination[], char departure[], int price){
    Offer offer = CreateOffer(type, destination, departure, price);
    AddOffer(offer, services.repo);
    Operation* operation = CreateOperation(&offer, "add");
    Push(services.stack_undo, operation);
    return services;
}

int Undo(Services services){
    if(isEmpty(services.stack_undo))
        return 0;
    Operation* operation = Pop(services.stack_undo);
    if(operation == NULL)
        return 0;
    if(operation->type_operation != NULL && strcmp(operation->type_operation, "add") == 0){
        Offer* offer = operation->offer;
        if(offer == NULL) {
            DestroyOperation(operation);
            return 0;
        }
        char destination[30],  departure[30];
        strcpy(destination, offer->destination);
        strcpy(departure, offer->departure);
        RemoveOffer(destination, departure, services.repo);
        Operation* operation_redo = CreateOperation(GetOffer(operation), "add");
        Push(services.stack_redo, operation_redo);
    }
    DestroyOperation(operation);
    return 1;
}

int Redo(Services services){
    if(isEmpty(services.stack_redo))
        return 0;
    Operation* operation = Pop(services.stack_redo);
    if(operation == NULL)
        return 0;
    if(operation->type_operation != NULL && strcmp(operation->type_operation, "add") == 0) {
        Offer *offer = operation->offer;
        if (offer == NULL) {
            DestroyOperation(operation);
            return 0;
        }
        char type[30], destination[30], departure[30];
        int price;
        strcpy(type, offer->type);
        strcpy(destination, offer->destination);
        strcpy(departure, offer->departure);
        price = offer->price;
        AddOfferController(services, type, destination, departure, price);
    }
    DestroyOperation(operation);
    return 1;
}

Services RemoveOfferController(Services services, char destination[], char departure[]){
    RemoveOffer(destination, departure, services.repo);
    return services;
}

Services UpdateOfferController(Services services, char destination[], char departure[], int price){
    UpdateOffer(destination, departure, price, services.repo);
    return services;
}

Offer* GetOffersByDestinationController(char destination[], Services services, int* result_size){
    Repository* repo = services.repo;
    int filtered_size;
    Offer* filtered_offers = GetOffersByDestination(destination, repo, &filtered_size);
    *result_size = filtered_size;
    return filtered_offers;
}


Offer* GetOffersByTyperController(char departure[], char type[], Services services, int* result_size){
    int filtered_size;
    Offer* filtered_offers = GetOffersByTyper(departure, type, services.repo, &filtered_size);
    *result_size = filtered_size;
    return filtered_offers;
}

void test_functionalities(){
    Repository repo = GetInitialOffers();
    OperationStack* undo = CreateStack();
    OperationStack* redo = CreateStack();
    Services services = CreateServices(&repo, undo, redo);
    services = AddOfferController(services, "seaside", "Test destination", "20.04", 100);
    assert(GetRepoSize(services.repo) == 11);
    services = RemoveOfferController(services, "Test destination", "20.04");
    assert(GetRepoSize(services.repo) == 10);
    int result_undo = Undo(services);
    assert(result_undo == 1);
    DestroyStack(undo);
    int result_redo = Redo(services);
    assert(result_undo == 1);
    DestroyStack(redo);

}