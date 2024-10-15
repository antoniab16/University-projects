#pragma once
#include "dynamic_array.h"

class Repository{
private:
    DynamicVector<Movie> movies;

public:
    Repository();
    void addMovie(Movie movie);
    DynamicVector<Movie> getAllMovies();
    void removeMovie(const string& title, int year);
    void getInitialMovies();
    void updateMovie(string title, int year, string newGenre, int newLikes, string newTrailer);
    void test_construct_repo();
    void test_add_movie();
    void test_remove_movie();
    void test_update_movie();
    void test_get_intial_movies();
    void test_get_all_movies();
    DynamicVector<Movie> getMoviesByGenre(string genre);

    void test_get_movies_by_genre();
};