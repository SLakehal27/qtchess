#include "Bishop.hpp"

std::vector<Position> Bishop::getMoves()
{
    std::vector<Position> moves;
    GameManager* gameManager = GameManager::instance();
    int boardSize = gameManager->chessBoard.SIZE;

    for(int i = 1; i < boardSize; i++) {
        if(gameManager->isPieceInBetweenMoves(moves, { position.x + i, position.y + i }, color)) break;
        moves.push_back({ position.x + i, position.y + i });
    }

    for(int i = 1; i < boardSize; i++) {
        if(gameManager->isPieceInBetweenMoves(moves, { position.x + i, position.y - i }, color)) break;
        moves.push_back({ position.x + i, position.y - i });
    }
    
    for(int i = 1; i < boardSize; i++) {
        if(gameManager->isPieceInBetweenMoves(moves, { position.x - i, position.y - i }, color)) break;
        moves.push_back({ position.x - i, position.y - i });
    }

    for(int i = 1; i < boardSize; i++) {
        if(gameManager->isPieceInBetweenMoves(moves, { position.x - i, position.y + i }, color)) break;
        moves.push_back({ position.x - i, position.y + i });
    }

    return moves;
}