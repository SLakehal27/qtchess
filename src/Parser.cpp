#include "Parser.hpp"
#include <string>
#include <limits>
#include <iostream>
#include "Pawn.hpp"

// Test: Adding Pawn to the board.
// Position testPosition{6,2};


void Parser::parse(std::ifstream& file)
{
    std::string str;
    std::string type = "";
    Position position;
    std::string color = "";

    if (!file.is_open()) {
        std::cout << "Could not open game mode file" << std::endl;
        return;
    }

    while(std::getline(file, str)) {
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
    if(pieceType == "pawn") {
        std::shared_ptr<Pawn> pawn = std::make_shared<Pawn>(position, color);
        chessBoard.board[position.x][position.y]->setDisplayPiece(pawn);
    }
}
