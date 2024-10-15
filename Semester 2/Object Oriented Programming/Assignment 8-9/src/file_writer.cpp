#include <cstdlib>
#include "file_writer.h"

void CSVWriter::writeToFile(std::string filename, DynamicVector<Movie> movies) {
    std::ofstream file("../" + filename);
    for(Movie movie : movies){
        file << movie.getTitle() << ", " << movie.getGenre() << ", " << movie.getYear() << ", " << movie.getLikes() << ", " << movie.getTrailer()<<endl;
    }
    file.close();
}

void CSVWriter::displayFile(std::string filename) {
    std::string command;
    command = "open -a 'TextEdit' ../" + filename;
    system(command.c_str());
}

void HTMLWriter::writeToFile(std::string filename, DynamicVector<Movie> movies) {
    std::ofstream file("../" + filename);
    file << "<!DOCTYPE html>\n";
    file << "<html>\n";
    file << "<head>\n";
    file << "<title>Movie watchlist</title>\n";
    file << "</head>\n";
    file << "<body>\n";
    file << "<table border=\"1\">\n";
    file << "<tr><th>Title</th><th>Genre</th><th>Year</th><th>Likes</th><th>Trailer</th></tr>\n";
    for(Movie movie:movies){
        file << "<tr><td>" << movie.getTitle() << "</td><td>" << movie.getGenre() << "</td><td>" << movie.getYear() << "</td><td>" << movie.getLikes() << "</td><td>" << movie.getTrailer() << "</td></tr>\n";
    }
    file << "</table>\n";
    file << "</body>\n";
    file << "</html>";
    file.close();
}

void HTMLWriter::displayFile(std::string filename) {
    std::string command;
    command = "open -a 'Opera' ../" + filename;
    system(command.c_str());
}