#pragma once
#include <string>

using namespace std;

class Movie{
private:
    string title;
    string genre;
    int year_of_release;
    int likes;
    string trailer;

public:
    Movie(const string& title, const string& genre, int year, int likes, const string& trailer);
    Movie();
    string getTitle();
    string getGenre();
    int getYear();
    int getLikes();
    string getTrailer();
    bool operator==(const Movie& other);
    bool operator!=(const Movie& other);
    void setLikes(int newLikes);
    void setTrailer(string newTrailer);
    void setGenre(string newGenre);
    void setTitle(string newTitle);
    void setYear(int newYear);
    void test_constructor_and_getters();
    void test_setters();
    void test_operators();

    friend std::ostream& operator<<(std::ostream& os, const Movie& movie);
    friend std::istream& operator>>(std::istream& is, Movie& movie);
};

