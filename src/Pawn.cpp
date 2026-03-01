#include "Pawn.hpp"
#include "Chessboard.hpp"
#include <iostream>
#include "GameManager.hpp"

std::vector<Position> Pawn::getMoves()
{
    std::vector<Position> moves;
    GameManager* gameManager = GameManager::instance();

    switch (this->color)
    {
        case PieceColor::White:
            if(gameManager->isPieceAt({position.x - 1, position.y})) break;

            // Starting move
            if (this->position.x == 6) {
                moves.push_back({position.x - 2, position.y});
            }

            moves.push_back({position.x - 1, position.y});
            
            break;
        case PieceColor::Black:
            if(gameManager->isPieceAt({position.x + 1, position.y})) break;
            
            // Starting move
            if (this->position.x == 1) {
                moves.push_back({position.x + 2, position.y});
            }
            moves.push_back({position.x + 1, position.y});
            break;
    }

    return moves;
}

std::vector<Position> Pawn::moveAt(Position position)
{
    return std::vector<Position>();
}
