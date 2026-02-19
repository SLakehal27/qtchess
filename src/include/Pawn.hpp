#pragma once
#include "Piece.hpp"

class Pawn : public Piece {
    Position getPosition() override;
    std::vector<Position> getMovePositions() override;
    std::vector<Position> moveAt(Position position) override;
};