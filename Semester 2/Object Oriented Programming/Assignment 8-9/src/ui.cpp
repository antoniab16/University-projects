#include <iostream>
#include "ui.h"
#include "exceptions.h"

void UI::printMovies(){
    DynamicVector<Movie> movies = controller.getAllMovies();
    for(int i = 0; i < movies.getLength(); i++){
        Movie m = movies[i];
        cout<<"Title : "<<m.getTitle()<<" | "<<"Genre : "<<m.getGenre()<<" | "<<"Year : "<<m.getYear()<<" | "
        <<"Likes : "<<m.getLikes()<<" | "<<"Trailer : "<<m.getTrailer()<<endl;
    }
}

void UI::run_administartor(){
    while(1){
        cout<<"1. Add a movie to database"<<endl;
        cout<<"2. Remove a movie from database"<<endl;
        cout<<"3. Update a movie from database"<<endl;
        cout<<"4. See all movies from database"<<endl;
        cout<<"0. Go back to choose mode"<<endl;
        string option_admin;
        cout<<">>>";
        cin>>option_admin;
        if(option_admin == "0")
            break;
        else if(option_admin == "1"){
            string title, genre, trailer;
            int year_release, likes;
            cout << "Enter the title of the movie you wish to add: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter the genre of the movie you wish to add: ";
            cin.ignore();
            getline(cin, genre);
            cout << "Enter the year of release of the movie you wish to add: ";
            cin >> year_release;
            cout << "Enter the number of likes of the movie you wish to add: ";
            cin >> likes;
            cout << "Enter the trailer of the movie you wish to add: ";
            cin.ignore();
            getline(cin, trailer);
            string result = controller.addMovie(title, genre, year_release, likes, trailer);
            if(!result.empty()){
                cout<<"Error: " << result << endl;
            }
        }
        else if(option_admin == "2"){
            string title;
            int year_release;
            cout << "Enter the title of the movie you wish to remove: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter the year of release of the movie you wish to remove: ";
            cin >> year_release;
            string result = controller.removeMovie(title, year_release);
            if(!result.empty()){
                cout<<"Error: " << result << endl;
            }
        }
        else if(option_admin == "3"){
            string title, genre, trailer;
            int year, likes;
            cout << "Enter the title of the movie you wish to update: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter the year of release of the movie you wish to update: ";
            cin >> year;
            cout << "Enter the new genre of the movie you wish to update: ";
            cin.ignore();
            getline(cin, genre);
            cout << "Enter the new number of likes of the movie you wish to update: ";
            cin >> likes;
            cout << "Enter the new trailer of the movie you wish to update: ";
            cin.ignore();
            getline(cin, trailer);
            string result = this->controller.updateMovie(title, year, genre, likes, trailer);
            if(!result.empty()){
                cout<<"Error: " << result << endl;
            }
        }
        else if(option_admin == "4"){
            cout<<"The database: "<<endl;
            printMovies();
        }
        else{
            cout<<"Invalid option! Please try again"<<endl;
        }
    }
}

void UI::run_user() {
    while(1){
        cout<<"1. See movies from database by genre"<<endl;
        cout<<"2. Delete movie from watchlist"<<endl;
        cout<<"3. See watchlist"<<endl;
        cout<<"4. Open CSV/HTML file with watchlist"<<endl;
        cout<<"0. Go back to choose mode"<<endl;
        string option_user;
        cout<<">>>";
        cin>>option_user;
        if(option_user == "1"){
            string genre;
            cout<<"Enter genre you want to see: ";
            cin.ignore();
            getline(cin, genre);
            controller.getMoviesByGenre(genre);
            char command;
            char answer_like;
            char answer_add;
            do{
                Movie m = controller.nextMovie();
                cout<<"Title : "<<m.getTitle()<<" | "<<"Genre : "<<m.getGenre()<<" | "<<"Year : "<<m.getYear()<<" | "
                    <<"Likes : "<<m.getLikes()<<endl;
                string command_trailer = "open " + m.getTrailer();
                system(command_trailer.c_str());
                cout<<"Do you like the trailer? (y/n)"<<endl;
                cout<<">>>";
                cin>>answer_like;
                if(answer_like == 'y'){
                    cout<<"Do you want to add to watchlist? (y/n)"<<endl;
                    cout<<">>>";
                    cin>>answer_add;
                    if(answer_add == 'y'){
                        try{
                        controller.addToWatchlist(m);}
                        catch(const std::runtime_error& e) {
                            cout << "Error : " << e.what() << endl;
                        }
                    }
                }
                else{
                    cout<<"Would you still want to add movie to watchlist? (y/n)"<<endl;
                    cout<<">>>";
                    cin>>answer_add;
                    if(answer_add == 'y'){
                        try{
                            controller.addToWatchlist(m);}
                        catch(const Exceptions& e) {
                            cout << "Error : " << e.get_message() << endl;
                        }
                    }
                }
                cout<<"Press 1 to see the next movie or 'q' to quit"<<endl;
                cout<<">>>";
                cin>>command;
            }while(command != 'q');
            saveToFile();
        }
        else if (option_user == "2"){
            string title;
            int year_release;
            cout << "Enter the title of the movie you wish to remove: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter the year of release of the movie you wish to remove: ";
            cin >> year_release;
            try{
            this->controller.removeFromWatchlist(title, year_release);}
            catch(const Exceptions& e){
                cout<<"Error : "<<e.get_message()<<endl;
            }
            saveToFile();
        }
        else if (option_user == "3"){
            printWatchlist();
            saveToFile();
        }
        else if(option_user == "4"){
            displayFile();
        }
        else if(option_user == "0")
            break;
        else{
            cout<<"Invalid option! Please try again"<<endl;
        }
    }
}

void UI::run() {
    cout<<"Welcome to the movie database!"<<endl;
    cout << "Enter filename: ";
    cin >> filename;
    cout << "Enter file type (CSV/HTML): ";
    cin >> type;
    cout<<"Choose the mode: "<<endl;
    while(1){
            cout<<"1. Administrator mode"<<endl;
            cout<<"2. User mode"<<endl;
            cout<<"0. Exit"<<endl;
            string option_mode;
            cout<<">>>";
            cin>>option_mode;
            if(option_mode == "1"){
                run_administartor();
            }
            else if(option_mode == "2"){
                run_user();
            }
            else if(option_mode == "0"){
                cout<<"Goodbye!"<<endl;
                break;
            }
            else{
                cout<<"Invalid option! Please try again"<<endl;
            }
        }

}

UI::UI() {
    controller = Controller();
}

void UI::printWatchlist() {
    DynamicVector<Movie> watchlist = controller.getWatchlist();
    for(int i = 0; i < watchlist.getLength(); i++){
        Movie m = watchlist[i];
        cout<<"Title : "<<m.getTitle()<<" | "<<"Genre : "<<m.getGenre()<<" | "<<"Year : "<<m.getYear()<<" | "
            <<"Likes : "<<m.getLikes()<<" | "<<"Trailer : "<<m.getTrailer()<<endl;
    }
}

void UI::saveToFile() {
    FileWriter* file;
    if(type == "CSV"){
        file = new CSVWriter();
    }
    else if(type == "HTML"){
        file = new HTMLWriter();
    }
    file->writeToFile(filename, controller.getWatchlist());
    delete file;
}

void UI::displayFile() {
    FileWriter* file;
    if(type == "CSV"){
        file = new CSVWriter();
    }
    else if(type == "HTML"){
        file = new HTMLWriter();
    }
    file->displayFile(filename);
    delete file;
}

