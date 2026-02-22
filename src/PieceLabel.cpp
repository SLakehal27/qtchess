#include "PieceLabel.hpp"
#include "Pawn.hpp"
#include "PieceColor.hpp"
#include "PieceLabel.hpp"
#include <iostream>

void PieceLabel::setDisplayPiece(std::shared_ptr<Piece> piece)
{
    if (piece == nullptr) return;
    setText(QString::fromStdString(getPieceSymbol(piece)));
    // std::cout << getPieceSymbol(piece) << std::endl;
    setAlignment(Qt::AlignCenter);
    this->setFontSize(48);
    this->setPieceColor(piece);
}

void PieceLabel::mousePressEvent(QMouseEvent *event)
{
    // TODO: Add logic to override this.
    // if (event->button() == Qt::LeftButton) {
    //     emit clicked(this);
    // }
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
    if (piece->color == PieceColor::Black) return;
    std::string backgroundColor = ((piece->position.x + piece->position.y) % 2 == 0) ? "#D7BEA8" : "#B49286";
    setStyleSheet(QString::fromStdString("QLabel {font-size: 48px; color: white; background-color: " + backgroundColor + "}"));
}