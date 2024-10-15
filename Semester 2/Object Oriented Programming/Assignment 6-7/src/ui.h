#pragma once
#include "controller.h"
#include "movies.h"
#include "file_writer.h"

class UI{
private:
    Controller controller;
    string filename, type, file_read;
public:
    UI();
    void run();

    void printMovies();

    void printWatchlist();

    void run_administartor();

    void run_user();

    void saveToFile();

    void displayFile();
};
