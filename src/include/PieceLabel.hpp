#pragma once
#include <QLabel>
#include <QMouseEvent>
#include <QString>
#include "Piece.hpp"

class PieceLabel : public QLabel {
    Q_OBJECT
    public:
        PieceLabel(QString str) : QLabel(str) {}
        void setDisplayPiece(std::shared_ptr<Piece> piece);
        template <class T> void promote(std::shared_ptr<Piece> piece);
        std::shared_ptr<Piece> piece;
    signals:
        void clicked(PieceLabel* pieceLabel);
    protected:
        void mousePressEvent(QMouseEvent* event) override;
        std::string getPieceSymbol(std::shared_ptr<Piece> piece);
        void setFontSize(const int font_size);
        void setPieceColor(std::shared_ptr<Piece> piece);
    
};

template <class T>
inline void PieceLabel::promote(std::shared_ptr<Piece> piece)
{
    piece = std::make_shared<T>(piece->position, piece->color);
    setDisplayPiece(piece);
}
