#pragma once
#include "Piece.hpp"
#include <memory>

class King : public Piece {
    public:
        King(Position position, PieceColor color) : Piece(position, color) {}
    protected:
        std::vector<Position> getMoves() override;
};