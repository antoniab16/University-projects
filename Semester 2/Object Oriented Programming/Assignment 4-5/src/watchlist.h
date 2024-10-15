#pragma once
#include "movies.h"
#include "dynamic_array.h"

class Watchlist {
private:
    DynamicVector<Movie>movies;

public:
    Watchlist(){

    };

    void addToWatchlist(Movie movie);

    void removeFromWatchlist(const std::string& title, int year);

    DynamicVector<Movie> getWatchlist();

    int getLength();

    Movie& operator[](int index);

    void test_add_watchlist();

    void test_remove_watchlist();

    void test_get_watchlist();

    void test_operator_watchlist();

    void test_get_length();
};