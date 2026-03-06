#include "Piece.hpp"
#include "GameManager.hpp"

std::vector<Position> Piece::getValidMoves()
{
    std::vector<Position> moves = this->getMoves();
    std::vector<Position> validMoves;

    GameManager* gameManager = GameManager::instance();

    for (Position position : moves) {
        if(gameManager->isPieceAt(position) && gameManager->isSameColorAt(position, color)) continue;
        if(!position.isLegal()) continue;
        validMoves.push_back(position);
    }

    return validMoves;
}