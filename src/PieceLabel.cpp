#include "./include/PieceLabel.hpp"
#include "./include/Pawn.hpp"
#include "./include/PieceColor.hpp"

PieceLabel::PieceLabel(std::shared_ptr<Piece> piece) : piece(piece)
{
    setText(QString::fromStdString(getPieceSymbol(piece)));
    setAlignment(Qt::AlignCenter);
    if(piece->color == PieceColor::White) {
        setStyleSheet("QLabel {font-size: 48px; color: white;}");
    } else {
        setStyleSheet("QLabel {font-size: 48px; color: black;}");
    }
}

void PieceLabel::mousePressEvent(QMouseEvent *event)
{
    // TODO: Add logic to override this.
}

std::string PieceLabel::getPieceSymbol(std::shared_ptr<Piece> piece)
{
    if (piece == nullptr) return "\u2440";
    if (auto pawn = std::dynamic_pointer_cast<Pawn>(piece)) return "\u2659";
    return std::string();
}
