
#include "validator.h"

bool Validator::movieExists(DynamicVector<Movie> movies, string title, int year) {
    for (auto & movie : movies){
        if(title == movie.getTitle() && year == movie.getYear())
            return true;
    }
    return false;
}
