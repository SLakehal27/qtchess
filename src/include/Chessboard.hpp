#pragma once
#include <vector>
#include <QLabel>
#include "PieceLabel.hpp"

struct Chessboard
{
    const long unsigned int SIZE = 8;
    std::vector<std::vector<PieceLabel*>> board{SIZE, std::vector(SIZE, new PieceLabel("")) };
};
