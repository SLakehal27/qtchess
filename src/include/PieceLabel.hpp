#pragma once
#include <QLabel>
#include "Piece.hpp"

class PieceLabel : public QLabel {
    public:
        PieceLabel(std::shared_ptr<Piece> piece);
        std::shared_ptr<Piece> piece;
    signals:
        void clicked(std::unique_ptr<PieceLabel> piece);
    protected:
        void mousePressEvent(QMouseEvent* event) override;
};