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
        
            // Starting move
            if (this->position.x == 6 && !gameManager->isPieceAt({position.x - 2, position.y})) {
                moves.push_back({position.x - 2, position.y});
            }

            // Attack (left)
            if(gameManager->isPieceAt({position.x - 1, position.y - 1})) {
                moves.push_back({position.x - 1, position.y - 1});
            }

            // Attack (Right)
            if(gameManager->isPieceAt({position.x - 1, position.y + 1})) {
                moves.push_back({position.x - 1, position.y + 1});
            }

            // Piece in front of pawn
            if(gameManager->isPieceAt({position.x - 1, position.y})) break;

            // Regular move
            moves.push_back({position.x - 1, position.y});
            break;
        case PieceColor::Black:

            // Starting move
            if (this->position.x == 1 && !gameManager->isPieceAt({position.x + 2, position.y})) {
                moves.push_back({position.x + 2, position.y});
            }

            // Attack (left)
            if(gameManager->isPieceAt({position.x + 1, position.y - 1})) {
                moves.push_back({position.x + 1, position.y - 1});
            }

            // Attack (Right)
            if(gameManager->isPieceAt({position.x + 1, position.y + 1})) {
                moves.push_back({position.x + 1, position.y + 1});
            }

            // Piece in front of pawn
            if(gameManager->isPieceAt({position.x + 1, position.y})) break;

            // Regular move
            moves.push_back({position.x + 1, position.y});

            break;
    }

    return moves;
}
