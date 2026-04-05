#pragma once
#include "Piece.hpp"
#include "GameManager.hpp"

class Bishop : public Piece {
    public:
        Bishop(Position position, PieceColor color) : Piece(position, color) {}
    protected:
        std::vector<Position> getMoves() override;
};