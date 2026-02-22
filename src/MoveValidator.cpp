#include "MoveValidator.hpp"

bool MoveValidator::isInBoard(Position position)
{
    return (position.x >= 0 && position.x < this->chessboard.SIZE)
    && (position.y >=0 && position.y < this->chessboard.SIZE);
}

void MoveValidator::validateMove(std::vector<Position>& positions, PieceColor color)
{
    return;
}
