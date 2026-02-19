#pragma once
#include <vector>
#include "Position.hpp"
#include "PieceColor.hpp"
#include "MoveValidator.hpp"

class Piece {
    protected:
        virtual ~Piece() = default;
        virtual Position getPosition() = 0;
        virtual std::vector<Position> getMovePositions() = 0;
        virtual std::vector<Position> moveAt(Position position) = 0;
        Position position;
        PieceColor color;
        MoveValidator validator;
};