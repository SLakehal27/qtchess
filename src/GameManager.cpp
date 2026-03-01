#include "GameManager.hpp"

GameManager *GameManager::instance()
{
    static GameManager gameManager;
	return &gameManager;
}

bool GameManager::isPieceAt(Position position)
{
    if (!position.isLegal() || chessBoard.board[position.x][position.y] == nullptr) return false;
    return chessBoard.board[position.x][position.y]->text() != "";
}
