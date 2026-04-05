#pragma once
#include "Piece.hpp"

class Queen : public Piece {
    public:
        Queen(Position position, PieceColor color) : Piece(position, color) {}
    protected:
        std::vector<Position> getMoves() override;
    private:
        void addBishopMoves(std::vector<Position>& moves);
        void addRookMoves(std::vector<Position>& moves);
};