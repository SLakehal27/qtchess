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
        
        virtual ~Piece() = default;
        std::vector<Position> getValidMoves();
        virtual std::vector<Position> moveAt(Position position) = 0;
        
        protected:
            virtual std::vector<Position> getMoves() = 0;
};