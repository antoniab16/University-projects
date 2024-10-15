#pragma once
#include "repository.h"
#include "watchlist.h"
#include "file_repo.h"

class Controller{
private:
    Repository repo;
    FileRepository fileRepo;
    Watchlist watchlist;
    int currentMovieIndex;
    string currentGenre;

public:
    Controller();
    std::string  addMovie(std::string title, std::string genre, int year, int likes, std::string trailer);
    DynamicVector<Movie> getAllMovies();
    std::string  removeMovie(std::string title, int year);
    std::string  updateMovie(std::string title, int year, std::string newGenre, int newLikes, std::string newTrailer);
    void test_construct_controller();
    void test_add_movie();
    void test_remove_movie();
    void test_update_movie();
    DynamicVector<Movie> getMoviesByGenre(const std::string& genre);
    Movie nextMovie();
    void addToWatchlist(const Movie& movie);
    DynamicVector<Movie> getWatchlist();
    void removeFromWatchlist(const string& title, int year);
    void setFile(std::string filename);
    void writeToFile(std::string filename);
    void test_get_movies_by_genre();

    void test_next_movie();

    void test_add_watchlist();

    void test_remove_watchlist();
};