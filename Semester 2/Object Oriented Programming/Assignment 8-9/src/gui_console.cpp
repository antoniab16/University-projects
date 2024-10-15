#include "gui_console.h"
#include <string>
#include <QDebug>
#include <QComboBox>
#include "file_writer.h"

GUI::GUI(Controller controller, QWidget* parent) : controller(Controller()), QWidget{parent}{
    this->initGUI();
}

void GUI::initGUI() {
    auto* mainLayout = new QVBoxLayout(this);
    QFont font("Raleway", 18);
    auto* intro = new QLabel("Welcome!");
    intro->setAlignment(Qt::AlignCenter);
    intro->setFont(font);
    mainLayout->addWidget(intro);
    auto* buttonsWidget = new QWidget();
    auto* buttonsLayout = new QHBoxLayout(buttonsWidget);
    adminButton = new QPushButton("ADMIN");
    userButton = new QPushButton("USER");
    buttonsLayout->addWidget(adminButton);
    buttonsLayout->addWidget(userButton);
    mainLayout->addWidget(buttonsWidget);
    auto* csvHtmlWidget = new QWidget();
    auto* csvHtmlLayout = new QHBoxLayout(csvHtmlWidget);
    auto* csvHtmlLabel = new QLabel("CSV/HTML : ");
    csvHtmlLabel->setBuddy(csvHtmlWidget);
    csvHtmlLabel->setFont(font);
    csvHtmlLineEdit = new QLineEdit();
    csvHtmlLayout->addWidget(csvHtmlLabel);
    csvHtmlLayout->addWidget(csvHtmlLineEdit);
    mainLayout->addWidget(csvHtmlWidget);
    QObject::connect(adminButton, &QPushButton::clicked, this, &GUI::adminGUI);
    QObject::connect(userButton, &QPushButton::clicked, this, &GUI::userGUI);

}

void GUI::populateMovies() {
    if(moviesListWidget->count() > 0)
        moviesListWidget->clear();
    auto movies = controller.getAllMovies();
    for(auto movie:movies){
        QString movieInList = QString::fromStdString(movie.getTitle() + ", " + movie.getGenre() + ", " + std::to_string(movie.getYear())+ ", " + std::to_string(movie.getLikes())+ ", " +movie.getTrailer());
        QFont font("Raleway", 12);
        auto* item = new QListWidgetItem(movieInList);
        item->setFont(font);
        moviesListWidget->addItem(item);
    }
    if(movies.getLength() != 0){
        moviesListWidget->setCurrentRow(0);
    }
}

void GUI::populateWatchlist() {
    if(watchlistWidget->count() > 0)
        watchlistWidget->clear();
    auto movies = controller.getWatchlist();
    for(auto movie:movies){
        QString movieInList = QString::fromStdString(movie.getTitle() + ", " + to_string(movie.getYear()));
        QFont font("Raleway", 12);
        auto* item = new QListWidgetItem(movieInList);
        item->setFont(font);
        watchlistWidget->addItem(item);
    }
    if(movies.getLength() != 0){
        watchlistWidget->setCurrentRow(0);
    }
}

