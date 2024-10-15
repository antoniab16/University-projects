#pragma once
#include "dynamic_array.h"
#include "repository.h"
#include "controller.h"
#include "movies.h"
#include "watchlist.h"
#include <iostream>

class Tests{
private:
    void testDynamicVector();
    void testRepository();
    void testController();
    void testMovies();
    void testWatchlist();
public:
    void testAll();

};