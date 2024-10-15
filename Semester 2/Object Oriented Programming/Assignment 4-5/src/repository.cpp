#include <cassert>
#include "repository.h"

Repository::Repository() : movies(DynamicVector<Movie>()){
}

/// Takes Movie object as argument and adds it to the repository using add method from DynamicVector
/// Throws exception if movie already exists.
/// \param movie - movie we want to add to the repository
void Repository::addMovie( Movie movie) {
    for(int i = 0; i < this->movies.getLength(); i++){
        if(this->movies[i].getTitle() == movie.getTitle() && this->movies[i].getYear() == movie.getYear())
            throw std::runtime_error("Movie already exists!");
    }
    this->movies.add(movie);
}

/// Takes title and year of a movie as arguments and removes the corresponding movie from the repository using remove method from DynamicVector
/// Throws exception if movie does not exist.
/// \param title - title of the movie we want to remove
/// \param year - year of the movie we want to remove
void Repository::removeMovie(const std::string& title, int year){
    int index = -1;
    for(int i = 0; i < this->movies.getLength(); i++) {
        if (this->movies[i].getTitle() == title && this->movies[i].getYear() == year) {
            index = i;
            break;
        }
    }
    if(index == -1)
        throw std::runtime_error("Movie does not exist!");
    else{
        this->movies.remove(this->movies[index]);
    }
}

DynamicVector<Movie> Repository::getAllMovies() {
    return this->movies;
}

/// Adds initial movies to the repository
void Repository::getInitialMovies() {
    this->addMovie(Movie("Oppenheimer", "Biography", 2023, 812000, "https://www.youtube.com/watch?v=uYPbbksJxIg"));
    this->addMovie(Movie("Culpa Mia", "Drama", 2023, 33000, "https://www.youtube.com/watch?v=3CpKBAPqqM0"));
    this->addMovie(Movie("Spider-Man : No Way Home", "Action", 2021, 2900000, "https://www.youtube.com/watch?v=JfVOs4VSpmA"));
    this->addMovie(Movie("LaLaLand", "Drama", 2016, 200000, "https://www.youtube.com/watch?v=0pdqf4P9MB8"));
    this->addMovie(Movie("Hunger Games Ballads Of Songbirds And Snakes", "Action", 2023, 215000, "https://www.youtube.com/watch?v=RDE6Uz73A7g"));
    this->addMovie(Movie("The Batman", "Action", 2022, 1300000, "https://www.youtube.com/watch?v=mqqft2x_Aa4"));
    this->addMovie(Movie("Wall-E", "Animation", 2008, 12000, "https://www.youtube.com/watch?v=CZ1CATNbXg0"));
    this->addMovie(Movie("Titanic", "Drama", 1997, 726000, "https://www.youtube.com/watch?v=F2RnxZnubCM"));
    this->addMovie(Movie("Cars", "Animation", 2006, 1200, "https://www.youtube.com/watch?v=W_H7_tDHFE8"));
    this->addMovie(Movie("Elvis", "Biography", 2022, 149000, "https://www.youtube.com/watch?v=wBDLRvjHVOY"));
}

/// Takes title and year of a movie and the new genre, the new number of likes and the new trailer as arguments and updates the corresponding movie from the repository
/// Throws exception if movie does not exist.
/// \param title - title of the movie we want to update
/// \param year - year of the movie we want to update
/// \param newGenre - the new genre of the movie
/// \param newLikes - the new number of likes of the movie
/// \param newTrailer - the new trailer of the movie
void Repository::updateMovie(string title, int year, string newGenre, int newLikes, string newTrailer) {
    int ok = 0;
    for(int i = 0; i < this->movies.getLength(); i++){
        if(this->movies[i].getTitle() == title && this->movies[i].getYear() == year){
            this->movies[i].setGenre(newGenre);
            this->movies[i].setLikes(newLikes);
            this->movies[i].setTrailer(newTrailer);
            ok = 1;
        }
    }
    if(ok == 0)
        throw std::runtime_error("Movie does not exist!");
}

