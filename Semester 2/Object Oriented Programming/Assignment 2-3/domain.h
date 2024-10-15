#pragma once
typedef struct{
    char type[30], destination[30] , departure[30];
    int price;
}Offer;

Offer CreateOffer(char type[], char destination[], char departure[], int price);
