#include "repository.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Repository CreateRepository(){
    Repository repo;
    repo.offers = CreateDynamicVector(10);
    return repo;
}

void AddOffer(Offer offer, Repository* repo){
    AddElement(repo->offers, offer);
}


int GetRepoSize(Repository* repo){
    return GetSize(repo->offers);
}

void RemoveOffer(char destination[], char departure[], Repository* repo){
    int index = -1;
    for (int i = 0; i < GetRepoSize(repo); i++)
    {
        Offer* offer = &(repo->offers->elements[i]);
        if (strcmp(offer->destination, destination) == 0 && strcmp(offer->departure, departure) == 0 ){
            index = i;
            RemoveElement(repo->offers, i);
        }
    }
    if (index == -1)
        printf("Offer not found \n");
}

void UpdateOffer(char destination[], char departure[], int price, Repository* repo){
    int found = 0;
    for (int i = 0; i < GetRepoSize(repo); i++)
    {
        Offer* offer = &(repo->offers->elements[i]);
        if (strcmp(offer->destination, destination) == 0 && strcmp(offer->departure, departure) == 0 ) {
            offer->price = price;
            found = 1;
        }
    }
    if (found == 0)
        printf("Offer does not exist\n");
}

Repository GetInitialOffers(){
    int k = 0;
    const char* types[] = {"seaside", "mountain", "city break"};
    const char* destinations[] = {"Spain", "Iceland", "London", "Dubai", "Dublin", "New York",
                                  "Greece", "Switzerland", "Tokyo", "Bali", "Romania"};
    const char* departure_dates[] = {"20.03", "10.08", "28.09", "18.07", "11.11", "03.02", "14.05",
                                     "21.10", "01.06", "08.08", "03.12"};
    int prices[10] = {500, 800, 300, 1000, 750, 200, 325, 600, 1200, 100};
    Repository  repo = CreateRepository();
    for (int i = 0; i < 10; i++){
        if(k % 3 == 0)
            k = 0;
        Offer offer = CreateOffer(types[k], destinations[i], departure_dates[i], prices[i]);
        AddOffer(offer, &repo);
        k++;
    }
    return repo;
}

Offer* GetOffersByDestination(char destination[], Repository* repo, int* result_size){
    int filtered_size = 0;
    Offer* filtered_offers = malloc(GetRepoSize(repo)* sizeof(Offer));
    if(filtered_offers == NULL){
        return NULL;
    }
    for (int i = 0; i < GetRepoSize(repo); i++)
    {
        Offer* offer = &(repo->offers->elements[i]);
        if (destination[0] == '\0' || strstr(offer->destination, destination) != NULL)
            filtered_offers[filtered_size++] = *offer;
    }
    filtered_offers = realloc(filtered_offers, filtered_size * sizeof (Offer));
    if (filtered_offers == NULL && filtered_size == 0){
        *result_size = 0;
        return NULL;
    }
    for (int i = 0; i < filtered_size - 1; i++)
    {
        for (int j = i + 1; j < filtered_size; j++)
        {
            if (filtered_offers[i].price > filtered_offers[j].price){
            Offer copy = filtered_offers[i];
            filtered_offers[i] = filtered_offers[j];
            filtered_offers[j] = copy;
            }
        }
    }
    *result_size = filtered_size;
    return filtered_offers;
}

int CompareDate(char date1[], char date2[]){
    int compare_month = strncmp(date1 + 3, date2 + 3, 2);
    if(compare_month != 0)
        return compare_month;
    return strncmp(date1, date2, 2);
}

Offer* GetOffersByTyper(char departure[], char type[], Repository* repo, int* result_size){
    int filtered_size = 0;
    Offer* filtered_offers = malloc(GetRepoSize(repo)* sizeof(Offer));
    for (int i = 0; i < GetRepoSize(repo); i++)
    {
        Offer* offer = &(repo->offers->elements[i]);
        if (strcmp(offer->type, type) == 0){
            if(CompareDate(offer->departure, departure) > 0)
                filtered_offers[filtered_size++] = *offer;
        }
    }
    filtered_offers = realloc(filtered_offers, filtered_size * sizeof (Offer));
    if (filtered_offers == NULL && filtered_size == 0){
        *result_size = 0;
        return NULL;
    }
    *result_size = filtered_size;
    return filtered_offers;
}

void DestroyRepo(Repository* repo){
    DestroyDynamicVector(repo->offers);
}