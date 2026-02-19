#pragma once
#include <vector>
#include <QLabel>

struct Chessboard
{
    const long unsigned int SIZE = 8;
    std::vector<std::vector<QLabel*>> board{SIZE, std::vector(SIZE, new QLabel(""))};
};
