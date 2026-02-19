#include "./include/GameWindow.hpp"
#include "./include/PieceLabel.hpp"
#include "./include/Pawn.hpp"

GameWindow::GameWindow() {
    QWidget* mainWidget = new QWidget;
    setCentralWidget(mainWidget);

    chessBoardLayout->setRowMinimumHeight(2,2);
    chessBoardLayout->setContentsMargins(0,0,0,0);
    chessBoardLayout->setSpacing(0);

    setFixedSize(QSize(600, 600));
    setWindowTitle("QtChess");

    mainWidget->setLayout(chessBoardLayout);

    this->createChessBoard();

}

void GameWindow::createChessBoard() {
    for (int i = 0; i < chessBoard.SIZE; i++) {
        for (int j = 0; j < chessBoard.SIZE; j++) {
            chessBoard.board[i][j] = new QLabel("");
            chessBoard.board[i][j]->setAlignment(Qt::AlignCenter);
            if ((i+j) % 2 == 0) {
                chessBoard.board[i][j]->setStyleSheet("background-color : #D7BEA8");
            }
            else {
                chessBoard.board[i][j]->setStyleSheet("background-color : #B49286");
            }
            chessBoardLayout->addWidget(chessBoard.board[i][j], i, j);
        }
    }
    
    // Test: Adding Pawn to the board.
    // Position testPosition{6,2};
    // std::shared_ptr<Pawn> pawn = std::make_shared<Pawn>(testPosition, PieceColor::White);
    // chessBoardLayout->addWidget(new PieceLabel(pawn), testPosition.x, testPosition.y);
}

