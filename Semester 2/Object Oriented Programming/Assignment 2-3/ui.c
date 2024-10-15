#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ui.h"
#define MAX_SIZE 20

void print_offers(Services services){
    Repository* repo = GetRepo(services);
    int size = GetRepoSize(repo);
    for (int i = 0; i < size; i++) {
        Offer* offer = &(repo->offers->elements[i]);
        printf("Type :");
        puts(offer->type);
        printf("Destination :");
        puts(offer->destination);
        printf("Departure :");
        puts(offer->departure);
        printf("Price: %d \n", offer->price);
        printf("\n");
    }
}

void run(){
    int option;
    char type[MAX_SIZE], destination[MAX_SIZE], departure[MAX_SIZE];
    int price;
    Repository repo = GetInitialOffers();
    OperationStack* undo = CreateStack();
    OperationStack* redo = CreateStack();
    Services services = CreateServices(&repo, undo, redo);
    printf("These are the initial offers: \n");
    print_offers(services);
    while (1){
        printf("1. Add offer \n");
        printf("2. Remove offer \n");
        printf("3. Update offer \n");
        printf("4. Display all tourism offers based for a given destination, in asceniding order by price \n");
        printf("5. Display all tourism offers of a certain type, having departure after a chosen date \n");
        printf("6. Undo \n");
        printf("7. Redo \n");
        printf("0. Exit program \n");
        printf("Enter your option: \n");
        scanf("%d", &option);
        while (getchar() != '\n');
        if (option == 0){
            printf("Goodbye!");
            break;
        }
        else if (option == 1){
            printf("Enter the type of offer:");
            fgets(type, sizeof(type), stdin);
            type[strcspn(type, "\n")] = '\0';
            printf("Enter the destination:");
            fgets(destination, sizeof(destination), stdin);
            destination[strcspn(destination, "\n")] = '\0';
            printf("Enter the departure date:");
            fgets(departure, sizeof(departure), stdin);
            departure[strcspn(departure, "\n")] = '\0';
            printf("Enter the price:");
            scanf("%d", &price);
            while (getchar() != '\n');
            AddOfferController(services, type, destination,departure, price);
            print_offers(services);
        }
        else if (option == 2){
            printf("Enter the destination: ");
            fgets(destination, sizeof(destination), stdin);
            destination[strcspn(destination, "\n")] = '\0';
            printf("Enter the departure date: ");
            fgets(departure, sizeof(departure), stdin);
            departure[strcspn(departure, "\n")] = '\0';
            RemoveOfferController(services, destination, departure);
            print_offers(services);
        }
        else if(option == 3){
            printf("Enter the destination: ");
            fgets(destination, sizeof(destination), stdin);
            destination[strcspn(destination, "\n")] = '\0';
            printf("Enter the departure date: ");
            fgets(departure, sizeof(departure), stdin);
            departure[strcspn(departure, "\n")] = '\0';
            printf("Enter the new price: ");
            scanf("%d", &price);
            while(getchar() != '\n');
            UpdateOfferController(services, destination, departure, price);
            print_offers(services);
        }
        else if(option == 4){
            printf("Enter a string for which you want to see the offers: ");
            fgets(destination, sizeof(destination), stdin);
            destination[strcspn(destination, "\n")] = '\0';
            int result_size = 0;
            Offer* filtered_offers = GetOffersByDestinationController(destination, services, &result_size);
            printf("Offers found: \n");
            for(int i = 0; i < result_size; i++){
                printf("Type: %s\n", filtered_offers[i].type);
                printf("Destination: %s\n", filtered_offers[i].destination);
                printf("Departure date: %s\n", filtered_offers[i].departure);
                printf("Price: %d\n", filtered_offers[i].price);
                printf("\n");
            }
            free(filtered_offers);
        }
        else if(option == 5){
            printf("Enter the type of offer you wish to see: ");
            fgets(type, sizeof(type), stdin);
            type[strcspn(type, "\n")] = '\0';
            printf("Enter the departure date after which you want to see offers: ");
            fgets(departure, sizeof(departure), stdin);
            departure[strcspn(departure, "\n")] = '\0';
            int result_size = 0;
            Offer* filtered_offers = GetOffersByTyperController(departure, type, services, &result_size);
            printf("Offers found: \n");
            for(int i = 0; i < result_size; i++){
                printf("Type: %s\n", filtered_offers[i].type);
                printf("Destination: %s\n", filtered_offers[i].destination);
                printf("Departure date: %s\n", filtered_offers[i].departure);
                printf("Price: %d\n", filtered_offers[i].price);
                printf("\n");
            }
            free(filtered_offers);
        }
        else if(option == 6){
            Undo(services);
        }
        else if(option == 7){
            Redo(services);
        }
        else{
            printf("Incorrect input, please try again. \n");
        }
    }
    DestroyStack(undo);
    DestroyRepo(&repo);
}

