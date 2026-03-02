#include "GameManager.hpp"
#include "Pawn.hpp"

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

bool GameManager::canPromotePiece(std::shared_ptr<Piece> piece)
{
    if(piece == nullptr || (std::dynamic_pointer_cast<Pawn>(piece) == nullptr) ) return false;
    if(piece->color == PieceColor::White) return piece->position.x == 0;
    return piece->position.x == 7;
}
