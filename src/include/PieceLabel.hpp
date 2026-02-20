#pragma once
#include <QLabel>
#include <QMouseEvent>
#include <QString>
#include "Piece.hpp"

class PieceLabel : public QLabel {
    public:
        PieceLabel(QString str) : QLabel(str) {}
        void setDisplayPiece(std::shared_ptr<Piece> piece);
    signals:
        void clicked(PieceLabel* pieceLabel);
    protected:
        void mousePressEvent(QMouseEvent* event) override;
        std::string getPieceSymbol(std::shared_ptr<Piece> piece);
        void setFontSize(const int font_size);
        void setPieceColor(std::shared_ptr<Piece> piece);

    private:
        std::shared_ptr<Piece> piece;
};