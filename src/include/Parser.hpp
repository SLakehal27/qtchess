#pragma once
#include <fstream>
#include "Chessboard.hpp"
#include "GameManager.hpp"

class Parser {
    public:
        Parser(Chessboard& chessboard) : chessBoard(chessboard) {}
        void parse(std::ifstream& file);
    private:
        void addPiece(Position position, std::string pieceType, PieceColor color);
        template <class T> void addPieceToBoard(Position position, PieceColor color);
        Chessboard& chessBoard;
};

template <class T>
inline void Parser::addPieceToBoard(Position position, PieceColor color)
{
    GameManager* gameManager = GameManager::instance();

    std::shared_ptr<T> piece = std::make_shared<T>(position, color);
    chessBoard.board[position.x][position.y]->setDisplayPiece(piece);
    gameManager->pieceLabels.push_back(chessBoard.board[position.x][position.y]);
}
