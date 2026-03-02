#pragma once
#include "Piece.hpp"

class Knight : public Piece {
    public:
        Knight(Position position, PieceColor color) : Piece(position, color) {}
    protected:
        std::vector<Position> getMoves() override;
};