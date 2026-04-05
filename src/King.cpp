#include "King.hpp"

std::vector<Position> King::getMoves()
{
    std::vector<Position> moves;

    Position kingMoves[] = {
        {position.x - 1, position.y},
        {position.x + 1, position.y},
        {position.x, position.y - 1},
        {position.x, position.y + 1},
        {position.x - 1, position.y - 1},
        {position.x + 1, position.y + 1},
        {position.x + 1, position.y - 1},
        {position.x - 1, position.y + 1},
    };

    for (Position pos: kingMoves) {
        moves.push_back(pos);
    }

    return moves;
}