#include "Piece.hpp"

std::vector<Position> Piece::getValidMoves()
{
    std::vector<Position> moves = this->getMoves();
    std::vector<Position> validMoves;

    for (Position position : moves) {
        if(position.isLegal()) validMoves.push_back(position);
    }

    return validMoves;
}