#include <cassert>
#include "controller.h"
#include <iostream>

/// Constructor for the Controller class
Controller::Controller() : repo(Repository()), watchlist(Watchlist()) {
    repo.getInitialMovies();
}

/// Takes title, genre, year, likes and trailer of a movie as parameters and creates a new Movie object which is then
/// added to the repository using addMovie form Repository
void Controller::addMovie(std::string title, std::string genre, int year, int likes, std::string trailer) {
    Movie m = Movie(title, genre, year, likes, trailer);
    this->repo.addMovie(m);
}

/// Returns all the movies from the repository
DynamicVector<Movie> Controller::getAllMovies() {
    return this->repo.getAllMovies();
}

/// Takes title and year of a movie as parameters and removes the movie with the given title and year from the
/// repository using removeMovie from Repository
void Controller::removeMovie(std::string title, int year) {
    this->repo.removeMovie(title, year);
}

/// Takes title, year of a movie and new genre, new number of likes and new trailer as parameters and updates the movie
/// using updateMovie from Repository
void Controller::updateMovie(std::string title, int year, std::string newGenre, int newLikes, std::string newTrailer) {
    this->repo.updateMovie(title, year, newGenre, newLikes, newTrailer);
}

void Controller::test_add_movie() {
    Controller controller;
    controller.addMovie("Title", "Genre", 2004, 1000, "Trailer");
    DynamicVector<Movie> movies = controller.getAllMovies();
    assert(movies.getLength() == 11);
}

void Controller::test_remove_movie() {
    Controller controller;
    controller.addMovie("Title", "Genre", 2004, 1000, "Trailer");
    controller.removeMovie("Title", 2004);
    DynamicVector<Movie> movies = controller.getAllMovies();
    assert(movies.getLength() == 10);

}

void Controller::test_update_movie() {
    Controller controller;
    controller.addMovie("Title", "Genre", 2004, 1000, "Trailer");
    controller.updateMovie("Title", 2004, "NewGenre", 1000, "NewTrailer");
    DynamicVector<Movie> movies = controller.getAllMovies();
    assert(movies[10].getGenre() == "NewGenre");
    assert(movies[10].getTrailer() == "NewTrailer");
}

void Controller::test_construct_controller() {
    Controller controller;
    DynamicVector<Movie> movies = controller.getAllMovies();
    assert(movies.getLength() == 10);
}

DynamicVector<Movie> Controller::getMoviesByGenre(const std::string& genre) {
    currentMovieIndex = -1;
    currentGenre = genre;
    DynamicVector<Movie> movies_found = repo.getMoviesByGenre(genre);
    return movies_found;
}

Movie Controller::nextMovie() {
    DynamicVector<Movie> movies = repo.getMoviesByGenre(currentGenre);
    currentMovieIndex = (currentMovieIndex + 1) % movies.getLength();
    return movies[currentMovieIndex];
}

void Controller::addToWatchlist(const Movie &movie) {
    this->watchlist.addToWatchlist(movie);
}

Watchlist Controller::getWatchlist() {
    return this->watchlist;
}

void Controller::removeFromWatchlist(const string &title, int year) {
    this->watchlist.removeFromWatchlist(title, year);
}

void Controller::test_get_movies_by_genre(){
    Controller controller;
    controller.addMovie("Title1", "Genre1", 2004, 1000, "Trailer");
    controller.addMovie("Title2", "Genre2", 2021, 1000, "Trailer");
    controller.addMovie("Title3", "Genre1", 2024, 1000, "Trailer");
    DynamicVector<Movie> movies = controller.getMoviesByGenre("Genre1");
    assert(movies.getLength() == 2);
    assert(movies[0].getTitle() ==  "Title1");
    assert(movies[1].getTitle() ==  "Title3");
}

void Controller::test_next_movie(){
    Controller controller;
    Movie movie1 = Movie("Title1", "Genre1", 2004, 1000, "Trailer");
    controller.addMovie(movie1.getTitle(), movie1.getGenre(), movie1.getYear(), movie1.getLikes(), movie1.getTrailer());
    Movie movie2 = Movie("Title2", "Genre1", 2021, 1000, "Trailer");
    controller.addMovie(movie2.getTitle(), movie2.getGenre(), movie2.getYear(), movie2.getLikes(), movie2.getTrailer());
    DynamicVector<Movie> movies = controller.getMoviesByGenre("Genre1");
    assert(movies.getLength() == 2);
    assert(controller.nextMovie() == movie1);
    Movie movie2_checked = controller.nextMovie();
    assert(movie2_checked == movie2);
    Movie movie3_checked = controller.nextMovie();
    assert(movie3_checked == movie1);
}

void Controller::test_add_watchlist(){
    Controller controller;
    Movie movie("Title1", "Genre1", 2004, 1000, "Trailer");
    controller.addToWatchlist(movie);
    assert(controller.getWatchlist().getLength() == 1);
    assert(controller.getWatchlist()[0] == movie);
}

void Controller::test_remove_watchlist(){
    Controller controller;
    Movie movie("Title1", "Genre1", 2004, 1000, "Trailer");
    controller.addToWatchlist(movie);
    assert(controller.getWatchlist().getLength() == 1);
    controller.removeFromWatchlist(movie.getTitle(), movie.getYear());
    assert(controller.getWatchlist().getLength() == 0);
}