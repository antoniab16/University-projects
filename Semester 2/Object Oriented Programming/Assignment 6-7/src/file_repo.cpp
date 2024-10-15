#include <fstream>
#include "file_repo.h"
#include <filesystem>
FileRepository::FileRepository(std::string filename) {
    this->filename = filename;
}

void FileRepository::addMovie(Movie movie) {
    std::ofstream file;
    file.open(filename.c_str(), std::ios_base::app);
    file << movie;
    file.close();
}


void FileRepository::removeMovie(const std::string &title, int year) {
    int index = findMovies(title, year);
    if(index != -1){
        DynamicVector<Movie> movies = getAllMovies();
        movies.remove(movies[index]);
        writeToFile(movies);
    }
}

void FileRepository::updateMovie(std::string title, int year, std::string newGenre, int newLikes, std::string newTrailer) {
    int index = findMovies(title, year);
    if(index != -1){
        DynamicVector<Movie> movies = getAllMovies();
        movies[index].setGenre(newGenre);
        movies[index].setLikes(newLikes);
        movies[index].setTrailer(newTrailer);
        writeToFile(movies);
    }
}

DynamicVector<Movie> FileRepository::getAllMovies() {
    movies.clear();
    std::ifstream file(this->filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Failed to open file: "
                  << std::__fs::filesystem::absolute(this->filename)
                  << std::endl;
        return movies;
    }
    Movie movie;
    while(file >> movie){
        movies.push_back(movie);
    }
    file.close();
    return movies;
}

int FileRepository::findMovies(std::string title, int year) {
    int index = 0;
    std::ifstream file(filename.c_str());
    Movie movie;
    while(file >> movie){
        if(movie.getTitle() == title && movie.getYear() == year){
            file.close();
            return index;
        }
        index++;
    }
    file.close();
    return -1;
}

void FileRepository::writeToFile(DynamicVector<Movie> movies) {
    std::ofstream file(filename.c_str());
    for (Movie movie : movies)
        file << movie;
    file.close();
}

