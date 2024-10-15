#include "watchlist.h"
#include "validator.h"
#include "exceptions.h"

/// Adds to watchlist a new movie
/// \param movie
void Watchlist::addToWatchlist(Movie movie) {
    if(Validator::movieExists(movies, movie.getTitle(), movie.getYear())){
        throw Exceptions("Movie already exists!");
    }
    else
        movies.add(movie);
}

/// Removes a movie from the watchlist based on title and year of movie
/// \param title title of movie to be removed
/// \param year year of movie to be removed
void Watchlist::removeFromWatchlist(const string &title, int year) {
    if(!Validator::movieExists(movies, title, year)){
        throw Exceptions("Movie doesn't exist!");
    }
    else{
        auto it = std::remove_if(movies.begin(), movies.end(), [&title, &year](Movie &m) {
            return m.getTitle() == title && m.getYear() == year;
        });
        int index = std::distance(movies.begin(), it);
        movies.remove(movies[index]);
    }
}

DynamicVector<Movie> Watchlist::getWatchlist() {
    return this->movies;
}

int Watchlist::getLength() {
    return this->movies.getLength();
}

Movie &Watchlist::operator[](int index) {
    return this->movies[index];
}

void Watchlist::test_add_watchlist() {
    Watchlist watchlist;
    Movie movie("Title", "Genre", 2004, 1000, "Trailer");
    watchlist.addToWatchlist(movie);
    assert(watchlist.movies.getLength() == 1);
    assert(watchlist.movies[0].getTitle() == movie.getTitle());
    try{
        watchlist.addToWatchlist(movie);
        assert(false);
    }catch (std::runtime_error& e){
        assert(std::string(e.what()) == "Movie already in watchlist!");
    }
}

void Watchlist::test_remove_watchlist() {
    Watchlist watchlist;
    Movie movie("Title", "Genre", 2004, 1000, "Trailer");
    watchlist.addToWatchlist(movie);
    assert(watchlist.movies.getLength() == 1);
    watchlist.removeFromWatchlist(movie.getTitle(), movie.getYear());
    assert(watchlist.movies.getLength() == 0);

}

void Watchlist::test_get_watchlist(){
    Watchlist watchlist;
    Movie movie1("Title", "Genre", 2004, 1000, "Trailer");
    Movie movie2("Title1", "Genre1", 2004, 1000, "Trailer1");
    watchlist.addToWatchlist(movie1);
    watchlist.addToWatchlist(movie2);
    DynamicVector<Movie>movies = watchlist.getWatchlist();
    assert(movies.getLength() == 2);
    assert(movies[0].getTitle() == movie1.getTitle());
    assert(movies[1].getTitle() == movie2.getTitle());
}

void Watchlist::test_operator_watchlist(){
    Watchlist watchlist;
    Movie movie("Title1", "Genre1", 2004, 1000, "Trailer1");
    watchlist.addToWatchlist(movie);
    assert(watchlist[0].getTitle() == movie.getTitle());
}

void Watchlist::test_get_length(){
    Watchlist watchlist;
    assert(watchlist.getLength() == 0);
    Movie movie("Title1", "Genre1", 2004, 1000, "Trailer1");
    watchlist.addToWatchlist(movie);
    assert(watchlist.getLength() == 1);
}
