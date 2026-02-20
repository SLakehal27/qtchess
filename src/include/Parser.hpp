#pragma once
#include <fstream>
#include "Chessboard.hpp"

class Parser {
    public:
        Parser(Chessboard* chessboard) : chessBoard(chessboard) {}
        void parse(std::ifstream& file);
    private:
        void addPieceToBoard(Position position, std::string pieceType, PieceColor color);
        Chessboard* chessBoard;
};