void Repository::test_add_movie() {
    Repository repo;
    Movie movie1("Title", "Genre", 2004, 1000, "Trailer");
    repo.addMovie(movie1);
    assert(repo.getAllMovies().getLength() == 1);
    assert(repo.getAllMovies()[0] == movie1);
    try{
        repo.addMovie(movie1);
    }catch(const std::runtime_error& e){
        assert(std::string(e.what()) == "Movie already exists!");
    }
}

void Repository::test_remove_movie(){
    Repository repo;
    Movie movie1("Title", "Genre", 2004, 1000, "Trailer");
    repo.addMovie(movie1);
    Movie movie2("Title1", "Genre1", 2004, 1000, "Trailer1");
    repo.addMovie(movie2);
    assert(repo.getAllMovies().getLength() == 2);
    repo.removeMovie(movie2.getTitle(), movie2.getYear());
    assert(repo.getAllMovies().getLength() == 1);
    try{
        repo.removeMovie("Nonexistent", 2000);
    }catch (const std::runtime_error& e){
        assert(std::string(e.what())=="Movie does not exist!");
    }
}

void Repository::test_update_movie() {
    Repository repo;
    Movie movie1("Title", "Genre", 2004, 1000, "Trailer");
    repo.addMovie(movie1);
    repo.updateMovie("Title", 2004, "NewGenre", 1000, "NewTrailer");
    assert(repo.getAllMovies()[0].getGenre() == "NewGenre");
    assert(repo.getAllMovies()[0].getTrailer() == "NewTrailer");
    try{
        repo.updateMovie("Nonexistent", 2000, "new_genre", 1, "new_trailer");
    }catch (const std::runtime_error& e){
        assert(std::string(e.what())=="Movie does not exist!");
    }
}

void Repository::test_get_intial_movies() {
    Repository repo;
    repo.getInitialMovies();
    assert(repo.getAllMovies().getLength() == 10);
}

void Repository::test_construct_repo() {
    Repository repo = Repository();
    assert(repo.getAllMovies().getLength() == 0);
}

void Repository::test_get_all_movies() {
    Repository repo;
    Movie movie1("Title", "Genre", 2004, 1000, "Trailer");
    repo.addMovie(movie1);
    Movie movie2("Title1", "Genre1", 2004, 1000, "Trailer1");
    repo.addMovie(movie2);
    DynamicVector<Movie> movies = repo.getAllMovies();
    assert(movies.getLength() == 2);
    assert(movies[0] == movie1);
    assert(movies[1] == movie2);
}

/// Searches for movies having a certain genre and creates a new dynamic vector of the movies found returning it
/// \param genre genre by which movies are searched for
/// \return vector of movies with the wanted genre
DynamicVector<Movie> Repository::getMoviesByGenre(string genre) {
    DynamicVector<Movie> movies_found;
    if (genre == "")
        return this->movies;
    for(int i = 0; i < this->movies.getLength(); i++){
        if(this->movies[i].getGenre() == genre)
            movies_found.add(this->movies[i]);
    }
    return movies_found;
}

void Repository::test_get_movies_by_genre(){
    Repository repo;
    Movie movie1("Title", "Genre", 2004, 1000, "Trailer");
    repo.addMovie(movie1);
    Movie movie2("Title1", "Genre1", 2004, 1000, "Trailer1");
    repo.addMovie(movie2);
    Movie movie3("Title2", "Genre1", 2004, 1000, "Trailer1");
    repo.addMovie(movie3);
    DynamicVector<Movie> movies_genre1 = repo.getMoviesByGenre("Genre1");
    assert(movies_genre1.getLength() == 2);
    assert(movies_genre1[0] == movie2);
    assert(movies_genre1[1] == movie3);
    DynamicVector<Movie> all_movies = repo.getMoviesByGenre("");
    assert(all_movies.getLength() == 3);
}





