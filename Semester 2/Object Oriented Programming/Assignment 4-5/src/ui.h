#pragma once
#include "controller.h"
#include "movies.h"

class UI{
private:
    Controller controller;

public:
    UI();
    void run();

    void printMovies();

    void printWatchlist();

    void run_administartor();

    void run_user();
};
