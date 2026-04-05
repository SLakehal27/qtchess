#pragma once
#include "Piece.hpp"
#include "GameManager.hpp"

class Rook : public Piece {
    public:
        Rook(Position position, PieceColor color) : Piece(position, color) {}
    protected:
        std::vector<Position> getMoves() override;
};