void GUI::adminGUI() {
    adminWidget = new QWidget();
    adminWidget->show();
    adminWidget->setWindowTitle("ADMIN");
    hide();
    controller.readFromFile();
    auto* layout = new QHBoxLayout(adminWidget);
    moviesListWidget = new QListWidget();
    moviesListWidget->setMinimumWidth(300);
    moviesListWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    layout->addWidget(moviesListWidget);
    auto* right = new QWidget();
    right->setMinimumWidth(500);
    auto* verticalLayout = new QVBoxLayout(right);
    auto* movieInfoWidget = new QWidget();
    auto* formLayout = new QFormLayout(movieInfoWidget);
    titleEditWidget = new QLineEdit();
    genreEditWidget = new QLineEdit();
    yearEditWidget = new QLineEdit();
    likesEditWidget = new QLineEdit();
    trailerEditWidget = new QLineEdit();
    QFont font("Raleway", 18);
    auto* titleLabel = new QLabel("Title : ");
    titleLabel->setBuddy(titleEditWidget);
    titleLabel->setFont(font);
    titleEditWidget->setFont(font);
    auto* genreLabel = new QLabel("Genre : ");
    genreLabel->setBuddy(genreEditWidget);
    genreLabel->setFont(font);
    genreEditWidget->setFont(font);
    auto* yearLabel = new QLabel("Year : ");
    yearLabel->setBuddy(yearEditWidget);
    yearLabel->setFont(font);
    yearEditWidget->setFont(font);
    auto* likesLabel = new QLabel("Likes : ");
    likesLabel->setBuddy(likesEditWidget);
    likesLabel->setFont(font);
    likesEditWidget->setFont(font);
    auto* trailerLabel = new QLabel("Trailer : ");
    trailerLabel->setBuddy(trailerEditWidget);
    trailerLabel->setFont(font);
    trailerEditWidget->setFont(font);
    formLayout->addRow(titleLabel, titleEditWidget);
    formLayout->addRow(genreLabel, genreEditWidget);
    formLayout->addRow(yearLabel, yearEditWidget);
    formLayout->addRow(likesLabel, likesEditWidget);
    formLayout->addRow(trailerLabel, trailerEditWidget);
    verticalLayout->addWidget(movieInfoWidget);
    auto* buttonsWidget = new QWidget();
    auto* horizontalLayout = new QGridLayout(buttonsWidget);
    addButton = new QPushButton("ADD");
    addButton->setFont(font);
    removeButton = new QPushButton("REMOVE");
    removeButton->setFont(font);
    updateButton = new QPushButton("UPDATE");
    updateButton->setFont(font);
    exitButton = new QPushButton("EXIT");
    exitButton->setFont(font);
    QObject::connect(addButton, &QPushButton::clicked, this, &GUI::addMovieButton);
    QObject::connect(removeButton, &QPushButton::clicked, this, &GUI::removeMovieButton);
    QObject::connect(updateButton, &QPushButton::clicked, this, &GUI::updateMovieButton);
    QObject::connect(exitButton, &QPushButton::clicked, this, &GUI::exitProgramButton);
    QObject::connect(moviesListWidget, &QListWidget::itemSelectionChanged, this, [this](){listItemChange();});
    horizontalLayout->addWidget(addButton, 0, 0);
    horizontalLayout->addWidget(removeButton, 0, 1);
    horizontalLayout->addWidget(updateButton, 0, 2);
    horizontalLayout->addWidget(exitButton, 1, 1);
    verticalLayout->addWidget(buttonsWidget);
    layout->addWidget(moviesListWidget);
    layout->addWidget(right);
    populateMovies();
}

void GUI::listItemChange() {
    QModelIndexList selectedIndexes = moviesListWidget->selectionModel()->selectedIndexes();
    if(selectedIndexes.empty()){
        titleEditWidget->clear();
        genreEditWidget->clear();
        yearEditWidget->clear();
        likesEditWidget->clear();
        trailerEditWidget->clear();
    }
    else{
        int selectedIndex = selectedIndexes.at(0).row();
        Movie selectedMovie = controller.getAllMovies()[selectedIndex];
        titleEditWidget->setText(QString::fromStdString(selectedMovie.getTitle()));
        genreEditWidget->setText(QString::fromStdString(selectedMovie.getGenre()));
        yearEditWidget->setText(QString::fromStdString(std::to_string(selectedMovie.getYear())));
        likesEditWidget->setText(QString::fromStdString(std::to_string(selectedMovie.getLikes())));
        trailerEditWidget->setText(QString::fromStdString(selectedMovie.getTrailer()));
    }
}

void GUI::addMovieButton() {
    std::string title = titleEditWidget->text().toStdString();
    std::string genre = genreEditWidget->text().toStdString();
    std::string year = yearEditWidget->text().toStdString();
    std::string likes = likesEditWidget->text().toStdString();
    std::string trailer = trailerEditWidget->text().toStdString();
    string result = controller.addMovie(title, genre, stoi(year), stoi(likes), trailer);
    if(!result.empty()){
        QMessageBox::critical(this, "Error: ", QString::fromStdString(result));
    }
    else
        populateMovies();
}

