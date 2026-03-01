#include "GameWindow.hpp"
#include "PieceLabel.hpp"
#include "Pawn.hpp"
#include "Parser.hpp"

GameWindow::GameWindow() {
    QWidget* mainWidget = new QWidget;
    setCentralWidget(mainWidget);

    chessBoardLayout->setRowMinimumHeight(2,2);
    chessBoardLayout->setContentsMargins(0,0,0,0);
    chessBoardLayout->setSpacing(0);

    setFixedSize(QSize(600, 600));
    setWindowTitle("QtChess");

    mainWidget->setLayout(chessBoardLayout);

    gameManager = GameManager::instance();

    this->createChessBoard();
    
    Parser parser(gameManager->chessBoard);
    std::ifstream file("default.txt");
    parser.parse(file);
}

void GameWindow::createChessBoard() {
    Chessboard& chessBoard = gameManager->chessBoard;

    for (int i = 0; i < chessBoard.SIZE; i++) {
        for (int j = 0; j < chessBoard.SIZE; j++) {
            chessBoard.board[i][j] = new PieceLabel("");
            chessBoard.board[i][j]->setAlignment(Qt::AlignCenter);
            if ((i+j) % 2 == 0) {
                chessBoard.board[i][j]->setStyleSheet("background-color : #D7BEA8");
            } else {
                chessBoard.board[i][j]->setStyleSheet("background-color : #B49286");
            }
            chessBoardLayout->addWidget(chessBoard.board[i][j], i, j);
            connect(chessBoard.board[i][j], SIGNAL(clicked(PieceLabel*)), this, SLOT(displayPieceMoves(PieceLabel*)));
        }
    }

}

void GameWindow::displayPieceMoves(PieceLabel* pieceLabel) {
    if(pieceLabel->piece == nullptr) return;
    
    std::cout << "pos : " << pieceLabel->piece->position << std::endl;
    
    std::vector<Position> moves = pieceLabel->piece->getValidMoves();

    std::cout << "moves : [";

    if (moves.size() == 0) {
        std:: cout << "]" << std::endl;
    }
    else {
        for(int i = 0; i < moves.size() - 1; i++) {
            std::cout << moves[i] << ", ";
        }
    
        std::cout << moves[moves.size() - 1] << "]" << std::endl;
    }


    std::cout << "color : " << pieceLabel->piece->color << std::endl;
    std::cout << std::endl;
}
