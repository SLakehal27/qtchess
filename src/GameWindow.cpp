#include "GameWindow.hpp"
#include "PieceLabel.hpp"
#include "Pawn.hpp"
#include "Parser.hpp"
#include <algorithm>
#include <QAbstractButton>
#include "Knight.hpp"

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

    togglePieceLabels();

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

    gameManager->turnCounter++;
    
    int x, y, rowSpan, colSpan;
    chessBoardLayout->getItemPosition(chessBoardLayout->indexOf(highlightLabel), &x, &y, &rowSpan, &colSpan);

    int pieceLabelIdx = std::find(gameManager->pieceLabels.begin(), gameManager->pieceLabels.end(), 
    gameManager->chessBoard.board[originalPosition.x][originalPosition.y]) - gameManager->pieceLabels.begin();
    
    PieceLabel* originalPieceLabel = gameManager->pieceLabels[pieceLabelIdx];
    PieceLabel* newPieceLabel = gameManager->chessBoard.board[x][y];
    
    // Reset new position
    originalPieceLabel->setText("");
    originalPieceLabel->piece->position = Position{x, y};
    newPieceLabel->setDisplayPiece(originalPieceLabel->piece);
    originalPieceLabel->piece.reset();

    gameManager->pieceLabels[pieceLabelIdx] = newPieceLabel;

    // // Toggles connexions
    togglePieceLabels();

    // Promotion
    if (gameManager->canPromotePiece(newPieceLabel->piece)) {
        proposePromotion(newPieceLabel);
    }
}

void GameWindow::proposePromotion(PieceLabel *pieceLabel)
{
    QMessageBox msgBox(this);
    msgBox.setWindowTitle("Promotion");
    msgBox.setText("<center>Choose a piece to promote your pawn to</center>");
    
    msgBox.addButton("Queen", QMessageBox::ActionRole);
    msgBox.addButton("Knight", QMessageBox::ActionRole);
    msgBox.addButton("Rook", QMessageBox::ActionRole);
    msgBox.addButton("Bishop", QMessageBox::ActionRole);
    msgBox.exec();

    QAbstractButton* clickedButton = msgBox.clickedButton();
    
    if(clickedButton == nullptr) return;

    if(clickedButton->text().toStdString() == "Knight") {
        pieceLabel->piece = std::make_shared<Knight>(pieceLabel->piece->position, pieceLabel->piece->color);
        pieceLabel->setDisplayPiece(pieceLabel->piece);
    }
    
}

void GameWindow::clearHighlights() {
    if(highlightLabels.size() == 0) return;

    for (auto& highlightLabel : highlightLabels) {
        highlightLabel->deleteLater();
    }
    
    highlightLabels.clear();
}

void GameWindow::togglePieceLabels()
{
    PieceColor colorToDisable = (gameManager->turnCounter % 2 == 0) ? PieceColor::Black : PieceColor::White;

    for(PieceLabel* pieceLabel: gameManager->pieceLabels) {

        if(pieceLabel->piece != nullptr && pieceLabel->piece->color != colorToDisable) {
            connect(pieceLabel, SIGNAL(clicked(PieceLabel*)), this, SLOT(displayPieceMoves(PieceLabel*)));
            continue;
        }

        disconnect(pieceLabel, nullptr, nullptr, nullptr);

    }
}
