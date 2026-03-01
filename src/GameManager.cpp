#include "GameManager.hpp"

GameManager *GameManager::instance()
{
    static GameManager gameManager;
	return &gameManager;
}

bool GameManager::isPieceAt(Position position)
{
    return chessBoard.board[position.x][position.y]->text() != "";
}
