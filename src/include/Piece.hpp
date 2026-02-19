#pragma once
#include <vector>
#include "Position.hpp"

class Piece {
    protected:
        virtual ~Piece() = default;
        virtual std::vector<Position> getPositions() = 0;
        virtual std::vector<Position> moveAt(Position position) = 0;
        Position position;
};