void GUI::removeMovieButton() {
    if(moviesListWidget->count() == 0){
        QMessageBox::critical(this, "Error : ", "No more movies");
        return;
    }
    std::string title = titleEditWidget->text().toStdString();
    std::string year = yearEditWidget->text().toStdString();
    string result = controller.removeMovie(title, stoi(year));
    if(!result.empty()){
        QMessageBox::critical(this, "Error: ", QString::fromStdString(result));
    }
    else
        populateMovies();
}

void GUI::updateMovieButton() {
    if(moviesListWidget->count() == 0){
        QMessageBox::critical(this, "Error : ", "No more movies");
        return;
    }
    string newGenre = genreEditWidget->text().toStdString();
    string newLikes = likesEditWidget->text().toStdString();
    std::string newTrailer = trailerEditWidget->text().toStdString();
    std::string title = titleEditWidget->text().toStdString();
    std::string year = yearEditWidget->text().toStdString();
    string result = this->controller.updateMovie(title, stoi(year), newGenre, stoi(newLikes), newTrailer);
    if(!result.empty()){
        QMessageBox::critical(this, "Error: ", QString::fromStdString(result));
    }
    else
        populateMovies();
}

void GUI::exitProgramButton() {
    QApplication::quit();
}


QListWidgetItem *GUI::getSelectedItem(int index) {
    return moviesListWidget->selectedItems()[index];
}

