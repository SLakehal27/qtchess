#pragma once
#include "Chessboard.hpp"

class GameManager {
    public:
        static GameManager* instance();
        bool isPieceAt(Position position);
        Chessboard chessBoard;
};