#pragma once
#include "Position.hpp"
#include "PieceColor.hpp"
#include "Chessboard.hpp"

class MoveValidator {
    public:
        void validateMove(std::vector<Position>& positions, PieceColor color);
    private:
        Chessboard chessboard;
};