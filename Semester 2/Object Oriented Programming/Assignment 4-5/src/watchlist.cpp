#include "watchlist.h"

void Watchlist::addToWatchlist(Movie movie) {
    for (int i = 0; i < this->movies.getLength(); i++)
    {
        if(this->movies[i].getTitle() == movie.getTitle() && this->movies[i].getYear() == movie.getYear())
            throw std::runtime_error("Movie already in watchlist!");
    }
    this->movies.add(movie);
}

void Watchlist::removeFromWatchlist(const string &title, int year) {
    int ok = 0;
    for (int i = 0; i < this->movies.getLength(); i++)
    {
        if(this->movies[i].getTitle() == title && this->movies[i].getYear() == year){
            this->movies.remove(this->movies[i]);
            ok =1;
        }
    }
    if (ok == 0)
        throw std::runtime_error("Movie is not in watchlist");
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
    try{
        watchlist.removeFromWatchlist(movie.getTitle(), movie.getYear());
        assert(false);
    }catch(std::runtime_error& e){
        assert(std::string(e.what()) == "Movie is not in watchlist");
    }
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
