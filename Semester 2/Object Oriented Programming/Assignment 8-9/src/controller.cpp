#include <cassert>
#include <fstream>
#include "controller.h"
#include <iostream>
#include "exceptions.h"

/// Constructor for the Controller class
Controller::Controller(Repository repo, Watchlist watchlist)
        : repo(Repository()), watchlist(Watchlist()), fileRepo(FileRepository()){
    repo.getInitialMovies();
}

/// Takes title, genre, year, likes and trailer of a movie as parameters and creates a new Movie object which is then
/// added to the repository using addMovie form Repository
std::string Controller::addMovie(std::string title, std::string genre, int year, int likes, std::string trailer) {
    Movie m = Movie(title, genre, year, likes, trailer);
    try{
        this->repo.addMovie(m);
        return "";
    } catch(const Exceptions& e){
        return e.get_message();
    }
}

/// Returns all the movies from the repository
DynamicVector<Movie> Controller::getAllMovies() {
    return this->repo.getAllMovies();
}

/// Takes title and year of a movie as parameters and removes the movie with the given title and year from the
/// repository using removeMovie from Repository
std::string Controller::removeMovie(std::string title, int year) {
    try{
        this->repo.removeMovie(title, year);
        return "";
    } catch(const Exceptions& e){
        return e.get_message();
    }

}

/// Takes title, year of a movie and new genre, new number of likes and new trailer as parameters and updates the movie
/// using updateMovie from Repository
std::string Controller::updateMovie(std::string title, int year, std::string newGenre, int newLikes, std::string newTrailer) {
    try{
        this->repo.updateMovie(title, year, newGenre, newLikes, newTrailer);
        return "";
    } catch(const Exceptions& e){
        return e.get_message();
    }

}


DynamicVector<Movie> Controller::getMoviesByGenre(const std::string& genre) {
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

DynamicVector<Movie> Controller::getWatchlist() {
    return this->watchlist.getWatchlist();
}

void Controller::removeFromWatchlist(const string &title, int year) {
    this->watchlist.removeFromWatchlist(title, year);
}

void Controller::setFile(std::string filename) {
    FileRepository newRepo{filename};
    repo = newRepo;
    DynamicVector<Movie> movies = newRepo.getAllMovies();
    for(auto& movie:movies){
        repo.addMovie(movie);
    }
}

void Controller::writeToFile(std::string filename) {
    FileRepository newRepo{filename};
    DynamicVector<Movie> movies = repo.getAllMovies();
    newRepo.writeToFile(movies);
}

int Controller::getIndexMovie(string filename, std::string title, int year) {
    FileRepository newRepo{filename};
    DynamicVector<Movie> movies = repo.getAllMovies();
    int index = newRepo.findIndexMovie(title, year);
    return index;
}

void Controller::readFromFile() {
    std::ifstream fin("/Users/antonia/CLionProjects/oop-a8-9-antoniab16/movies.txt");
    Movie movie;
    if(fin.is_open()){
        while(fin.good()){
            fin >> movie;
            repo.addMovie(movie);
        }
    }
    fin.close();
}
int Controller::getCurrentIndex() const {
    return this->currentMovieIndex;
}

Movie Controller::getMovieAtIndex(int index, DynamicVector<Movie> movies) {
    return movies.at(index);
}

