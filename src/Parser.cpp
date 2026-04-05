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
        addPiece(position, type, (color == "b" ? PieceColor::Black : PieceColor::White));
    }

    file.close();
}

void Parser::addPiece(Position position, std::string pieceType, PieceColor color)
{
    if(pieceType == "pawn") {
        addPieceToBoard<Pawn>(position, color);
    } else if(pieceType == "knight") {
        addPieceToBoard<Knight>(position, color);
    } else if(pieceType == "bishop") {
        addPieceToBoard<Bishop>(position, color);
    }
}
