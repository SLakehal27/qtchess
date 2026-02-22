#pragma once
#include "Position.hpp"
#include "PieceColor.hpp"
#include "Chessboard.hpp"

class MoveValidator {
    public:
        bool isInBoard(Position position);
        void validateMove(std::vector<Position>& positions, PieceColor color);
    private:
        Chessboard chessboard;
};