#include <stdio.h>
#include <QApplication>
#include "GameWindow.hpp"

int main (int argc, char** argv) {
    QApplication app(argc, argv);
    GameWindow gameWindow;
    gameWindow.show();
    return app.exec();
}
 
