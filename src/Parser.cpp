#include "Parser.hpp"
#include <string>
#include <limits>
#include <iostream>
#include "GameManager.hpp"
#include "Pawn.hpp"
#include "Knight.hpp"
#include "Bishop.hpp"

// Test: Adding Pawn to the board.
// Position testPosition{6,2};


void Parser::parse(std::ifstream& file)
{
    std::string line;
    std::string type = "";
    Position position;
    std::string color = "";

    if (!file.is_open()) {
        std::cout << "Could not open game mode file" << std::endl;
        return;
    }

    while(std::getline(file, line)) {
        file >> type;
        file >> position.x;
        file >> position.y;
        file >> color;
        addPieceToBoard(position, type, (color == "b" ? PieceColor::Black : PieceColor::White));
    }

    file.close();
}

void Parser::addPieceToBoard(Position position, std::string pieceType, PieceColor color)
{
    GameManager* gameManager = GameManager::instance();

    if(pieceType == "pawn") {
        std::shared_ptr<Pawn> pawn = std::make_shared<Pawn>(position, color);
        chessBoard.board[position.x][position.y]->setDisplayPiece(pawn);
        gameManager->pieceLabels.push_back(chessBoard.board[position.x][position.y]);
    }

    if(pieceType == "knight") {
        std::shared_ptr<Knight> knight = std::make_shared<Knight>(position, color);
        chessBoard.board[position.x][position.y]->setDisplayPiece(knight);
        gameManager->pieceLabels.push_back(chessBoard.board[position.x][position.y]);
    }

    if(pieceType == "bishop") {
        std::shared_ptr<Bishop> bishop = std::make_shared<Bishop>(position, color);
        chessBoard.board[position.x][position.y]->setDisplayPiece(bishop);
        gameManager->pieceLabels.push_back(chessBoard.board[position.x][position.y]);
    }


}
