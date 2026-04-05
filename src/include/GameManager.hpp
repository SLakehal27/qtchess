#pragma once
#include "Chessboard.hpp"
#include <memory>
#include "Piece.hpp"

class GameManager {
    public:
        static GameManager* instance();
        bool isPieceAt(Position position);
        bool isSameColorAt(Position position, PieceColor color);
        bool canPromotePiece(std::shared_ptr<Piece> piece);
        bool isPieceInBetweenMoves(std::vector<Position>& moves, Position position, PieceColor color);

        Chessboard chessBoard;
        std::vector<PieceLabel*> pieceLabels;
        int turnCounter;
};