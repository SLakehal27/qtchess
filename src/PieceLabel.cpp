#include "Pawn.hpp"
#include "PieceLabel.hpp"
#include "PieceColor.hpp"
#include "GameManager.hpp"
#include "Knight.hpp"
#include "Bishop.hpp"
#include "Rook.hpp"

void PieceLabel::setDisplayPiece(std::shared_ptr<Piece> piece)
{
    if (piece == nullptr) return;
    setText(QString::fromStdString(getPieceSymbol(piece)));
    setAlignment(Qt::AlignCenter);
    this->setFontSize(48);
    this->setPieceColor(piece);
    this->piece = piece;
}

void PieceLabel::mousePressEvent(QMouseEvent *event)
{
    if (event->button() != Qt::LeftButton) return;
    emit clicked(this);
}

std::string PieceLabel::getPieceSymbol(std::shared_ptr<Piece> piece)
{
    if (auto pawn = std::dynamic_pointer_cast<Pawn>(piece)) return "\u265f";
    if (auto knight = std::dynamic_pointer_cast<Knight>(piece)) return "\u265e";
    if (auto bishop = std::dynamic_pointer_cast<Bishop>(piece)) return "\u265d";
    if (auto rook = std::dynamic_pointer_cast<Rook>(piece)) return "\u265c";
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