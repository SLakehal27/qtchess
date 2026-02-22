#pragma once
#include <vector>
#include "Position.hpp"
#include "PieceColor.hpp"

class Piece {
    public: 
        PieceColor color;
        Position position;

        Piece(Position position, PieceColor color) {
            this->position = position;
            this->color = color;
        }
        
    protected:
        virtual ~Piece() = default;
        virtual std::vector<Position> getMovePositions() = 0;
        virtual std::vector<Position> moveAt(Position position) = 0;
};