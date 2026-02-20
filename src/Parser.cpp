#include "Parser.hpp"
#include <string>
#include <iostream>
#include <limits>
#include "Pawn.hpp"

// Test: Adding Pawn to the board.
// Position testPosition{6,2};


void Parser::parse(std::ifstream& file)
{
    std::string str;
    std::string type = "";
    Position position;
    std::string color = "";

    while(std::getline(file, str)) {
        std::cout << str << std::endl;
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
        chessBoard->board[position.x][position.y]->setDisplayPiece(pawn);
    }
}
