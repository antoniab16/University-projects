#include "movies.h"
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>

Movie::Movie(const string& title, const string& genre, int year, int likes, const string& trailer) {
    this->title = title;
    this->genre = genre;
    this->year_of_release = year;
    this->likes = likes;
    this->trailer = trailer;
}

string Movie::getTitle() {
    return this->title;
}

string Movie::getGenre() {
    return this->genre;
}

int Movie::getYear() {
    return this->year_of_release;
}

int Movie::getLikes() {
    return this->likes;
}

string Movie::getTrailer() {
    return this->trailer;
}

Movie::Movie() {
    this->title = "";
    this->genre = "";
    this->year_of_release = 0;
    this->likes= 0;
    this->trailer = "";
}

bool Movie::operator==(const Movie &other) {
    return this->title == other.title && this->genre == other.genre && this->year_of_release == other.year_of_release
    && this->likes == other.likes && this->trailer == other.trailer;
}

bool Movie::operator!=(const Movie &other) {
    return this->title != other.title || this->genre != other.genre || this->year_of_release != other.year_of_release
    || this->likes != other.likes || this->trailer != other.trailer;
}

void Movie::setLikes(int newLikes) {
    this->likes = newLikes;
}

void Movie::setGenre(string newGenre) {
    this->genre = newGenre;
}

void Movie::setTrailer(string newTrailer) {
    this->trailer = newTrailer;
}

void Movie::setTitle(std::string newTitle) {
    this->title = newTitle;
}

void Movie::setYear(int newYear) {
    this->year_of_release = newYear;
}

void Movie::test_constructor_and_getters() {
    Movie movie("Title", "Genre", 2004, 1000, "Trailer");
    assert(movie.getTitle() == "Title");
    assert(movie.getGenre() == "Genre");
    assert(movie.getYear() == 2004);
    assert(movie.getLikes() == 1000);
    assert(movie.getTrailer() == "Trailer");
}

void Movie::test_setters() {
    Movie movie("Title", "Genre", 2004, 1000, "Trailer");
    movie.setLikes(1004);
    assert(movie.getLikes() == 1004);
    movie.setGenre("NewGenre");
    assert(movie.getGenre() == "NewGenre");
    movie.setTrailer("NewTrailer");
    assert(movie.getTrailer() == "NewTrailer");
}

void Movie::test_operators() {
    Movie movie("Title", "Genre", 2004, 1000, "Trailer");
    Movie movie1("Title", "Genre", 2004, 1000, "Trailer");
    assert(movie == movie1);
    assert(!(movie1 != movie));
    movie.setGenre("NewGenre");
    assert(movie != movie1);
}

std::ostream &operator<<(ostream &os, const Movie &movie) {
    os << movie.title << ", "
       << movie.genre << ", "
       << movie.year_of_release << ", "
       << movie.likes << ", "
       << movie.trailer << std::endl;
    return os;

}

std::istream& operator>>(std::istream& is, Movie& movie) {
    std::string line;
    if (std::getline(is, line)) {
        std::stringstream ss(line);
        std::string field;
        std::vector<std::string> fields;

        while (std::getline(ss, field, ',')) {
            fields.push_back(field);
        }

        if (fields.size() == 5) {
            movie.setTitle(fields[0]);
            movie.setGenre(fields[1]);
            movie.setYear(std::stoi(fields[2]));
            movie.setLikes(std::stoi(fields[3]));
            movie.setTrailer(fields[4]);
        }
    }

    return is;
}


