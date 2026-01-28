#include "GameWindow.hpp"

void GameWindow::createChessBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            chessSquares[i][j] = new QLabel("");
            if ((i+j) % 2 == 0) {
                chessSquares[i][j]->setStyleSheet("background-color : #D7BEA8");
            }
            else {
                chessSquares[i][j]->setStyleSheet("background-color : #B49286");
            }
            chessSquares[i][j]->setAlignment(Qt::AlignCenter);
            chessBoardLayout->addWidget(chessSquares[i][j], i, j);
        }
    }
}

GameWindow::GameWindow() {
    QWidget* mainWidget = new QWidget;
    setCentralWidget(mainWidget);

    chessBoardLayout->setRowMinimumHeight(2,2);
    chessBoardLayout->setContentsMargins(0,0,0,0);
    chessBoardLayout->setSpacing(0);

    setFixedSize(QSize(600, 600));
    setWindowTitle("QtChess");

    mainWidget->setLayout(chessBoardLayout);

    createChessBoard();
}