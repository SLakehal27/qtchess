#include "Knight.hpp"
#include <iostream>

std::vector<Position> Knight::getMoves()
{
    std::vector<Position> moves;

    Position knightMoves[] = {
        {position.x - 1, position.y - 2},
        {position.x - 2, position.y - 1},
        {position.x - 2, position.y + 1},
        {position.x - 1, position.y + 2},
        {position.x + 1, position.y - 2},
        {position.x + 2, position.y - 1},
        {position.x + 2, position.y + 1},
        {position.x + 1, position.y + 2}
    };

    for (Position pos: knightMoves) {
        moves.push_back(pos);
    }

    return moves;
}