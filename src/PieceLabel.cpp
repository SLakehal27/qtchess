#include "Pawn.hpp"
#include "PieceLabel.hpp"
#include "PieceColor.hpp"
#include "GameManager.hpp"

void PieceLabel::setDisplayPiece(std::shared_ptr<Piece> piece)
{
    if (piece == nullptr) return;
    setText(QString::fromStdString(getPieceSymbol(piece)));
    setAlignment(Qt::AlignCenter);
    this->setFontSize(48);
    this->setPieceColor(piece);
    this->piece = piece;
}

// void PieceLabel::setBackgroundColor(Position position)
// {
//     GameManager* gameManager = GameManager::instance();
//     if ((position.x + position.y) % 2 == 0) {
//         gameManager->chessBoard.board[position.x][position.y]->setStyleSheet("background-color : #D7BEA8");
//     } else {
//         gameManager->chessBoard.board[position.x][position.y]->setStyleSheet("background-color : #B49286");
//     }
// }

void PieceLabel::mousePressEvent(QMouseEvent *event)
{
    if (event->button() != Qt::LeftButton) return;
    emit clicked(this);
}

std::string PieceLabel::getPieceSymbol(std::shared_ptr<Piece> piece)
{
    if (auto pawn = std::dynamic_pointer_cast<Pawn>(piece)) return "\u265f";
    return std::string();
}

void PieceLabel::setFontSize(const int font_size)
{
    QFont pieceFont = font();
    pieceFont.setPointSize(font_size);
    setFont(pieceFont);
}

void PieceLabel::setPieceColor(std::shared_ptr<Piece> piece) {
    std::string backgroundColor = ((piece->position.x + piece->position.y) % 2 == 0) ? "#D7BEA8" : "#B49286";
    if (piece->color == PieceColor::Black)  {
        setStyleSheet(QString::fromStdString("QLabel {font-size: 48px; color: black; background-color: " + backgroundColor + "}"));
        return;
    }
    setStyleSheet(QString::fromStdString("QLabel {font-size: 48px; color: white; background-color: " + backgroundColor + "}"));
}