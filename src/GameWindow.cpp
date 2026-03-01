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
    this->createChessBoard(gameManager->chessBoard);

    Parser parser(gameManager->chessBoard);
    std::ifstream file("default.txt");
    parser.parse(file);
}

void GameWindow::createChessBoard(Chessboard& chessBoard) {
    for (int i = 0; i < chessBoard.SIZE; i++) {
        for (int j = 0; j < chessBoard.SIZE; j++) {
            chessBoard.board[i][j] = new PieceLabel("");
            chessBoard.board[i][j]->setAlignment(Qt::AlignCenter);
            if ((i + j) % 2 == 0) {
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

    clearHighlights();
    
    if(pieceLabel->piece == nullptr) return;

    std::vector<Position> validMoves = pieceLabel->piece->getValidMoves();
    if(validMoves.size() == 0) return;

    for(int i = 0; i < validMoves.size(); i++) {
        highlightLabels.push_back(new HighlightLabel());
        chessBoardLayout->addWidget(highlightLabels[i], validMoves[i].x, validMoves[i].y);
        highlightLabels[i]->originalPosition = pieceLabel->piece->position;
        connect(highlightLabels[i], SIGNAL(clicked(HighlightLabel*, Position)), this, SLOT(displayMove(HighlightLabel*, Position)));
    }
}

void GameWindow::displayMove(HighlightLabel* highlightLabel, Position originalPosition)
{
    clearHighlights();

    int x, y, rowSpan, colSpan;
    chessBoardLayout->getItemPosition(chessBoardLayout->indexOf(highlightLabel), &x, &y, &rowSpan, &colSpan);

    PieceLabel* pieceLabel = gameManager->chessBoard.board[originalPosition.x][originalPosition.y];

    pieceLabel->setText("");
    disconnect(pieceLabel, nullptr, nullptr, nullptr);

    pieceLabel->piece->position = Position{x, y};
    gameManager->chessBoard.board[x][y]->setDisplayPiece(pieceLabel->piece);
    connect(gameManager->chessBoard.board[x][y], SIGNAL(clicked(PieceLabel*)), this, SLOT(displayPieceMoves(PieceLabel*)));
    pieceLabel->piece.reset();
} 

void GameWindow::clearHighlights() {
    if(highlightLabels.size() == 0) return;

    for (auto& highlightLabel : highlightLabels) {
        highlightLabel->deleteLater();
    }
    
    highlightLabels.clear();
}
