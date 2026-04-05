#include "GameManager.hpp"
#include "Pawn.hpp"
#include <iostream>

GameManager *GameManager::instance()
{
    static GameManager gameManager;
	return &gameManager;
}

bool GameManager::isPieceAt(Position position)
{
    if (!position.isLegal()) return false;
    return chessBoard.board[position.x][position.y]->text() != "";
}

bool GameManager::isSameColorAt(Position position, PieceColor color)
{
    std::shared_ptr<Piece> otherPiece = chessBoard.board[position.x][position.y]->piece;
    if(otherPiece == nullptr) return false;
    return otherPiece->color == color;
}

bool GameManager::isPieceInBetweenMoves(std::vector<Position>& moves, Position position, PieceColor color)
{
    if(!isPieceAt(position)) return false;
    if(isSameColorAt(position, color)) return true;
    moves.push_back(position);
    return true;
}

bool GameManager::canPromotePiece(std::shared_ptr<Piece> piece)
{
    if(piece == nullptr || (std::dynamic_pointer_cast<Pawn>(piece) == nullptr) ) return false;
    if(piece->color == PieceColor::White) return piece->position.x == 0;
    return piece->position.x == 7;
}