void GUI::userGUI() {
    userWidget = new QWidget();
    userWidget->show();
    userWidget->setWindowTitle("USER");
    hide();
    controller.readFromFile();
    watchlist = controller.getWatchlist();
    auto* layout = new QVBoxLayout(userWidget);
    auto* genreSelectionWidget = new QWidget();
    auto* genreSelectionLayout = new QHBoxLayout(genreSelectionWidget);
    auto* genreSelectionLabel = new QLabel("Select Genre: ");
    genreComboBox = new QComboBox(this);
    genreComboBox->addItem("All");
    genreComboBox->addItem("Action");
    genreComboBox->addItem("Drama");
    genreComboBox->addItem("Biography");
    genreSelectionLayout->addWidget(genreSelectionLabel);
    genreSelectionLayout->addWidget(genreComboBox);
    layout->addWidget(genreSelectionWidget);
    auto* watchlistSide = new QWidget();
    auto* watchlistLayout = new QHBoxLayout(watchlistSide);
    auto* watchlistLabel = new QLabel("WATCHLIST");
    QFont font("Raleway", 18);
    watchlistLabel->setAlignment(Qt::AlignCenter);
    watchlistLabel->setFont(font);
    watchlistLayout->addWidget(watchlistLabel);
    watchlistWidget = new QListWidget();
    watchlistWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    watchlistLayout->addWidget(watchlistWidget);
    auto* movieDatabaseSide = new QWidget();
    auto* movieDatabaseLayout = new QVBoxLayout(movieDatabaseSide);
    auto* movieDatabaseLabel = new QLabel("MOVIE DATABASE");
    movieDatabaseLabel->setAlignment(Qt::AlignHCenter);
    movieDatabaseLabel->setFont(font);
    movieDatabaseLayout->addWidget(movieDatabaseLabel);
    auto* movieDatabaseWidget = new QWidget();
    auto* formLayout = new QFormLayout(movieDatabaseWidget);
    auto* titleLabel = new QLabel("TITLE: ");
    titleLabelInfo = new QLabel("-");
    titleLabel->setFont(font);
    titleLabelInfo->setFont(font);
    titleLabelInfo->setAlignment(Qt::AlignHCenter);
    auto* genreLabel = new QLabel("GENRE: ");
    genreLabelInfo = new QLabel("-");
    genreLabel->setFont(font);
    genreLabelInfo->setFont(font);
    genreLabelInfo->setAlignment(Qt::AlignHCenter);
    auto* yearLabel = new QLabel("YEAR: ");
    yearLabelInfo = new QLabel("-");
    yearLabel->setFont(font);
    yearLabelInfo->setFont(font);
    yearLabelInfo->setAlignment(Qt::AlignHCenter);
    auto* likesLabel = new QLabel("LIKES:");
    likesLabelInfo = new QLabel("-");
    likesLabel->setFont(font);
    likesLabelInfo->setFont(font);
    likesLabelInfo->setAlignment(Qt::AlignHCenter);
    auto* trailerLabel = new QLabel("TRAILER");
    trailerLabelInfo = new QLabel("-");
    trailerLabel->setFont(font);
    trailerLabelInfo->setFont(font);
    trailerLabelInfo->setAlignment(Qt::AlignHCenter);
    formLayout->addRow(titleLabel, this->titleLabelInfo);
    formLayout->addRow(genreLabel, this->genreLabelInfo);
    formLayout->addRow(yearLabel, this->yearLabelInfo);
    formLayout->addRow(likesLabel, this->likesLabelInfo);
    formLayout->addRow(trailerLabel, this->trailerLabelInfo);
    movieDatabaseLayout->addWidget(movieDatabaseWidget);
    auto* buttonsWidget = new QWidget();
    auto* hLayout = new QGridLayout(buttonsWidget);
    auto* addToWatchlistButton = new QPushButton("ADD");
    addToWatchlistButton->setFont(font);
    auto* nextButton = new QPushButton("NEXT");
    nextButton->setFont(font);
    auto* removeFromWatchlistButton = new QPushButton("REMOVE");
    removeFromWatchlistButton->setFont(font);
    exitButton = new QPushButton("EXIT");
    exitButton->setFont(font);
    auto* saveAndOpenButton = new QPushButton("Save and open file: ");
    saveAndOpenButton->setFont(font);
    hLayout->addWidget(addToWatchlistButton, 0, 0);
    hLayout->addWidget(nextButton, 0, 1);
    hLayout->addWidget(removeFromWatchlistButton, 0, 2);
    hLayout->addWidget(saveAndOpenButton, 0, 3);
    hLayout->addWidget(exitButton, 1, 2);
    movieDatabaseLayout->addWidget(buttonsWidget);
    layout->addWidget(watchlistSide);
    layout->addWidget(movieDatabaseSide);
    populateWatchlist();
    QObject::connect(nextButton, &QPushButton::clicked, this, &GUI::userNextMovie);
    QObject::connect(addToWatchlistButton, &QPushButton::clicked, this, &GUI::userAddToWatchlist);
    QObject::connect(removeFromWatchlistButton, &QPushButton::clicked, this, &GUI::userRemoveFromWatchlist);
    QObject::connect(saveAndOpenButton, &QPushButton::clicked, this, &GUI::saveAndOpenWatchlist);
    QObject::connect(exitButton, &QPushButton::clicked, this, &GUI::exitProgramButton);
}

void GUI::userShowMovie(int currentIndex) {
    std::string selectedGenre = genreComboBox->currentText().toStdString();
    DynamicVector<Movie> movies;
    if(selectedGenre == "All")
        movies = controller.getAllMovies();
    else
        movies = controller.getMoviesByGenre(selectedGenre);
    if(movies.getLength() == 0){
        //QMessageBox::critical(this, "Error", QString::fromStdString("No more movies"));
        titleLabelInfo->setText(QString::fromStdString("-"));
        genreLabelInfo->setText(QString::fromStdString("-"));
        yearLabelInfo->setText(QString::fromStdString("-"));
        likesLabelInfo->setText(QString::fromStdString("-"));
        trailerLabelInfo->setText(QString::fromStdString("-"));
        return;
    }
    if(currentIndex >= movies.getLength())
        currentIndex = 0;
    Movie movie = controller.getMovieAtIndex(currentIndex, movies);
    titleLabelInfo->setText(QString::fromStdString(movie.getTitle()));
    genreLabelInfo->setText(QString::fromStdString(movie.getGenre()));
    yearLabelInfo->setText(QString::fromStdString(std::to_string(movie.getYear())));
    likesLabelInfo->setText(QString::fromStdString(std::to_string(movie.getLikes())));
    trailerLabelInfo->setText(QString::fromStdString(movie.getTrailer()));
    string command_trailer = "open " + movie.getTrailer();
    system(command_trailer.c_str());
}

