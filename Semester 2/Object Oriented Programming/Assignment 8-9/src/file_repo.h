#pragma once
#include <iostream>
#include "repository.h"

class FileRepository : public Repository{
private:
    std::string filename;
    DynamicVector<Movie> movies;
public:
    FileRepository(std::string filename = "");
    void addMovie(Movie movie) override;
    void removeMovie(const std::string &title, int year) override;
    void updateMovie(std::string title, int year, std::string newGenre, int newLikes, std::string newTrailer) override;
    DynamicVector<Movie> getAllMovies() override;
    int findMovies(std::string, int year);
    void writeToFile(DynamicVector<Movie> movies);
    int findIndexMovie(string title, int year);
};

