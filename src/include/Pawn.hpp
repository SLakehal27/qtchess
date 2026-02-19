#pragma once
#include "Piece.hpp"

class Pawn : public Piece {
    public:
        Pawn(Position position, PieceColor color) : Piece(position, color) {}
        std::vector<Position> getMovePositions() override;
        std::vector<Position> moveAt(Position position) override;
};