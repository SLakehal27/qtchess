#include "Queen.hpp"
#include "GameManager.hpp"

std::vector<Position> Queen::getMoves()
{
    std::vector<Position> moves;
    addBishopMoves(moves);
    addRookMoves(moves);
    return moves;
}

void Queen::addBishopMoves(std::vector<Position> &moves)
{
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
}

void Queen::addRookMoves(std::vector<Position> &moves)
{
    GameManager* gameManager = GameManager::instance();
    int boardSize = gameManager->chessBoard.SIZE;

    for(int i = position.y - 1; i >= 0; i--) {
        if(gameManager->isPieceInBetweenMoves(moves, {position.x, i}, color)) break;
        moves.push_back({position.x, i});
    }

    for(int i = position.y + 1; i < boardSize; i++) {
        if(gameManager->isPieceInBetweenMoves(moves, {position.x, i}, color)) break;
        moves.push_back({position.x, i});
    }

    
    for(int i = position.x - 1; i >= 0; i--) {
        if(gameManager->isPieceInBetweenMoves(moves, {i, position.y}, color)) break;
        moves.push_back({i, position.y});
    }

    
    for(int i = position.x + 1; i < boardSize; i++) {
        if(gameManager->isPieceInBetweenMoves(moves, {i, position.y}, color)) break;
        moves.push_back({i, position.y});
    }

}