void GUI::userNextMovie() {
    std::string selectedGenre = genreComboBox->currentText().toStdString();
    cout<<"SELECTED GENRE: "<<selectedGenre<<endl;
    DynamicVector<Movie> movies;
    if(selectedGenre == "All")
        movies = controller.getAllMovies();
    else{
        movies = controller.getMoviesByGenre(selectedGenre);
        cout<<"Got movies by selected genre"<<endl;}
    if(movies.getLength() == 0){
        QMessageBox::critical(this, "Error", QString::fromStdString("No more movies in databse"));
        titleLabelInfo->setText(QString::fromStdString("-"));
        genreLabelInfo->setText(QString::fromStdString("-"));
        yearLabelInfo->setText(QString::fromStdString("-"));
        likesLabelInfo->setText(QString::fromStdString("-"));
        trailerLabelInfo->setText(QString::fromStdString("-"));
        return;
    }
    controller.nextMovie();
    int currentIndex = controller.getCurrentIndex();
    cout<<"Index: "<<currentIndex<<endl;
    Movie movie = controller.getMovieAtIndex(currentIndex, movies);
    cout<<"got movie:" << movie.getTitle()<<endl;
    userShowMovie(currentIndex);
}

void GUI::userAddToWatchlist() {
    std::string selectedGenre = genreComboBox->currentText().toStdString();
    DynamicVector<Movie> movies;
    if(selectedGenre == "All"){
        movies = controller.getAllMovies();
        }
    else {
        movies = controller.getMoviesByGenre(selectedGenre);
    }
    if(movies.getLength() == 0){
        QMessageBox::critical(this, "Error", QString::fromStdString("No more movies"));
        return;
    }
    std::string title = titleLabelInfo->text().toStdString();
    std::string genre = genreLabelInfo->text().toStdString();
    std::string year = yearLabelInfo->text().toStdString();
    std::string likes = likesLabelInfo->text().toStdString();
    std::string trailer = trailerLabelInfo->text().toStdString();
    try{
        controller.addToWatchlist(Movie(title, genre, std::stoi(year), std::stoi(likes), trailer));
        populateWatchlist();
    } catch(const std::exception& e){
        QMessageBox::critical(this, "Error", QString::fromStdString("Movie already in watchlist"));
    }

}

void GUI::userRemoveFromWatchlist() {
    QListWidgetItem* selectedItem = watchlistWidget->currentItem();
    if(!selectedItem){
        QMessageBox::critical(this, "Error", "No movie selected");
        return;
    }
    std::string titleYear = selectedItem->text().toStdString();
    std::string title = titleYear.substr(0, titleYear.find(","));
    std::string year = titleYear.substr(titleYear.find(", ") + 1);
    try{
        controller.removeFromWatchlist(title, std::stoi(year));
        populateWatchlist();
    }catch (const std::exception& e){
        QMessageBox::critical(this, "Error", QString::fromStdString(e.what()));
    }
}

void GUI::saveAndOpenWatchlist() {
    std::string filePath = csvHtmlLineEdit->text().toStdString();
    if(filePath.empty()){
        QMessageBox::critical(this, "Error", "No file entered");
        return;
    }
    std::string extension = filePath.substr(filePath.find_last_of(".") + 1);
    FileWriter* fileWriter;
    if(extension == "csv")
        fileWriter = new CSVWriter();
    else if(extension == "html")
        fileWriter = new HTMLWriter();
    else{
        QMessageBox::critical(this, "Error", "Unsuported file type");
        return;
    }
    DynamicVector<Movie> watchlist = controller.getWatchlist();
    fileWriter->writeToFile(filePath, watchlist);
    fileWriter->displayFile(filePath);
    delete fileWriter;

}



