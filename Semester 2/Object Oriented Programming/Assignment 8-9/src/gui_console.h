#include "controller.h"
#include <qwidget.h>
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QApplication>
#include <QMessageBox>
#include <QComboBox>

class GUI : public QWidget{
private:
    Controller controller;
    QListWidget* moviesListWidget{};
    QListWidget* watchlistWidget{};
    QWidget* adminWidget{};
    QWidget* userWidget{};
    QLineEdit* titleEditWidget{};
    QLineEdit* genreEditWidget{};
    QLineEdit* yearEditWidget{};
    QLineEdit* likesEditWidget{};
    QLineEdit* trailerEditWidget{};
    QLabel* titleLabelInfo{};
    QLabel* genreLabelInfo{};
    QLabel* yearLabelInfo{};
    QLabel* likesLabelInfo{};
    QLabel* trailerLabelInfo{};
    QTextEdit* moviesLinkEdit{};
    QPushButton* addButton, *removeButton, *updateButton;
    QPushButton* adminButton, *userButton;
    QPushButton* exitButton;
    DynamicVector<Movie> watchlist;
    std::vector<Movie>::iterator it;
    std::string type;
    QComboBox* genreComboBox;
    QLineEdit* csvHtmlLineEdit;

    void adminGUI();
    void userGUI();
    void addMovieButton();
    void removeMovieButton();
    void updateMovieButton();
    void exitProgramButton();
    int getSelectedIndex();
    QListWidgetItem* getSelectedItem(int index);
    void listItemChange();
    void userAddToWatchlist();
    void userNextMovie();
    void userRemoveFromWatchlist();
    void saveAndOpenWatchlist();
    void goBackToMain();

public:
    GUI(Controller controller, QWidget* parent = nullptr);
    ~GUI() = default;
    void initGUI();
    void populateMovies();
    void addMovieSignal(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&);
    void populateWatchlist();
    void userShowMovie(int currentIndex);

};

