#pragma once
#include "domain.h"
#include <string.h>

Offer CreateOffer(char type[], char destination[], char departure[], int price){
    Offer offer;
    strcpy(offer.type, type);
    strcpy(offer.destination, destination);
    strcpy(offer.departure, departure);
    offer.price = price;
    return offer;
}
