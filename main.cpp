#include <stdio.h>
#include <iostream>
#include <QtWidgets>

void createChessBoard (QGridLayout* layout, int maxSize = 8) {
    std::vector<QLabel*> chessSquares(maxSize * maxSize);

    for (int i = 0; i < maxSize; i++) {
        for (int j = 0; j < maxSize; j++) {
            chessSquares[i] = new QLabel("");
            if ((i+j)% 2 == 0) {
                chessSquares[i]->setStyleSheet("background-color : #D7BEA8");
            }
            else {
                chessSquares[i]->setStyleSheet("background-color : #B49286");
            }
            layout->addWidget(chessSquares[i], i, j);
        }
    }
}

int main (int argc, char** argv) {
    QApplication app(argc, argv);
    QWidget window;
    window.setFixedSize(QSize(600, 600));
    window.show();
    window.setWindowTitle("QtChess");


    QGridLayout* chessBoardLayout = new QGridLayout();

    chessBoardLayout->setRowMinimumHeight(2,2);

    window.setLayout(chessBoardLayout);
    
    chessBoardLayout->setContentsMargins(0,0,0,0);
    chessBoardLayout->setSpacing(0);
    
    createChessBoard(chessBoardLayout);

    return app.exec();
}
 
