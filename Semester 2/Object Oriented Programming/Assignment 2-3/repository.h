#pragma once
#include "domain.h"
#include "dynamic_vector.h"

typedef struct{
    DynamicVector* offers;
}Repository;

Repository CreateRepository();

void AddOffer(Offer offer, Repository* repo);

int GetRepoSize(Repository* repo);

void RemoveOffer(char destination[], char departure[], Repository* repo);

void UpdateOffer(char destination[], char departure[], int price, Repository* repo);

Repository GetInitialOffers();

Offer* GetOffersByDestination(char destination[], Repository* repo, int* result_size);

void DestroyRepo(Repository* repo);

Offer* GetOffersByTyper(char departure[], char type[], Repository* repo, int* result_size);