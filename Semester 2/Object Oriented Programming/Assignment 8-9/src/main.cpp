#include <iostream>
#include <QApplication>
#include "gui_console.h"

using namespace std;

int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    Repository repo;
    Watchlist watchlist;
    Controller controller{repo, watchlist};
    GUI gui{controller};
    gui.show();
    return app.exec();
}