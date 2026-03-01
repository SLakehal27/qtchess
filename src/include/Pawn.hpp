#pragma once
#include "Piece.hpp"

class Pawn : public Piece {
    public:
        Pawn(Position position, PieceColor color) : Piece(position, color) {}
        void moveAt(Position position) override;
    protected:
        std::vector<Position> getMoves() override;
};